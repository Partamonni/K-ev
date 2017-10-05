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

const int FAN_MAX_DUTY_CYCLE = 35; //(12/72)*256 and lowered still a bit for first tests
const int CMD_CHAR_COUNT = 2;
const int OVERCURRENT = 140;
const int OVERVOLTAGE = 85;
const int LOW_VOLTAGE = 58;
const bool NL = true; // Newline flag for overloaded serialPrint -function

String serialInput = "";
char cmd[CMD_CHAR_COUNT];
bool success = false;
bool setupSuccess = false;
bool valuesUpdated = false;
bool criticalFailure = false;
bool lowVoltage = false;

void interrupt_setup();
void serialPrint(String);
void serialPrint(String, bool);
void waitFor(String);
String enquire(String);

bool DEBUG = true;

void setup() 
{
  DDRC = DDRC | B00010000; // pinMode(mosfetSwitch, OUTPUT);
  PORTC = PORTC & B11101111; // digitalWrite(mosfetSwitch, LOW);
  pinMode(fanSwitch, OUTPUT);
  analogWrite(fanSwitch, FAN_MAX_DUTY_CYCLE);
  pinMode(curSense, INPUT);
  pinMode(curSenseRef, INPUT);
  
  Serial.begin(115200);
  Serial.println("Board started");
  serialInput.reserve(64);

  current = 5*((analogRead(curSense)-analogRead(curSenseRef))/1023)/0.02; // Can measure accuracy to ~0.25A
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
  voltage = (analogRead(vsense)/1023)*board5v*(537/27);
  if (voltage > OVERVOLTAGE || voltage < LOW_VOLTAGE)
  {
    do
    {
      serialPrint("!V", NL); // Board voltage failure
      delay(1000);
    }
    while(!DEBUG);
  }

  while(enquire("?h") != "ok"){}

  serialPrint(String(current,1), NL);
  serialPrint(String(voltage,1), NL);
  while(enquire("?t") != "ok"){}

  interrupt_setup();

  setupSuccess = true;
}

void loop() 
{
  ms = millis();
  while(ms+30 <= millis())
  {
    if(criticalFailure)
    {
      do
      {
        serialPrint("!C", NL);
        serialPrint("!V", NL);
        delay(1000);
      }
      while(!DEBUG);
    }

    if(Serial.available())
    {
      if(Serial.readStringUntil('\n') == "!S"){};
        
    }
    
    if(lowVoltage)
    {
      do
      {
        serialPrint("!v", NL);
        delay(1000);
      }
      while(!DEBUG || lowVoltage);
    }
  }
  
  serialPrint(String(current,1), NL);
  serialPrint(String(voltage,1), NL);
}

// https://www.instructables.com/id/Arduino-Timer-Interrupts/

void interrupt_setup()
{
cli();//stop interrupts
/*
//set timer0 interrupt at 2kHz
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
  OCR1A = 3124; // = (16*10^6) / (1*1024) - 1 (must be <65536)
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
    current = 5*((analogRead(curSense)-analogRead(curSenseRef))/1023)/0.02; // Can measure accuracy to ~0.25A

    if(current > OVERCURRENT || voltage > OVERVOLTAGE)
    {
      PORTC = PORTC & B11101111;
      criticalFailure = true;
    }

    board5v = 3.3*1023/analogRead(vref3v3); // Function of 5V*((3.3/5)*1023)/vref3v3
    voltage = (analogRead(vsense)/1023)*board5v*(537/27);
    
    if(voltage < LOW_VOLTAGE)
    {
      lowVoltage = true;
    }
    else if(voltage >= LOW_VOLTAGE)
    {
      lowVoltage = false;
    }
    valuesUpdated = true; 
  }
}

void serialPrint(String message)
{
  Serial.print(message);
  Serial.flush();
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