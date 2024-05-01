#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

ESP8266WebServer server(80);

// Initialize heating system
bool heatingOn = false;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP Address: " + WiFi.localIP().toString());

  // Route setup
  server.on("/", handleRoot);
  server.on("/heat", handleHeat);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>Heating System Controller</title></head>";
  html += "<body><h1>Heating System Controller</h1>";
  html += "<p>Current status: ";
  html += (heatingOn ? "On" : "Off");
  html += "</p>";
  html += "<form method='get' action='/heat'><button type='submit'>";
  html += (heatingOn ? "Turn Off" : "Turn On");
  html += " Heating</button></form></body></html>";

  server.send(200, "text/html", html);
}

void handleHeat() {
  heatingOn = !heatingOn;

  String message = "Heating system turned ";
  message += (heatingOn ? "on" : "off");

  server.send(200, "text/plain", message);
}
