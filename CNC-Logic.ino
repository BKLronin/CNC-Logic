

int PushButtonPin1 = 2;
int PushButtonPin2 = 3;

int mem1 = LOW;
int mem2 = LOW;

int lastmem1 = LOW;
int lastmem2 = LOW;

int warteDelay = 50;
int LastTime = 0;

int xpro1 = 4;
int xpro2 = 5;

int relais1 = 6;
int relais2 = 7;

int relais1Set = LOW;
int relais2Set = LOW;

int laserPWMin = 9;
int laserPWMout = 10;

int laser_in;
int laser_out;


void setup() {
   
  pinMode(PushButtonPin1, INPUT_PULLUP);
  pinMode(PushButtonPin2, INPUT_PULLUP);
  
  pinMode(xpro1, INPUT);
  pinMode(xpro2, INPUT);

  pinMode(relais1, OUTPUT);
  pinMode(relais2, OUTPUT);

  pinMode(laserPWMin, INPUT);
  pinMode(laserPWMout, OUTPUT);

  //Serial.begin(9600);
}
  // ut your setup code here, to run once:

 void loop() {

  laser_in = pulseIn(laserPWMin, LOW, 5000); 
  //Serial.write(laser_in);  
  laser_out = map(laser_in,0,1000,0,255 );
  analogWrite(laserPWMout, laser_out);
  
  //invertAnalogWrite(laserPWMout, laser_in); 
  
  int reading1 = digitalRead(PushButtonPin1);
  int reading2 = digitalRead(PushButtonPin2);
  int reading3 = digitalRead(xpro1);
  int reading4 = digitalRead(xpro2); 

 
  if (reading3 == LOW){   
    if (reading1 != lastmem1) 
    {LastTime = millis();
      if (mem1 == LOW ) 
      {relais1Set = !relais1Set;}} 

    if ((millis() - LastTime) > warteDelay && reading3 == LOW) 
    {mem1 = reading1;}
  
    digitalWrite(relais1, relais1Set);
    lastmem1 = reading1;
  }
  else
  {  digitalWrite(relais1, reading3);}
  
  
   if (reading4 == LOW){ 
    if (reading2 != lastmem2) 
    {LastTime = millis();
      if (mem2 == LOW) 
      {relais2Set = !relais2Set;}} 

    if ((millis() - LastTime) > warteDelay && reading4 == LOW) 
    {mem2 = reading2;}      

    digitalWrite(relais2, relais2Set);
    lastmem2 = reading2;
   }
  else
  {  digitalWrite(relais2, reading4);}
  
  
  
}
