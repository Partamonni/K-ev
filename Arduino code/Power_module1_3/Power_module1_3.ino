/* K-ev Power-Module script v1.0

   Written by Henri Pyoria (henri.pyoria@outlook.com)

   Temperature-IC addresses must be manually defined
   to tempAdr table. This skips teh lengthy search for 'em.
   IC's must support resolution configuration! (10bit used)

   2s watchdog implemented after the setups ready, in case of odd failures.
*/

#include <avr/wdt.h>
#include <EEPROM.h>
#include <OneWire.h>

// DO NOT USE DEBUG ON LIVE SYSTEM!!! IMPERATIVE!!!
#define DEBUG 1
#define VERBOSE 0
#define HOST_QUERY_ON 1

#define BAUD 9600
#define FAN_MAX_DUTY_CYCLE 255
#define CMD_CHAR_COUNT 2
#define OVERCURRENT 140
#define OVERVOLTAGE 85
#define LOW_VOLTAGE 58
#define OVER_HEAT 60
#define NL 1
// Newline flag for overloaded serialPrint -function
#define HOST_QUERY_TIME 5000
// ms, time to wait host to answer back before shutting gates
#define EEPROM_SAVE_INTERVAL 3600000
#define READ_TIME 200
// ms, for temperature sensors to sample readings and while monitoring is on
#define TMP_COUNT 41
#define BYTE 8

OneWire ds(10);

const PROGMEM byte  tempAdr[TMP_COUNT][8] =
{ {0x28, 0xBA, 0x4B, 0x41, 0x09, 0x00, 0x00, 0xAE},
  {0x28, 0xEE, 0x46, 0x41, 0x09, 0x00, 0x00, 0xB0},
  {0x28, 0x4C, 0x2B, 0x41, 0x09, 0x00, 0x00, 0x7F},
  {0x28, 0x68, 0x43, 0x41, 0x09, 0x00, 0x00, 0x3A},
  {0x28, 0x8E, 0x3F, 0x41, 0x09, 0x00, 0x00, 0xED},

  {0x28, 0x59, 0x49, 0x41, 0x09, 0x00, 0x00, 0x5D},
  {0x28, 0x2E, 0x4D, 0x41, 0x09, 0x00, 0x00, 0x5F},
  {0x28, 0x5C, 0x3F, 0x41, 0x09, 0x00, 0x00, 0x47},
  {0x28, 0x34, 0x45, 0x41, 0x09, 0x00, 0x00, 0xF5},
  {0x28, 0x53, 0x34, 0x41, 0x09, 0x00, 0x00, 0x13},

  {0x28, 0x84, 0x48, 0x41, 0x09, 0x00, 0x00, 0x1E},
  {0x28, 0x6F, 0x2D, 0x41, 0x09, 0x00, 0x00, 0x0C},
  {0x28, 0xA4, 0x3D, 0x41, 0x09, 0x00, 0x00, 0x17},
  {0x28, 0x6D, 0x3B, 0x41, 0x09, 0x00, 0x00, 0x82},
  {0x28, 0x58, 0x43, 0x41, 0x09, 0x00, 0x00, 0xD7},

  {0x28, 0xF6, 0x28, 0x41, 0x09, 0x00, 0x00, 0xF9},
  {0x28, 0x04, 0x49, 0x41, 0x09, 0x00, 0x00, 0x39},
  {0x28, 0x2B, 0x4D, 0x41, 0x09, 0x00, 0x00, 0xB4},
  {0x28, 0xD2, 0x42, 0x41, 0x09, 0x00, 0x00, 0x3F},
  {0x28, 0x08, 0x2E, 0x41, 0x09, 0x00, 0x00, 0x04},

  {0x28, 0x82, 0x2F, 0x41, 0x09, 0x00, 0x00, 0xEC},
  {0x28, 0x89, 0x29, 0x41, 0x09, 0x00, 0x00, 0x88},
  {0x28, 0xD6, 0x3D, 0x41, 0x09, 0x00, 0x00, 0xE1},
  {0x28, 0x8E, 0x42, 0x41, 0x09, 0x00, 0x00, 0x6C},
  {0x28, 0xC4, 0x40, 0x41, 0x09, 0x00, 0x00, 0x55},

  {0x28, 0xFD, 0x46, 0x41, 0x09, 0x00, 0x00, 0xB2},
  {0x28, 0xC4, 0x28, 0x41, 0x09, 0x00, 0x00, 0x7A},
  {0x28, 0x3F, 0x32, 0x41, 0x09, 0x00, 0x00, 0x31},
  {0x28, 0xFD, 0x2F, 0x41, 0x09, 0x00, 0x00, 0x50},
  {0x28, 0x8F, 0x2E, 0x41, 0x09, 0x00, 0x00, 0x6B},

  {0x28, 0x74, 0x4A, 0x41, 0x09, 0x00, 0x00, 0xEF},
  {0x28, 0x1F, 0x35, 0x41, 0x09, 0x00, 0x00, 0xD6},
  {0x28, 0x4F, 0x25, 0x41, 0x09, 0x00, 0x00, 0x84},
  {0x28, 0xF9, 0x41, 0x41, 0x09, 0x00, 0x00, 0x3F},
  {0x28, 0x36, 0x2A, 0x41, 0x09, 0x00, 0x00, 0xE5},

  {0x28, 0x67, 0x2F, 0x41, 0x09, 0x00, 0x00, 0x2E},
  {0x28, 0x18, 0x4E, 0x41, 0x09, 0x00, 0x00, 0x4E},
  {0x28, 0x4F, 0x27, 0x41, 0x09, 0x00, 0x00, 0x07},
  {0x28, 0x8D, 0x3B, 0x41, 0x09, 0x00, 0x00, 0xAB},
  {0x28, 0x7B, 0x38, 0x41, 0x09, 0x00, 0x00, 0x25},

  {0x28, 0xF4, 0x2E, 0x41, 0x09, 0x00, 0x00, 0x0B}
};
byte data[TMP_COUNT][9];

