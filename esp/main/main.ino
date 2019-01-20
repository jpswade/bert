// Main Wifi Car Application.
// @see https://github.com/squix78/esp8266-projects/blob/master/arduino-ide/wifi-car/wifi-car.ino
// @see https://github.com/flannelhead/espway/blob/arduino/espway-arduino/espway-arduino.ino

// Includes.
#include <ESPAsyncWebServer.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoOTA.h>
#include <DNSServer.h>

// Assign Arduino Friendly Names to GPIO pins.
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13

// Assign friendly names for motor pins.
#define PWMA 5
#define DIRA 0
#define PWMB 4
#define DIRB 2

// Speed.
#define PWMLOW 1024
#define PWMHIGH 1
int Speed = 800;
int TSpeed = 1023;

// The port to listen for incoming TCP connections
#define LISTEN_PORT 80

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

// WiFi parameters.
const char* ssid = "bert";
const char* password = "";

/* Setup IP */
IPAddress apIP(192, 168, 4, 1);

/* Setup DNS */
const uint8_t DNS_PORT = 53;
DNSServer dnsServer;

/* Setup WebSocket */
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

// put your setup code here, to run once:
void setup() {

  // Connect the WiFi.
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());

  // Motor A.
  Serial.begin(115200);
  Serial.println("Preparing motor A...");
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  analogWrite(PWMA, LOW);
  digitalWrite(DIRA, LOW);

  // Motor B.
  Serial.println("Preparing motor B...");
  pinMode(DIRB, OUTPUT);
  pinMode(PWMB, OUTPUT);
  analogWrite(PWMB, LOW);
  digitalWrite(DIRB, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Motor test");
  analogWrite(PWMA,LOW);
  digitalWrite(DIRA,HIGH);
  delay(1000);

  Serial.println("Starting motor...");
  Serial.println("Speed: 500");
  analogWrite(PWMA, PWMHIGH);
  delay(1000);

  Serial.println("End.");
}
