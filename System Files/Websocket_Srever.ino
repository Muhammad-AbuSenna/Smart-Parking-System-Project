#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESP32Servo.h>
#include "webpage.h"
Servo myservo;
//---------------------------------------------------
WebServer server(80);
const char* ssid = "SSID";
const char* password = "Password";
//---------------------------------------------------
#include "handleFunctions.h"
//===================================================
void setup()
{
  Serial.begin(115200);
  //-------------------------------------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while(WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(500); Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //-------------------------------------------------
  myservo.attach(15);
  server.on("/", handleRoot);
  server.on("/readIR", handleIR);
  server.on("/reservSlot", handleSlot);
  server.on("/unreservSlot", unhandleSlot);
  server.begin();
  Serial.println("HTTP server started");
}
//===================================================
void loop(void)
{
  server.handleClient(); delay(1);
}
