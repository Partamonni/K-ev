/* K-ev Power-Module script v0.2
 *  
 * Written by Henri Pyoria (henri.pyoria@outlook.com)
 *  
 * Temperature-IC's must be pre-configured for 10-bit resolution (possible atleast on MAX31820)
 * and addresses must be manually defined to tempAdr table. This skips teh lengthy search for 'em.
 * 
 * 2s watchdog implemented after the setups ready, in case of odd failures.
 */

#include <avr/wdt.h>
#include <OneWire.h>

const int FAN_MAX_DUTY_CYCLE = 35; //(12/72)*256 and lowered still a bit for first tests
const int CMD_CHAR_COUNT = 2;
const int OVERCURRENT = 140;
const int OVERVOLTAGE = 85;
const int LOW_VOLTAGE = 58;
const int OVER_HEAT = 60;
const int NL = 1;  // Newline flag for overloaded serialPrint -function
const int HOST_QUERY_TIME = 5000; // ms | Change for real application
const int TMP_COUNT = 21;
const int BYTE = 8;

const bool DEBUG = true; // DO NOT USE THIS ON LIVE SYSTEM!!! IMPERATIVE!!!

OneWire ds(2);

byte  tempAdr[TMP_COUNT][8] =
{ {0x28, 0xBA, 0x4B, 0x41, 0x09, 0x00, 0x00, 0xAE},
  {0x28, 0xEE, 0x46, 0x41, 0x09, 0x00, 0x00, 0xB0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0},
  {0}
};
byte  data[TMP_COUNT][9];

int vsense = A1;
int curSense = A2;
int curSenseRef = A3;
int vref3v3 = A2;
int fanSwitch = 11;
int mosfetSwitch = A4;

double current;
double voltage;
double board5v;
double ms;
double temperature[TMP_COUNT];

String serialInput = "";
bool success = false;
bool setupSuccess = false;
bool criticalCFailure = false;
bool criticalVFailure = false;
bool criticalTFailure = false;
bool lowVoltage = false;
bool hostNotResponding = false;
bool hostShut = false;

void interrupt_setup();
void serialPrint(String);
void serialPrint(String, bool);
void waitFor(String);
String enquire(String);

void setup() 
{
  DDRC |= B00010000; // pinMode(mosfetSwitch, OUTPUT);
  PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW);
  pinMode(fanSwitch, OUTPUT);
  analogWrite(fanSwitch, FAN_MAX_DUTY_CYCLE);
  pinMode(curSense, INPUT);
  pinMode(curSenseRef, INPUT);
  
  Serial.begin(57600);
  Serial.println("Board started");
  serialInput.reserve(64);  // These values are way too unoptimized,
  Serial.setTimeout(200);   // but I don't really care too much for now.

  current = 5*((analogRead(curSense)-analogRead(curSenseRef))/1023)/0.02; 
  // ^ Can measure accuracy to ~0.25A
  if (current > 0.5 || current < -0.5)
  {
    do
    {
      serialPrint("!C", NL); // Board current failure
      delay(1000);
    }
    while(!DEBUG);
  }

  pinMode(vsense, INPUT);
  pinMode(vref3v3, INPUT);
  board5v = 3.3*1023/analogRead(vref3v3); // Function of 5V*((3.3/5)*1023)/vref3v3
  // ^ Returns real voltage referring to internal 3v3 regulator voltage
  // 3v3 output pin shorted to analog input
  voltage = (analogRead(vsense)/1023)*board5v*(537/27);
  // (537/27) is a multiplier to counter voltage divider in the circuit
  if (voltage > OVERVOLTAGE || voltage < LOW_VOLTAGE)
  {
    do
    {
      serialPrint("!V", NL); // Board voltage failure
      delay(1000);
    }
    while(!DEBUG);
  }
  
  interrupt_setup();
  
  if(!ds.reset())
  {
    do
    {
      serialPrint("!T", NL); // Board temperature failure
      delay(1000);
    }
    while(!DEBUG);
  }

  while(enquire("?h") != "ok"){} 

  serialPrint(String(current,1), NL);
  serialPrint(String(voltage,1), NL);


  
  setupSuccess = true;
  wdt_reset();
  wdt_enable(WDTO_2S);
  digitalWrite(mosfetSwitch, HIGH);
}

