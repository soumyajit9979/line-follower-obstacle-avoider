#define TP 1
#define EP 2
#define RS 3
int trigPin = 9;      // trig pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04

int revleft4 = 4;       //REVerse motion of Left motor
int fwdleft5 = 5;       //ForWarD motion of Left motor
int revright6 = 6;      //REVerse motion of Right motor
int fwdright7 = 7;      //ForWarD motion of Right motor

long duration, distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 19)            
  {
    digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(500);
    digitalWrite(fwdright7, LOW);      //movebackword         
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    delay(500);
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);  
    delay(100);  
    digitalWrite(fwdright7, HIGH);       
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft4, LOW);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(500);
  }

}
#define LS 4
#define SERVO 5
#define RM1 6
#define RM2 7 
#define LM1 8
#define LM2 9
#define MAX_DISTANCE 200
long duration,distance;

void setup()
{
 pinMode(RS,INPUT);
 pinMode(LS,INPUT);
 pinMode(RM1,OUTPUT);
 pinMode(RM2,OUTPUT);
 pinMode(LM1,OUTPUT);
 pinMode(LM2,OUTPUT);
 pinMode (TP,OUTPUT);
 pinMode (EP,INPUT);
 pinMode (SERVO,OUTPUT);
 Serial.begin (9600);
 delay(50);
}
void loop() 
{
if(digitalRead(LS)==1 && digitalRead(RS)==1)
{   
   digitalWrite(RM1,HIGH);
   digitalWrite(RM2,LOW);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);
} 
if(digitalRead(LS)==0 && digitalRead(RS)==0)
 {  digitalWrite(RM1,HIGH);
   digitalWrite(RM2,LOW);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);
}
if(digitalRead(LS)==1 && digitalRead(RS)==0)
  { digitalWrite(RM1,LOW);
   digitalWrite(RM2,HIGH);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);
}
if(digitalRead(LS)==0 && digitalRead(RS)==1)
{
   digitalWrite(RM1,HIGH);
   digitalWrite(RM2,LOW);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,HIGH);
}
 digitalWrite(TP, LOW);
 delayMicroseconds(2);   
 digitalWrite(TP, HIGH);     
 delayMicroseconds(10);
 duration =pulseIn(EP, HIGH); 
 distance = duration / 58.2;   
 delay(10); 
 Serial.println(distance);
if (distance > 15)            
  {
    digitalWrite(RM1, HIGH);                    
    digitalWrite(RM2, LOW);
    digitalWrite(LM1, HIGH);                                
    digitalWrite(LM2, LOW);                                                       
  }
  if (distance < 14)            
  {
    digitalWrite(RM1,LOW);                    
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,LOW);                                
    digitalWrite(LM2,LOW); 
    delay(200);
     digitalWrite(RM1,LOW);                    
    digitalWrite(RM2,HIGH);
    digitalWrite(LM1,LOW);                                
    digitalWrite(LM2,HIGH); 
    delay(500);
     digitalWrite(RM1,LOW);                    
    digitalWrite(RM2,HIGH);
    digitalWrite(LM1,HIGH);                                
    digitalWrite(LM2,LOW); 
    delay(450);
     digitalWrite(RM1,HIGH);                    
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,HIGH);                                
    digitalWrite(LM2,LOW); 
    delay(2000);
     digitalWrite(RM1,HIGH);                    
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,LOW);                                
    digitalWrite(LM2,HIGH); 
    delay(450);
                                                        
  }}
