int vsense = A1;
int curSense = A2;
int curSenseRef = A3;
int vref3v3 = A2;
int fanSwitch = 11;
int mosfetSwitch = A4;
double boardVoltage;
double current;
double voltage;
double board5v;
int FAN_MAX_DUTY_CYCLE = 35; //(12/72)*256 and lowered still a bit for first tests
String serialInput = "";
bool packageReady = false;


void setup() 
{
  pinMode(mosfetSwitch, OUTPUT);
  digitalWrite(mosfetSwitch, LOW);
  pinMode(fanSwitch, OUTPUT);
  analogWrite(fanSwitch, FAN_MAX_DUTY_CYCLE);
  pinMode(curSense, INPUT);
  pinMode(curSenseRef, INPUT);
  
  Serial.begin(9600);
  Serial.println("Board started");
  serialInput.reserve(200);

  current = (5*((analogRead(curSense)-analogRead(curSenseRef))/1023)/0.02; // Can measure accuracy to ~0.25A
  if (current > 0.5 || current < -0.5)
  {
    while(true)
    {
    Serial.println("!C"); // Board current failure
    delay(1000);
    }
  }

  pinMode(vsense, INPUT);
  pinMode(vref3v3, INPUT);
  board5v = 3.3*1023/analogRead(vref3v3); // Function of 5V*((3.3/5)*1023)/vref3v3
  voltage = (analogRead(vsense)/1023)*board5v*(537/27);
  if (packVoltage > 85 || packVoltage < 65)
  {
    while(true)
    {
    Serial.println("!V"); // Board voltage failure
    delay(1000);
    }
  }
}

void loop() 
{
  
  while(!Serial.available())
  {
    Serial.println("rfh"); // rfh: ready for host
  }
  
  while(Serial.available())
    serialInput = Serial.readStringUntil("\n");
    
    if(serialInput == "ack")
    {
      Serial.println(packVoltage);
      Serial.println(current);
      Serial.readStringUntil("\n);
    }
}