void loop() 
{
  wdt_reset();

  ds.reset();
  ds.skip();
  ds.write(0x44);
  
  ms = millis();
  while(ms+200 >= millis()) // Do over 200ms if no extra timing is 
  {                         // given for temp sensors to do conversion    
    if(criticalCFailure)
    {
      do
      {
        serialPrint("!C", NL);
        delay(1000);
        wdt_reset();
      }
      while(!DEBUG);
    }
    
    if(criticalVFailure)
    {
      do
      {
        serialPrint("!V", NL);
        delay(1000);
        wdt_reset();
      }
      while(!DEBUG);
    }
    else if(lowVoltage)
    {
      do
      {
        serialPrint("!v", NL);
        delay(1000);
        wdt_reset();
      }
      while(!DEBUG && lowVoltage);
    }

    if(criticalTFailure)
    {
      do
      {
        serialPrint("!T", NL);
        delay(1000);
        wdt_reset();
      }
      while(!DEBUG);
    }
    
    if(hostNotResponding)
    {
      do
      {
        serialPrint("!h", NL);
        delay(1000);
        if(Serial.readStringUntil('\n') == "ok")
        {
          hostNotResponding = false;           
          digitalWrite(mosfetSwitch, HIGH);
          serialPrint("up", NL);
          if(DEBUG)
            serialPrint("Host responded, gates are now open", NL);
        }
        wdt_reset();
      }
      while(hostNotResponding);
    }
    else if(Serial.available())
    {
      if(Serial.readStringUntil('\n') == "!S")
      {
        PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW)
        hostShut = true;
        serialPrint("sh", NL);
        if(DEBUG)
          serialPrint("Gate is now shut", NL);
      } 
    }
  }
  wdt_reset();

  for(int i = 0; i < TMP_COUNT; ++i)
  {
    if(tempAdr[i]) // This checks if entry has any address in it
    {
      ds.reset();
      ds.select(tempAdr[i]);    
      ds.write(0xBE); // Request sensor to read out the scratchpad
      for(int j = 0; i < 9; ++j) // Read all 9 bytes
      {
        data[i][j] = ds.read(); 
      }
      if(OneWire::crc8(data[i], 8) != data[i][8])
      { // If crc is wrong, set all bits to 1
        for(int k = 0; k < 9; ++k)
          data[i][k] = byte(0xFF, HEX);
        if(DEBUG)
          serialPrint("CRC-check failed!", NL);
      }
    }
  }

  int rawTemp;
  for(int i = 0; i < TMP_COUNT; ++i)
  {
      rawTemp = 0;
      rawTemp = (data[i][0] << BYTE) | data[i][1];
      // ^ Reads data to temporary container
      rawTemp &= ~3;
      // ^ Sets last 2 bits to zero,
      // as 10-bit resolution doesn't use them
      temperature[i] = 85.0*(double(rawTemp)/1360.0);

      if(i==0 && temperature[i] >= (OVER_HEAT+60)
        criticalTFailure = true;
      else if(i!=0 && temperature[i] >= OVER_HEAT)
        criticalTFailure = true;
  }
  
  wdt_reset();
  
  success = true;
  if(Serial.readStringUntil('\n') != "ok")
  {
    serialPrint("?h", NL);
    success = false;
  }

  ms = millis();
  while(ms+HOST_QUERY_TIME > millis() && !success)
  {
    if(Serial.readStringUntil('\n') == "ok")
      success = true;
    wdt_reset();
  }
  
  if(!success)
  {
    PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW)
    hostNotResponding = true;
    if(DEBUG){serialPrint("Host not reached, gates are now shut", NL);}
  }
  else
  {
    serialPrint(String(current,1), NL);
    serialPrint(String(voltage,1), NL);
    for(int i = 0; i < TMP_COUNT; ++i)
    {
        serialPrint(String(temperature[i],1), NL);
    }
  }
}

// http://www.instructables.com/id/Arduino-Timer-Interrupts/

void interrupt_setup()
{
cli();//stop interrupts
/*
//set timer0 interrupt at 2kHz // USED BY PWM
  TCCR0A = 0;// set entire TCCR0A register to 0
  TCCR0B = 0;// same for TCCR0B
  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);
*/

//set timer1 interrupt at 10Hz
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; //initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 3124; // = (16*10^6) / (10*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
/*
//set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
*/

sei();//allow interrupts

}//end setup

ISR(TIMER1_COMPA_vect) //timer1 interrupt
{
  if(setupSuccess)
  {
    board5v = 3.3*1023/analogRead(vref3v3); // Function of 5V*((3.3/5)*1023)/vref3v3
    voltage = (analogRead(vsense)/1023)*board5v*(537/27);

    if(voltage > OVERVOLTAGE)
    {
      PORTC &= B11101111;
      criticalVFailure = true;
    }

    current = board5v*((analogRead(curSense)-analogRead(curSenseRef))/1023)/0.02; // Can measure accuracy to ~0.25A

    if(current > OVERCURRENT)
    {
      PORTC &= B11101111;
      criticalCFailure = true;
    }
    
    if(voltage < LOW_VOLTAGE)
      lowVoltage = true;

    else if(voltage >= LOW_VOLTAGE)
      lowVoltage = false;
  }
}


// These serial funcs are needed because somehow too fast consecutive
// Serial.Print() calls fail to wait the previous calls to finish.
void serialPrint(String message)
{ 
  Serial.print(message);
  Serial.flush(); 
  // Flushing means for arduino just to wait for data to be transmitted,
  // not emptying the queue;
}

void serialPrint(String message, bool NL)
{
  Serial.println(message);
  Serial.flush();
}

void waitFor(String messageWanted)
{
  success = false;
  while(!success)
  {
    while(!Serial.available())
    {
      delay(100);
    }
    
    serialInput = Serial.readStringUntil('\n');

    if(DEBUG)
    {
      serialPrint("Command received: ");
      serialPrint(serialInput, NL);
      Serial.print(serialInput.length(), DEC);
      Serial.flush();
      serialPrint(" bytes", NL);
    }
    
    if(serialInput == messageWanted)
    {
      success = true;
    }
    else
    {
      if(DEBUG) {serialPrint("Answer wasnt wanted, clearing", NL);}
      serialInput = "";
    }
  }
}

String enquire(String query)
{
  success = false;
  while(!success)
  {
    while(!Serial.available())
    {
      delay(1000);
      serialPrint(query, NL);
    }
    
    serialInput = Serial.readStringUntil('\n');

    if(DEBUG)
    {
      serialPrint("Command received: ");
      serialPrint(serialInput, NL);
      Serial.print(serialInput.length(), DEC);
      Serial.flush();
      serialPrint(" bytes", NL);
    }
    
    if(serialInput.length() == CMD_CHAR_COUNT)
    {
      success = true;
    }
    else
    {
      if(DEBUG) {serialPrint("Answer wasnt wanted, clearing", NL);}
      serialInput = "";
    }
  }
  return serialInput;
}