byte curSense = 0; // Analog pin
byte vsense = 1; // Analog pin
byte vref3v3 = 2; // Analog pin
byte curSenseRef = 3; // Analog pin
byte fanSwitch = 11;
byte mosfetSwitch = A4; // IDE changes these to corresponding pin numbers by itself

volatile double current;
volatile double voltage;
volatile double board5v;
double ms;
double msEEPROM;
double temperature[TMP_COUNT];

volatile double coulombCounter = 0; //Ah
volatile double lastCurrents[100] = {0}; //A
const double defaultCapacity = 80; //Ah
double stateOfHealth = 1; // x100%
double soc = 1; // x100%
const double voltageFull = 84; //V
const double voltageEmpty = 66; //V
const double current0_5C = 41.5; //A
const double current0_3C = 24.9; //A
const double current0_1C = 8.3; //A
const double dischargeVChange1Ah = 0.35; //V
const double ccChargeEndCapacity = 71; //Ah

String serialInput = "";
bool success = false;
bool setupSuccess = false;
bool criticalCFailure = false;
bool criticalVFailure = false;
bool criticalTFailure = false;
bool lowVoltage = false;
bool hostUp = false;
bool hostShut = false;

void interruptSetup();
void systemMonitoring();
void readTemps();
int calcSOC();

void sendData();
void serialPrint(String);
void serialPrint(String, int);
String enquire(String);
bool checkIfShut();
void checkHost();

int adConversion(byte);
byte* getTempAdr(byte n);

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

  DIDR0 = B00001111; // Set A0-A4 as analog inputs

  Serial.begin(BAUD);
  Serial.println("Board started");
  serialInput.reserve(64);  // These values are probably too unoptimized,
  Serial.setTimeout(200);   // but I don't really care too much for now.

  current = 250 * ((adConversion(curSense) - adConversion(curSenseRef)) / 1023);
  // ^ Can measure accuracy to ~0.25A
  // 5*((analogRead(curSense)-analogRead(curSenseRef))/1023)/0.02

  if(current > 0.5 || current < -0.5)
  {
    do
    {
      serialPrint("!C", NL); // Board current failure
      delay(1000);
    }
    while (!DEBUG);
  } // These trap loops are to send alert to user interface
  // They can be cleared only by full power cycle (for now, atleast)

  board5v = 3375.9 / adConversion(vref3v3);
  // ^ Returns real voltage referring to internal 3v3 regulator voltage
  // Simplified function of 5V*((3.3/5)*1023)/vref3v3
  // 3v3 output pin shorted to analog input
  voltage = 179 * adConversion(vsense) * board5v / 9207;
  // Simplified function of (analogRead(vsense)/1023)*board5v*(537/27)
  // (537/27) is a multiplier to counter voltage divider in the circuit
  
  if(voltage > OVERVOLTAGE || voltage < LOW_VOLTAGE)
  {
    do
    {
      serialPrint("!V", NL); // Board voltage failure
      delay(1000);
    }
    while (!DEBUG);
  }

  msEEPROM = millis();
  byte tmp[4];
  for (int i = 0; i < 4; ++i)
  {
    tmp[i] = EEPROM.read(i);
  }
  memcpy(&coulombCounter, tmp, 4);
  
  for (int i = 0; i < 4; ++i)
  {
    tmp[i] = EEPROM.read(i+4);
  }
  memcpy(&stateOfHealth, tmp, 4);

  // If no EEPROM value ->
  if(coulombCounter == 0)
  { // Initialize SOC to an approximate with voltage
    coulombCounter = (defaultCapacity*stateOfHealth)*((voltage-voltageEmpty)/(voltageFull-voltageEmpty));
  }
  
  if(stateOfHealth == 0)
    stateOfHealth = 1;

  interruptSetup();
