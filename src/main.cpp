#include <Arduino.h>

int LED_BUILTIN = 23;
int DELAY = 500;
int count = 0;

void IRAM_ATTR isr() {
  Serial.println("Interrupted");
  count = 0;
}

void setup() {
  pinMode (LED_BUILTIN, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(LED_BUILTIN, isr, FALLING);
}

void loop () {
for (count; count < 1000; count++){
  Serial.println(count);
  delay(DELAY);
}
}

