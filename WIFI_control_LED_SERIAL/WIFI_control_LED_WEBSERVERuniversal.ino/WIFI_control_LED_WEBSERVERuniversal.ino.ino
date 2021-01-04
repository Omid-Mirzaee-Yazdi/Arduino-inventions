/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;
String serialResponse = "";
char sz[] = "9#1#15#0#3#1#";
int counter=0;
int io[20];
int param[20];

void setup() {

   Serial.begin(115200);
  // Serial.setDebugOutput(true);



  for (uint8_t t = 4; t > 0; t--) {
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Wi-Fi", "0690862989@Aa09335566750");

}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    if (http.begin(client, "http://mirzaee.info/iot/iot.php")) {  // HTTP


      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          serialResponse = payload;
          // Convert from String Object to String
          char buf[sizeof(sz)];
          serialResponse.toCharArray(buf, sizeof(buf));
          char *p = buf;
          char *str;
          
          while ((str = strtok_r(p, "#", &p)) != NULL) // delimiter is the semicolon 
            Serial.println(str);
        }
        
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

  delay(2000);
}