#if DEBUG&&VERBOSE
  serialPrint("Interrupts now in place", NL);
#endif

  if(!ds.reset())
  {
    do
    {
      serialPrint("!T", NL); // Sensor bus failed
      delay(1000);
    }
    while (!DEBUG);
  }

  // Write config command and config values to all devices
  byte setCnf[4] = {0x4E, 0x7C, 0x0A, B00111111};
  ds.skip();
  ds.write_bytes(setCnf, 4);
  ds.reset(); // reset 1-Wire

  while (enquire("?h") != "ok") {}

  serialPrint(String(current, 1), NL);
  serialPrint(String(voltage, 1), NL);

  setupSuccess = true;
  wdt_reset();
  wdt_enable(WDTO_2S);

#if DEBUG&&VERBOSE
  serialPrint("wdt reset and enabled", NL);
#endif

  PORTC |= B00010000; // digitalWrite(mosfetSwitch, HIGH);
  serialPrint("up", NL);
}

void loop()
{
  wdt_reset();

  if(!ds.reset())
    serialPrint("!T", NL); // Sensor bus failed
  else
  {
    ds.skip(); // Select all sensors
    ds.write(0x44); // Command to start measurement
  }

  ms = millis(); // Store current time
  while (READ_TIME >= (unsigned long)(millis() - ms)) // Secondary loop
    systemMonitoring();     
  // Do over 200ms if no extra timing is given for temp sensors to do conversion
  
  wdt_reset();

#if DEBUG&&VERBOSE
  serialPrint("Secondary loop completed", NL);
#endif

  readTemps(); // Read and store temperatures
  wdt_reset();

  calcSOC();
  wdt_reset();

  checkHost();  // Check if host is up and set gate status accordingly

  sendData(); // Send gathered data

  // Save coulombCounter to EEPROM once an hour
  // EEPROM is calculated to quaranteedly withstand 10y with this interval
  if(EEPROM_SAVE_INTERVAL <= (unsigned long)(millis() - msEEPROM))
  {
    byte tmp[4];
    memcpy(tmp, &coulombCounter, 4);
    for (int i = 0; i < 4; ++i)
      EEPROM.update(i, tmp[i]);
      
    memcpy(tmp, &stateOfHealth, 4);
    for (int i = 0; i < 4; ++i)
      EEPROM.update(i+4, tmp[i]);

    msEEPROM = millis(); // Store current time
  }
}

void systemMonitoring()
{
  if(criticalCFailure || criticalVFailure || criticalTFailure)
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
  else if(hostUp && !(PORTC & B00010000) && !checkIfShut())
  {
    PORTC |= B00010000; // digitalWrite(mosfetSwitch, HIGH);
    serialPrint("up", NL);
  }

  if(lowVoltage)
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
}

