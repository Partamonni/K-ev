/* K-ev Power-Module script v1.0
 *  
 * Written by Henri Pyoria (henri.pyoria@outlook.com)
 *  
 * Temperature-IC addresses must be manually defined 
 * to tempAdr table. This skips teh lengthy search for 'em.
 * IC's must support resolution configuration! (10bit used)
 * 
 * 2s watchdog implemented after the setups ready, in case of odd failures.
 */

#include <avr/wdt.h>
#include <OneWire.h>

#define DEBUG 1
#define VERBOSE 0
#define HOST_QUERY_ON 1
 // DO NOT USE DEBUG ON LIVE SYSTEM!!! IMPERATIVE!!!

const int FAN_MAX_DUTY_CYCLE = 35; //(12/72)*256 and lowered still a bit for first tests
const int CMD_CHAR_COUNT = 2;
const int OVERCURRENT = 140;
const int OVERVOLTAGE = 85;
const int LOW_VOLTAGE = 58;
const int OVER_HEAT = 60;
const int NL = 1;  // Newline flag for overloaded serialPrint -function
const int HOST_QUERY_TIME = 5000; // ms | Change for real application
const int READ_TIME = 200; // ms, for temperature sensors to sample readings and while monitoring is on
const int TMP_COUNT = 41;
const int BYTE = 8;

// const bool DEBUG = true; // DO NOT USE THIS ON LIVE SYSTEM!!! IMPERATIVE!!!

OneWire ds(2);

byte  tempAdr[TMP_COUNT][8] =
{ {0x28, 0xBA, 0x4B, 0x41, 0x09, 0x00, 0x00, 0xAE},
  {0x28, 0xEE, 0x46, 0x41, 0x09, 0x00, 0x00, 0xB0},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
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

bool checkIfShut();
void interrupt_setup();
void serialPrint(String);
void serialPrint(String, bool);
String enquire(String);
#if DEBUG&&VERBOSE
void printBits(byte);
#endif

void setup() 
{
  DDRC |= B00010000; // pinMode(mosfetSwitch, OUTPUT);
  PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW);
  wdt_disable();
  wdt_reset();
  pinMode(fanSwitch, OUTPUT);
  analogWrite(fanSwitch, FAN_MAX_DUTY_CYCLE);
  pinMode(curSense, INPUT);
  pinMode(curSenseRef, INPUT);
  
  Serial.begin(57600);
  Serial.println("Board started");
  serialInput.reserve(64);  // These values are probably too unoptimized,
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

  #if DEBUG&&VERBOSE
  
    serialPrint("Interrupts now in place", NL);
  #endif
  
  if(!ds.reset())
  {
    do
    {
      serialPrint("!T", NL); // Board temperature failure
      delay(1000);
    }
    while(!DEBUG);
  }

  // Write config command and config values to all devices
  byte setCnf[4] = {0x4E, 0x7C, 0x0A, B00111111};
  ds.skip();
  ds.write_bytes(setCnf, 4);
  ds.reset(); // reset 1-Wire

  while(enquire("?h") != "ok"){} 

  serialPrint(String(current,1), NL);
  serialPrint(String(voltage,1), NL);

  
  
  setupSuccess = true;
  wdt_reset();
  wdt_enable(WDTO_2S);

  #if DEBUG&&VERBOSE
    serialPrint("wdt reset and enabled", NL);
  #endif
  digitalWrite(mosfetSwitch, HIGH);
  serialPrint("up", NL);
}

void loop() 
{
  wdt_reset();
  #if DEBUG&&VERBOSE
    serialPrint("loop() entered", NL);
  #endif

  ds.reset();
  ds.skip();
  ds.write(0x44); // Command temperature sensors to start measurement
  
  ms = millis(); // Store current time             
  while(ms+READ_TIME >= millis()) // Secondary loop  
    systemMonitoring();     // Do over 200ms if no extra timing is
                            // given for temp sensors to do conversion    
  wdt_reset();

  #if DEBUG&&VERBOSE
    serialPrint("Secondary loop completed", NL);
  #endif
  
  readTemps(); // Read and store temperatures
  wdt_reset();
  
  success = true;
  checkIfShut();
  
  #if HOST_QUERY_ON
  if(Serial.readStringUntil('\n') != "ok")
  {
    serialPrint("?h", NL);
    success = false;
  }
  else
    hostShut = false;
  
  ms = millis();
  while(!hostShut && !success && ms+HOST_QUERY_TIME > millis())
  {  
    if(checkIfShut())
      break;
    else if(Serial.available() && Serial.readStringUntil('\n') == "ok")
    {
      success = true;
    }
    else
      delay(HOST_QUERY_TIME/4);
    wdt_reset();
  }
  #endif
  
  if(!hostShut && !success)
  {
    PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW)
    hostNotResponding = true;
    #if DEBUG&&VERBOSE
      serialPrint("Host not reached, gates are now shut", NL);
    #endif
  }
  else
  {
    serialPrint(":c");
    serialPrint(String(current,1), NL);
    serialPrint(":v");
    serialPrint(String(voltage,1), NL);
    for(int i = 0; i < TMP_COUNT; ++i)
    {
      if(tempAdr[i][7] != 0x00)
      {
        serialPrint(String(':'));
        serialPrint(String(i));
        serialPrint(String('-'));
        serialPrint(String(temperature[i],1), NL);
      }
      else
        break;
    }
    serialPrint("e~", NL);
  }
}

