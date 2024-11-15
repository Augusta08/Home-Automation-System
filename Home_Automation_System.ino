#include <IRremote.h>

#define IR_RECEIVE_PIN 8

#define IR_BUTTON_1 16
#define IR_BUTTON_2 17
#define IR_BUTTON_3 18

#define ledPin 13
#define buzzer 12

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_1:
        {
          Serial.println("Pressed on button 1");
          if (digitalRead(ledPin) == LOW) {
            digitalWrite(ledPin, HIGH);
          } else {
            digitalWrite(ledPin, LOW);
          }
          break;
        }
      case IR_BUTTON_2:
        {
          Serial.println("Pressed on button 2");
          digitalWrite(buzzer, HIGH);
          delay(250);
          digitalWrite(buzzer, LOW);
          break;
        }
      default:
        {
          Serial.println("Button not recognized");
        }
    }
  }
}