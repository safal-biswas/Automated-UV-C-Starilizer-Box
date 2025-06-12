#include <NewPing.h>
#include <Servo.h>

NewPing eye(11, 12, 40);      //Trig = Pin 11, Echo = Pin 12, Max distance = 40cm
Servo door_left, door_right;

int white = 2;                //White LED to digital pin 2
int red = 3;
int green = 4;
int yellow = 7;
int uv = 13;

int cleaning_time = 30000;    //30 seconds
int n = 10;

void setup() {
  door_left.attach(6);       //Left servo to PWM pin 6
  door_right.attach(5);      //Right servo to PWM pin 5

  pinMode(white, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(uv, OUTPUT);
}



void delay_sec() {                //function for certain seconds of delay
  for(int i=1; i<=n; i++) {
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(yellow, LOW);
    delay(500);
  }
}



void loop() {

  int distance = eye.ping_cm();            //taking distance by ultrasonic sensor

  if(distance <= 30 && distance > 10  && distance != 0) {

    digitalWrite(green, LOW);
    
    delay(1000);
    for(int i=5; i<=180; i++) {         //Door Open
      door_left.write(i);
      door_right.write(i);
    }
    delay(1000);
    
    digitalWrite(white, HIGH);
    delay_sec();


    for(int i=1; i<=5; i++) {            //Primary Warning for 5 seconds
      digitalWrite(red, HIGH);
      digitalWrite(yellow, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      delay(500);

      int distance2 = eye.ping_cm();
      if (distance2 <= 10 && distance2 !=0) {      // If in second distance
        digitalWrite(red, HIGH);
        digitalWrite(green, HIGH);
        delay(1500);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);

        delay_sec();
        for(int i=1; i<=5; i++) {                 //Final Warning for 5 seconds
          digitalWrite(red, HIGH);
          digitalWrite(yellow, HIGH);
          delay(500);
          digitalWrite(red, LOW);
          digitalWrite(yellow, LOW);
          delay(500);
        }
        break;
      }
    }

    digitalWrite(white, LOW);
    
    delay(1000);
    for(int i=180; i>=5; i--) {           //Door Close
      door_left.write(i);
      door_right.write(i);
    }
    delay(1000);
    
    digitalWrite(uv, HIGH);               //Cleaning
    digitalWrite(yellow, HIGH);
    delay(cleaning_time);
    digitalWrite(uv, LOW);
    digitalWrite(yellow, LOW);

    digitalWrite(red, HIGH);              //Done Signal
    delay(200);
    digitalWrite(red, LOW);

    digitalWrite(green, HIGH);
  }
}
