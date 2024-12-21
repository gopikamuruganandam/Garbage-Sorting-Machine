const int trigPin = 14;
const int echoPin = 15;

long duration;
int distanceCm, distanceInch;

int pro = 7;
// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 9; 
// Create a servo object 
Servo Servo1; 
void setup()
{ 
  Serial.begin(9600); 
  pinMode(A2,INPUT);
    Servo1.attach(servoPin); 
 pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  pinMode(pro, INPUT);

}
void loop()
{
 int gas = analogRead(A2);
  digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
    distanceInch = duration*0.0133/2;
Serial.println(distanceCm);
Serial.print(gas);
    delay(100);
  if(distanceCm<4)
  {
    // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(1000); 
  
    Serial.println("OBJECT");
    delay(1000); 
  }
if(digitalRead(pro)==LOW)
{
 // Make servo go to 90 degrees 
   Servo1.write(90); 		
   delay(1000); 
 
  Serial.println("PRO");
  delay(1000);
}
if(gas<1000)
{
    // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); 
  Serial.println("SOIL");
  delay(1000);
}
 
}