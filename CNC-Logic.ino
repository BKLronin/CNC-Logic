int PushButtonPin1 = 4;
int PushButtonPin2 = 5;

int mem1 = LOW;
int mem2 = LOW;

int lastmem1 = LOW;
int lastmem2 = LOW;

int warteDelay = 50;
int LastTime = 0;

int xpro1 = 2;
int xpro2 = 3;

int relais1 = 0;
int relais2 = 1;

int relais1Set = LOW;
int relais2Set = LOW;


void setup() {
   
  pinMode(PushButtonPin1, INPUT_PULLUP);
  pinMode(PushButtonPin2, INPUT_PULLUP);
  
  pinMode(xpro1, INPUT);
  pinMode(xpro2, INPUT);

  pinMode(relais1, OUTPUT);
  pinMode(relais2, OUTPUT);
}
  // put your setup code here, to run once:

void loop() {
  
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
