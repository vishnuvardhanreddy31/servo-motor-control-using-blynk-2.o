/*
 * Servo Control using Blynk and ESP8266 (Nodemcu)
 * The project controls the position of a servo motor using Blynk apps. I'm using an SG90 180 degree micro servo. Nodemcu board can drive this servo motor without an additional power supply.
 * 
 * How its work?
 * - Slide the slider widget to the left or right (Minimum value 0 degrees, Maximum Value 180 degrees).
 * - The servo motor will position according to the slider value.
 * 
 * The circuit:
 * - Connect servo motor GND (brown wire), VCC (red wire), and DATA (orange wire) pins to the GROUND, 3V/5V, and D2 (GPIO 4) of the Nodemcu.
 * - Create a datastream (Virtual Pin) and name them SERVO. Select PIN to V0; select Data Type to Int; set MIN 0, MAX 180, Default value 0.
 * - Create slider widgets from the Blynk web dashboard and mobile dashboard. Go to slider settings and select datastream SERVO (V0).
 * 
 * Edgent_ESP8266 & Servo from Blynk <https://github.com/blynkkk/blynk-library/releases/latest>
 * Modified by My Creative Engineering <https://my-creative-engineering.blogspot.com>
 */

// Fill-in information from your Blynk Template here
//#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
//#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_TEMPLATE_ID "TMPL931x484J"
#define BLYNK_DEVICE_NAME "motor"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include <Servo.h>

Servo servo;

BLYNK_WRITE(V0)
{
  servo.write(param.asInt());
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
  servo.attach(4, 500, 2350);//D2
}

void loop() {
  BlynkEdgent.run();
}
