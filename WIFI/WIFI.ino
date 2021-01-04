#include <Arduino.h>
#include <ESP8266WiFi.h>
void setup() {
Serial.begin(115200);
  Serial.setDebugOutput(true);

WiFi.mode(WIFI_STA);
    WiFi.disconnect(); 


    if (connectWifi("Wi-Fi", "0690862989@Aa09335566750") == WL_CONNECTED) {DEBUG_WM(F("connect wifi with no saved "));}
    else
    {
      DEBUG_WM(F("connect wifi with config value "));
      if (connectWifi(ssid.c_str(), password.c_str()) == WL_CONNECTED) {}
    }
    Serial.print(F("IP Address:"));
    Serial.println(WiFi.localIP());

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
 HX711_Init();
}

void loop() {

}