void readTemps()
{
  for (byte i = 0; i < TMP_COUNT; ++i)
  {
    if(pgm_read_byte(tempAdr[i][7]) != 0x00) // This checks if sensors' address table entry has any address in it
    {
#if DEBUG&&VERBOSE
      serialPrint("Entered read cycle i=");
      serialPrint(String(i, DEC), NL);
#endif
      ds.reset();
      ds.select(getTempAdr(i));
#if DEBUG&&VERBOSE
      serialPrint("Device selected", NL);
      serialPrint("Commanding to read out the scratchpad", NL);
#endif
      ds.write(0xBE); // Request sensor to read out the scratchpad
      for (byte j = 0; j < 9; ++j) // Read all 9 bytes
      {
        data[i][j] = ds.read();
      }
#if DEBUG&&VERBOSE
      for (byte j = 0; j < 9; ++j)
      {
        if(data[i][j] <= 0x0F)
          serialPrint("0");
        serialPrint(String(data[i][j], HEX));
      }
      serialPrint("\nData read", NL);
#endif
      if(OneWire::crc8(data[i], 8) != data[i][8])
      { // If crc is wrong, set all bits to 1
        for (byte k = 0; k < 9; ++k)
          data[i][k] = 0xFF;
#if DEBUG&&VERBOSE
        serialPrint("CRC Check failed!", NL);
#endif
      }
    }
    else
      break;
  }

  int16_t rawTemp;
  for (byte i = 0; i < TMP_COUNT; ++i)
  {
    if(pgm_read_byte(tempAdr[i][7]) != 0x00)
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
      temperature[i] = 85.0 * (double(rawTemp) / 1360.0);

      if(i == 0 && temperature[i] >= 120)
      { // This sensor will be in the mosfet heatsink
        PORTC &= B11101111;
        criticalTFailure = true;
      }
      else if(i != 0 && temperature[i] >= OVER_HEAT)
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
#if DEBUG&&VERBOSE&&0
  serialPrint("Peeking: ");
  serialPrint(String(Serial.peek()), NL);
#endif
  if(Serial.peek() == '!')
  {
    if(Serial.readStringUntil('\n') == "!S")
    {
      PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW)
      hostShut = true;
      serialPrint("sh", NL);
#if DEBUG&&VERBOSE
      serialPrint("Gate is now shut by host", NL);
#endif
      return true;
    }
  }
  return false;
}

void interruptSetup() // http://www.instructables.com/id/Arduino-Timer-Interrupts/
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
  // set compare match register for 10hz increments
  OCR1A = 3124; // = (16*10^6) / (10*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  /*
    //set timer2 interrupt at 1kHz
    TCCR2A = 0;// set entire TCCR2A register to 0
    TCCR2B = 0;// same for TCCR2B
    TCNT2  = 0;//initialize counter value to 0
    // set compare match register for 10khz increments
    OCR2A = 249;// = (16*10^6) / (10000*64) - 1 (must be <256)
    // turn on CTC mode
    TCCR2A |= (1 << WGM21);
    // Set CS22 bit for 64 prescaler
    TCCR2B |= (1 << CS22);
    // enable timer compare interrupt
    TIMSK2 |= (1 << OCIE2A);
  */
  sei(); //allow interrupts

}//end setup

ISR(TIMER1_COMPA_vect) //timer1 interrupt
{
  board5v = 3375.9 / adConversion(vref3v3); // Simplified Function of 5V*((3.3/5)*1023)/vref3v3
  voltage = 179 * adConversion(vsense) * board5v / 9207; // Simplified Function of (vsense/1023)*board5v*(537/27)

  if(voltage > OVERVOLTAGE)
  {
    PORTC &= B11101111;
    criticalVFailure = true;
  }

  // Can measure accuracy to ~0.25A
  current = board5v * ((adConversion(curSense) - adConversion(curSenseRef)) / 1023) / 0.02;

  if(current > OVERCURRENT)
  {
    PORTC &= B11101111;
    criticalCFailure = true;
  }

  if(voltage < LOW_VOLTAGE)
    lowVoltage = true;
  else if(voltage >= LOW_VOLTAGE)
    lowVoltage = false;

  static byte i = 0;
  static double currentHelper = 0;
  coulombCounter += current / 360000; // Simplified from: current*0.01/60/60
									  //                        10ms^  ^m  ^h
  if(i++ < 10) // get average current on 100ms period
    currentHelper += current;
  else
  { // This adds new current entry after every 100ms
    currentHelper /= 10;
    memmove(&lastCurrents[1], &lastCurrents[0], sizeof(double) * 99);
    lastCurrents[0] = currentHelper;
    currentHelper = 0;
    i = 0;
  }
}

// These serial funcs are needed because somehow too fast consecutive
// Serial.Print() calls fail to wait the previous calls to finish.
void serialPrint(String message)
{
  Serial.print(message);
  Serial.flush();
  // Flushing means for arduino just to wait for data to be transmitted,
  // not emptying the queue
}

void serialPrint(String message, int nl)
{
  Serial.println(message);
  Serial.flush();
}

