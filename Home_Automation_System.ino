#include <IRremote.h>

#define IR_RECEIVE_PIN 8

#define IR_BUTTON_1 22
#define IR_BUTTON_2 25
#define IR_BUTTON_3 13
#define IR_BUTTON_4 12
#define IR_BUTTON_5 24

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
    delay(100);
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_1: {
        Serial.println("Pressed on button 1");
        if (digitalRead(ledPin) == LOW) {
          digitalWrite(ledPin, HIGH);
        } else {
          digitalWrite(ledPin, LOW);
        }
        break;
      }
      case IR_BUTTON_2: {
        Serial.println("Pressed on button 2");
        digitalWrite(buzzer, HIGH);
        delay(250);
        digitalWrite(buzzer, LOW);
        break;
      }
      case IR_BUTTON_3: {
        Serial.println("Pressed on button 3");
        break;
      }
      case IR_BUTTON_4: {
        Serial.println("Pressed on button play/pause");
        break;
      }
      default: {
        Serial.println("Button not recognized");
      }
    }
  }
}