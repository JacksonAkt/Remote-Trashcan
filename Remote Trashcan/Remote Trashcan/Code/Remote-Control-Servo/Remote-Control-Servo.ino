#include <Servo.h>
#include <IRremote.hpp>

//define servo
Servo myServo;
const int servoPin = 11;
int recentAngle = 90;

//define remote
#define IR_RECEIVE_PIN 2


void setup() {
  
  //set up servo
  myServo.attach(servoPin);
  myServo.write(recentAngle);

  //set up remote
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

}

void loop() {
   
  if (IrReceiver.decode()) {

    uint16_t cmd = IrReceiver.decodedIRData.command; 

    Serial.print("Command: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    switch (cmd) {
      case 0x19: 
         Serial.println("UP Pressed");
         recentAngle = 0;
         break;
      case 0x2D: 
         Serial.println("RIGHT Pressed");
         recentAngle -= 90; 
         break;
      case 0x1E:
         Serial.println("LEFT Pressed");
         recentAngle += 90;
         break;
      case 0x33:
         Serial.println("DOWN Pressed");
         recentAngle = 90;
         break;
      default: 
         Serial.println("Undetected Button");
         IrReceiver.resume();
         return;
    }
    recentAngle = constrain(recentAngle, 0, 180);

    Serial.print("Servo angle = ");
    Serial.println(recentAngle);

    myServo.write(recentAngle);


    Serial.println("------------------------");
    IrReceiver.resume(); // Receive the next value
  }

   //myServo.write(-90);
   //delay(1000);

}