void systemMonitoring()
{
  if(criticalCFailure || criticalVFailure || criticalTFailure || lowVoltage)
  {
    if(!criticalCFailure || !criticalVFailure || !criticalTFailure)
    {
      do
      {
        serialPrint("!v", NL);
        delay(1000);
        wdt_reset();
      }
      while(!DEBUG && lowVoltage);
      if(!hostShut && !DEBUG)
        serialPrint("up", NL);
    }
    else
    {
      do
      {
        if(criticalCFailure)
          serialPrint("!C", NL);
        if(criticalVFailure)  
          serialPrint("!V", NL);
        if(criticalTFailure)
          serialPrint("!T", NL);
        if(lowVoltage)
          serialPrint("!v", NL);
        delay(1000);
        wdt_reset();
      }
      while(!DEBUG);
    }
  }

  if(!checkIfShut() && hostNotResponding) // checkIfShut() is executed every time
  {
    serialPrint("?h", NL);
    delay(10);
    if(Serial.available() && Serial.readStringUntil('\n') == "ok")
    {
      hostNotResponding = false;     
      hostShut = false;      
      digitalWrite(mosfetSwitch, HIGH);
      serialPrint("up", NL);
      #if DEBUG&&VERBOSE
        serialPrint("Host responded, gates are now open", NL);
      #endif
    }
  }
}

void readTemps()
{
  for(int i = 0; i < TMP_COUNT; ++i)
  {
    if(tempAdr[i][7] != 0x00) // This checks if sensors' address table entry has any address in it
    {   
      #if DEBUG&&VERBOSE
        serialPrint("Entered read cycle i=");
        serialPrint(String(i, DEC), NL);
      #endif
      ds.reset();
      ds.select(tempAdr[i]);
      #if DEBUG&&VERBOSE
        serialPrint("Device selected", NL);
        serialPrint("Commanding to read out the scratchpad", NL);
      #endif          
      ds.write(0xBE); // Request sensor to read out the scratchpad
      for(int j = 0; j < 9; ++j) // Read all 9 bytes
      {
        data[i][j] = ds.read();
      }
      #if DEBUG&&VERBOSE
        for(int j = 0; j < 9; ++j)
        {
          if(data[i][j]<=0x0F)
            serialPrint("0");
          serialPrint(String(data[i][j], HEX));
        }
        serialPrint("\nData read", NL);
      #endif
      if(OneWire::crc8(data[i], 8) != data[i][8])
      { // If crc is wrong, set all bits to 1
        for(int k = 0; k < 9; ++k)
          data[i][k] = byte(0xFF, HEX);
        #if DEBUG&&VERBOSE
          serialPrint("CRC Check failed!", NL);
        #endif
      }
    }
    else
      break;
  }

  int16_t rawTemp;
  for(int i = 0; i < TMP_COUNT; ++i)
  {
    if(tempAdr[i][7] != 0x00)
    {
      rawTemp = 0;
      rawTemp = (data[i][1] << BYTE) | data[i][0];
      // ^ Reads data to temporary container
      rawTemp &= ~3;
      // ^ Sets last 2 bits to zero,
      // as 10-bit resolution doesn't use them
      #if DEBUG&&VERBOSE
        printBits(rawTemp);
      #endif
      temperature[i] = 85.0*(double(rawTemp)/1360.0);

      if(i==0 && temperature[i] >= 120)
      { // This sensor will be in the mosfet heatsink
        PORTC &= B11101111;
        criticalTFailure = true;
      }
      else if(i!=0 && temperature[i] >= OVER_HEAT)
      {
        PORTC &= B11101111;
        criticalTFailure = true;        
      }
    }
    else
      break;
  }
}

bool checkIfShut()
{
  #if DEBUG&&VERBOSE
    serialPrint("Peeking: ");
    serialPrint(String(Serial.peek()), NL);
  #endif
  if(Serial.peek() == '!')
  {
    if(Serial.readStringUntil('\n') == "!S")
    {
      PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW)
      hostShut = true;
      hostNotResponding = false;
      serialPrint("sh", NL);
      #if DEBUG&&VERBOSE
        serialPrint("Gate is now shut by host", NL);
      #endif
      return true;
    } 
  }
  return false;
}

void interrupt_setup() // http://www.instructables.com/id/Arduino-Timer-Interrupts/
{ 
  cli(); //stop interrupts
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

  sei(); //allow interrupts

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

String enquire(String query)
{
  success = false;
  while(!success)
  {
    while(!Serial.available())
    {
      delay(1000);
      serialPrint(query, NL);
      systemMonitoring();
    }
    
    serialInput = Serial.readStringUntil('\n');

    #if DEBUG&&VERBOSE
      serialPrint("Command received: ");
      serialPrint(serialInput, NL);
      Serial.print(serialInput.length(), DEC);
      Serial.flush();
      serialPrint(" bytes", NL);
    #endif
    
    if(serialInput.length() == CMD_CHAR_COUNT)
    {
      success = true;
    }
    else
    {
      #if DEBUG&&VERBOSE
        serialPrint("Answer wasn't wanted, clearing", NL);
      #endif
      serialInput = "";
    }
  }
  return serialInput;
}
#if DEBUG&&VERBOSE
void printBits(int data)
{
  String bits;
  for(int i = 0; i < 16; ++i)
    bits += bitRead(data, 15-i);
    
  Serial.println(bits);
}
#endif
