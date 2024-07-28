String serialCommunication;


#include <Servo.h>



const int echo = 13;
const int trig = 12;

Servo servo_motor; 
 
int ultasonicWaves_time = 0;
int object_distance  = 0;



void setup()

{
    servo_motor.attach(9);

    pinMode(trig , OUTPUT);
    pinMode(echo , INPUT);
    pinMode(2 , OUTPUT);
    pinMode(3 , OUTPUT);
    pinMode(5 , OUTPUT);
    pinMode(7 ,OUTPUT);
    Serial.begin(9600);

  
 
  
}

void loop()

{
   digitalWrite(trig ,HIGH);
   delay(1000);
   digitalWrite(trig ,LOW); 

   ultasonicWaves_time = pulseIn(echo , HIGH);
   object_distance  = (ultasonicWaves_time/2) /28.5;
   Serial.println(object_distance );
  
   
   servo_motor.write(0);
   
   if (object_distance <= 20 )
   {
    digitalWrite(2 ,HIGH);
    digitalWrite(3 ,HIGH);
    digitalWrite(5 ,HIGH);
    digitalWrite(7 ,HIGH);

    servo_motor.attach(9);
    servo_motor.write(160);
    delay(1000);
    servo_motor.write(0);
    delay(1500);

    
   }
   
  else

  {
    
    digitalWrite(2 ,LOW);
    digitalWrite(3 ,LOW);
    digitalWrite(5 ,LOW);
    digitalWrite(7 ,LOW);

    servo_motor.detach();
   
  }
  
  
  
  if (Serial.available()) {
    serialCommunication = Serial.readStringUntil('\n');
    serialCommunication.trim();
    if(serialCommunication.equals("red"))
    {
      digitalWrite(2 ,HIGH);
      digitalWrite(3 ,HIGH);
    }
    else 

    {
      digitalWrite(2 ,LOW);
      digitalWrite(3 ,LOW);
      digitalWrite(5 ,LOW);
      digitalWrite(7 ,LOW);
      
      
    }
  }
   
}
