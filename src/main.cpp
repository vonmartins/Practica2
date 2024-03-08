#include <Arduino.h>

#define DELAY  500;

const uint8_t BUTTON1_PIN = 8;
const uint8_t BUTTON2_PIN = 18;
const uint8_t LED_PIN = 15;


uint32_t count = 0;

struct Button{
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool buttonState;
  bool pressed;
};

Button button1 = {BUTTON1_PIN, 0, false, false};
Button button2 = {BUTTON2_PIN, 0, false, false};

void IRAM_ATTR isr() {
  Serial.println("Interrupted by button 2");
  count = 0;
}

void setup(){
  Serial.begin(9600);
  pinMode(button1.PIN, INPUT_PULLUP);
  pinMode(button2.PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(button2.PIN, isr, FALLING);
}

void loop(){

  button1.buttonState=digitalRead(button1.PIN);

  if (button1.buttonState == LOW && !button1.pressed) {
    count++;
    button1.pressed = true;
    Serial.print("Contador: ");
    Serial.println(count);
    digitalWrite(LED_PIN, HIGH);
    delay(50);

  }
  if (button1.buttonState == HIGH && button1.pressed) {
    digitalWrite(LED_PIN, LOW);
    button1.pressed = false;
    delay(50);
  }
}