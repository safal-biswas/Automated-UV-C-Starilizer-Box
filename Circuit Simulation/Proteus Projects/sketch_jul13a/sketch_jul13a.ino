#include <Servo.h>
#include <NewPing.h>

int uv = 2;
int white = 3;
int warning = 4;
int done = 9;

int primary_waiting = 10000;  //10 sec
int cleaning_time = 30000;    //30 sec

Servo door_left, door_right;
NewPing eye(7, 8, 15);  //pingPin = 7, echoPin = 8, max distance measured = 15cm


void setup() {
  door_right.attach(5);
  door_left.attach(6);
  
  Serial.begin(9600);
  
  pinMode(uv, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(warning, OUTPUT);
  pinMode(done, OUTPUT);
}




void loop() {
  
  int distance = eye.ping_cm();
  Serial.println(distance);
  
  if (distance <= 12) {
    digitalWrite(done, LOW);
    digitalWrite(white, HIGH);

    for(int i=90; i<=180; i++) {    //door open
      door_left.write(i);
      door_right.write(i);
    }

    delay(primary_waiting);
    

    for(int i=1; i<=5; i++) {          //1st warning
      digitalWrite(warning, HIGH);
      delay(500);
      digitalWrite(warning, LOW);
      delay(500);

      int distance2 = eye.ping_cm();
      Serial.println(distance2);
      
      if (distance2 <= 6) {
        
        delay(primary_waiting);
        
        for(int i=1; i<=5; i++) {         //2nd warning
          digitalWrite(warning, HIGH);
          delay(500);
          digitalWrite(warning, LOW);
          delay(500);
        }
        break;
      }
    }

    
    for(int i=180; i>=90; i--) {     //door closed
      door_left.write(i);
      door_right.write(i);
    }

    digitalWrite(uv, HIGH);
    delay(cleaning_time);
    digitalWrite(uv, LOW);
    
    digitalWrite(done, HIGH);
  }
}
