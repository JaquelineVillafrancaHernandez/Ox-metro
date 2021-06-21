#include <Arduino.h>

const byte RED_LED = 25;
const byte INFRA_LED = 26;
const byte SENSOR = 34;
unsigned int intensidad_red;
unsigned int intensidad_infra;

uint16_t led_on_time = 500;
ulong start_time;
byte state;

void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(INFRA_LED, OUTPUT);
  start_time = millis();
  state = 0;
}

void loop()
{
  if (millis() - start_time >= led_on_time)
  {
    start_time = millis();
    switch (state)
    {
    case 0:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(INFRA_LED, LOW);
      intensidad_red = analogRead(SENSOR);
      state = 1;
      break;

    case 1:
      digitalWrite(RED_LED, LOW);
      digitalWrite(INFRA_LED, HIGH);
      intensidad_infra = analogRead(SENSOR);
      Serial.printf("%d,%d\n", intensidad_red,intensidad_infra);
      state = 0;
      break;
    }
  }
}