String enquire(String query)
{
  success = false;
  while (!success)
  {
    while (!Serial.available())
    {
      delay(500);
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
  for (byte i = 0; i < 16; ++i)
    bits += bitRead(data, 15 - i);

  Serial.println(bits);
}
#endif

int calcSOC()
{
  double capacity = stateOfHealth * defaultCapacity;
  soc = (capacity - coulombCounter) / capacity;

  static bool cvCharging = false;

  // Cell manufacturer has given discharge curve for the cells at 0.5C current,
  // and 1V voltage drop equals roughly 0.35Ah for a cell.
  // We use that for estimating the SOC.

  bool nominalUsage = true;
  bool lightUsage = true;
  cli(); // disable interrupts for a brief moment
  for (byte i = 0; i < 100; ++i)
  {
    if(lastCurrents[i] > current0_5C)
    {
      nominalUsage = false;
      lightUsage = false;
    }
    else if(lastCurrents[i] < current0_3C)
    {
      nominalUsage = false;
      if(lastCurrents[i] > current0_1C && lastCurrents[i] < 0)
      {
        lightUsage = false;
      }
    }
    if(!lightUsage && !nominalUsage)
      break;
  }
  sei();

  if(nominalUsage)
  {
    double socHelper =
      (capacity - (32 * (82 - voltage) / dischargeVChange1Ah)) / capacity;
    // 32 is number of parallel cells, thus used capacity is 32 times that of a single cell

    socHelper += soc * 99;
    socHelper /= 100;
    soc = socHelper;
    // Function reaches 90% of end value in about 45 seconds when execution happens every 200ms
  }
  else if(lightUsage)
  {
    if(voltage < voltageFull)
    {
      double socHelper = capacity*((voltage-voltageEmpty)/(voltageFull-voltageEmpty));
      socHelper += soc * 9999;
      socHelper /= 10000;
      soc = socHelper;
    // Function reaches 90% of end value in about 76 minutes when execution happens every 200ms
    }
  }

  if(voltage <= voltageEmpty && current < current0_1C)
  {
    soc = 0;
    if(coulombCounter < defaultCapacity)
    {
      stateOfHealth = coulombCounter / defaultCapacity;
    }
  }
  else if(!cvCharging && voltage >= voltageFull
           && current < 0 && current >= -current0_5C)
  {
    soc = 2220 / defaultCapacity;
    cvCharging = true;
  }
  else if(cvCharging && current >= 0)
    cvCharging = false;
}

int adConversion(byte ch)
{
  ADMUX = B01000000 | ch; // Select pin and voltage reference
  ADCSRA = B11000111; // Start conversion (first 2 bits from left) with prescaler 128 (last 3 bits)

  while ((ADCSRA & B01000000) != 0) {}; // Wait for status bit to flip

  return ADC;
}

void sendData()
{
  serialPrint(":c");
  serialPrint(String(current, 1), NL);
  serialPrint(":v");
  serialPrint(String(voltage, 1), NL);
  serialPrint(":s");
  serialPrint(String(soc, 3), NL);
  serialPrint(":h");
  serialPrint(String(stateOfHealth, 3), NL);
  for (byte i = 0; i < TMP_COUNT; ++i)
  {
    if(tempAdr[i][7] != 0x00)
    {
      serialPrint(String(':'));
      serialPrint(String(i));
      serialPrint(String('-'));
      serialPrint(String(temperature[i], 1), NL);
    }
    else
      break;
  }
  serialPrint("e~", NL);
}

void checkHost()
{
  checkIfShut();

#if HOST_QUERY_ON

  // Check if host has answered "ok"

  if(Serial.readStringUntil('\n') != "ok")
  { // If not, false hostUp flag and try to reach host
    hostUp = false;
    serialPrint("?h", NL);

    ms = millis();
    while (!hostUp && HOST_QUERY_TIME > (unsigned long)(millis() - ms))
    {
      if(Serial.available() && Serial.readStringUntil('\n') == "ok")
        hostUp = true;
      else
      {
        serialPrint("?h", NL);
        systemMonitoring();
        delay(HOST_QUERY_TIME / 10);
      }
      wdt_reset();
    } // If not reachable, shut the gates
    if(!hostUp)
    {
      PORTC &= B11101111; // digitalWrite(mosfetSwitch, LOW)
      #if DEBUG&&VERBOSE
        serialPrint("Host not reached, gates are now shut", NL);
      #endif
    }
  }
  else
    hostUp = true;
  // If host had responded in time, func execution just jumps and ends here

#endif
}

byte* getTempAdr(byte n)
{
  static byte tmp[8];
  for (int i = 0; i < 8; ++i)
    tmp[i] = pgm_read_byte_near(tempAdr[n][i]);

  return tmp;
}
