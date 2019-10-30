#include<SoftwareSerial.h>
SoftwareSerial Serial1 (1, 0); //Rx=2 Tx=3
#define Up 9
#define Right 8
#define Left 11
#define Down 10
#define Joystick 3
#define Joystick_x A5
#define Joystick_y A6
int Motion_camera = 1;
void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial.println("Author : Thanh Quang Long");
  pinMode(Up, INPUT);
  pinMode(Down, INPUT);
  pinMode(Right, INPUT);
  pinMode(Left, INPUT);
  pinMode(Joystick, INPUT);
  digitalWrite(Up, HIGH);
  digitalWrite(Down, HIGH);
  digitalWrite(Right, HIGH);
  digitalWrite(Left, HIGH);
  digitalWrite(Joystick, HIGH);


}
void loop()
{
  if (digitalRead(Up) == LOW)
  {
   // Serial1.println("1");
    Serial.println(1);
    delay(500);
  }
  else if (digitalRead(Down) == LOW)
  {
    //Serial1.println("2");
    Serial.println(2);
    delay(500);
  }
  else if (digitalRead(Right) == LOW)
  {
    //Serial1.println("3");
    Serial.println(3);
    delay(500);
  }
  else if (digitalRead(Left) == LOW)
  {
   // Serial1.println("4");
    Serial.println(4);
    delay(500);
  }
  else if (digitalRead(Joystick) == LOW)
  {
    Camera();
    delay(500);

  }

}
void Camera()
{ Serial.print("X: ");
  Serial1.println(analogRead(Joystick_x));
  Serial.println(analogRead(Joystick_x));
  Serial.print("Y: ");
  Serial1.println(analogRead(Joystick_y));
  Serial.println(analogRead(Joystick_y));
//  Serial.println(Motion_camera);
  Serial1.println("Camera");

}
