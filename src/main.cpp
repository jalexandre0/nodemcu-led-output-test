#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include "config.h"

void setup() {
  wdt_enable(8000) ;
  Serial.begin(115200) ;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  ArduinoOTA.onStart([]() {
    //nothing to do on start
  });

  // Restart after Over The Air update.
  ArduinoOTA.onEnd([]() {
    ESP.restart();
  });

  ArduinoOTA.begin();

  //Set digital pins to output
  pinMode(D0, OUTPUT) ;
  pinMode(D1, OUTPUT) ;
  pinMode(D2, OUTPUT) ;
  pinMode(D3, OUTPUT) ;
  pinMode(D4, OUTPUT) ;
  pinMode(D5, OUTPUT) ;
  pinMode(D6, OUTPUT) ;
  pinMode(D7, OUTPUT) ;
  pinMode(D8, OUTPUT) ;
}

void loop() {
  Serial.println("Setting all HIGH") ;
  digitalWrite(D0, HIGH) ;
  digitalWrite(D1, HIGH) ;
  digitalWrite(D2, HIGH) ;
  digitalWrite(D3, HIGH) ;
  digitalWrite(D4, HIGH) ;
  digitalWrite(D5, HIGH) ;
  digitalWrite(D6, HIGH) ;
  digitalWrite(D7, HIGH) ;
  digitalWrite(D8, HIGH) ;
  //delay(5000) ;
  Serial.println("Setting All LOW!") ;
  digitalWrite(D0, LOW) ;
  digitalWrite(D1, LOW) ;
  digitalWrite(D2, LOW) ;
  digitalWrite(D3, LOW) ;
  digitalWrite(D4, LOW) ;
  digitalWrite(D5, LOW) ;
  digitalWrite(D6, LOW) ;
  digitalWrite(D7, LOW) ;
  digitalWrite(D8, LOW) ;
  //delay(5000) ;
  wdt_reset() ;
}
