/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use ESP8266 Shield via Hardware Serial
 * (on Mega, Leonardo, Micro...) to connect your project to Blynk.
 *
 * Note: Ensure a stable serial connection to ESP8266!
 *       Firmware version 1.0.0 (AT v0.22) or later is needed.
 *       You can change ESP baud rate. Connect to AT console and call:
 *           AT+UART_DEF=115200,8,1,0,0
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************/
#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include "ESP8266_SoftSer.h"
#include "BlynkSimpleShieldEsp8266_SoftSer.h"

// Set ESP8266 Serial object
//#define EspSerial Serial1
// This can be a SoftwareSerial object (remember to also edit ESP8266.h):
#include "SoftwareSerial.h" 
SoftwareSerial EspSerial(3, 2); // RX, TX

ESP8266 wifi(EspSerial);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "8558e07eb7f246d595a2ebdc92a06254";

void setup()
{
  // Set console baud rate
  Serial.begin(115200);
  delay(10);
  // Set ESP8266 baud rate
  EspSerial.begin(115200);
  delay(10);

  Blynk.begin(auth, wifi, "ColgateDeEsta", "escritorio7");
}

void loop()
{
  Blynk.run();
}

