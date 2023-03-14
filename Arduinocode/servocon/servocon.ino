#include <Servo.h>
#define Laserpin 7
#define xPin 4
#define yPin 5
int sensorValue1 = 0;
int sensorValue2 = 0;
Servo servo_x;
Servo servo_y;
int angle_xpl;
int angle_ypl;
int angle_x, angle_y, x_data, y_data;
String pyData;
void attach_servo() {
  servo_x.attach(xPin);
  servo_y.attach(yPin);
}
int swsetzero = 13;
int swzerost = 0;

void setup() {

  pinMode(swsetzero, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  pinMode(Laserpin, OUTPUT);
  digitalWrite(6, LOW);

  attach_servo();
  servo_x.write(95);
  servo_y.write(0);
  Serial.begin(2000000);
  Serial.setTimeout(1);
}
void loop() {
  digitalWrite(6, HIGH);
  digitalWrite(Laserpin, HIGH);
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  angle_xpl = sensorValue1 * (0.175953);
  angle_ypl = sensorValue2 * (0.175953);
  servo_y.write(angle_ypl);
  if (Serial.available() > 0) {
    x_data = Serial.readString().toInt();
    angle_x = map(x_data, 0, 640, 90, 140);
    angle_x = angle_x + sensorValue1 * (0.175953);
    servo_x.write(angle_x);
    Serial.flush();
  }
}
