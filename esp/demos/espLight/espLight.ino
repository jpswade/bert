#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <ArduinoOTA.h>
#include <Ticker.h>
#include <PubSubClient.h>

// Settings.
int ledPin = 4; // GPIO2=4
const char* mqttServer = "broker.mqtt-dashboard.com";
const int mqttPort = 1883;
const char* mqttInTopic = "PotteriesHackspace";
String clientString = "ESP8266Client-" + String(ESP.getChipId());
const char* clientId = clientString.c_str();

// Variables.
int ledOn = HIGH;
int ledOff = LOW;

// For LED status.
Ticker ticker;

// HTTP Server.
WiFiServer server(80);

// MQTT Server.
WiFiClient espClient;
PubSubClient mqtt(espClient);

void tick()
{
  // Toggle state.
  int state = digitalRead(ledPin);  // get the current state of GPIO1 pin
  digitalWrite(ledPin, !state);     // set pin to the opposite state
}

void httpHandler() {
  // Check if a client has connected.
  WiFiClient http = server.available();
  if (!http) {
    return;
  }

  http.setTimeout(600); // default is 1000

  // Read the first line of the request.
  String request = http.readStringUntil('\r');
  Serial.println(request);
  http.flush();

  // Match the request.
  int state = digitalRead(ledPin);
  if (request.indexOf("/on") != -1) {
    state = ledOn;
  }
  if (request.indexOf("/off") != -1) {
    state = ledOff;
  }

  // Set ledPin according to the request.
  digitalWrite(ledPin, state);

  // Return the response.
  http.println("HTTP/1.1 200 OK");
  http.println("Content-Type: text/html");
  http.println(""); //  do not forget this one.
  http.println("<!DOCTYPE HTML>");
  http.println("<html>");
  if (state == ledOn) {
    http.println("<p><a href=\"/off\">off</a></p>");
  } else {
    http.println("<p><a href=\"/on\">on</a></p>");
  }
  http.println("</html>");
}

void mqttConnect() {
  // Loop until we're reconnected.
  while (!mqtt.connected()) {
    Serial.print(">>> Attempting MQTT connection...");
    // Attempt to connect.
    if (mqtt.connect(clientId)) {
      Serial.println(">>> MQTT Connected");
      mqttSubscribe();
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqtt.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying.
      delay(5000);
    }
  }
}

void mqttSubscribe() {
  mqtt.setCallback(mqttCallback);
  if (mqtt.subscribe(mqttInTopic)) {
    Serial.println(">>> Subscribed to: " + String(mqttInTopic));
  } else {
    Serial.println(">>> Failed to subscribe to: " + String(mqttInTopic));
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print(">>> Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(ledPin, ledOn);
  } else {
    digitalWrite(ledPin, ledOff);
  }

}

void mqttSetup() {
  mqtt.setServer(mqttServer, mqttPort);
  mqttConnect();
  
}

void mqttHandler() {
if (!mqtt.connected()) {
    mqttConnect();
  }
  mqtt.loop();
}

void setup() {
  // Setup serial.
  Serial.begin(9600);
  Serial.println(">>> Serial started.");

  // Setup LED.
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledOn);
  Serial.println(">>> LED setup.");

  // Setup ticker.
  ticker.attach(1, tick);
  Serial.println(">>> Ticker started.");

  // Setup wifi.
  WiFiManager wifiManager;
  wifiManager.autoConnect();
  Serial.println(">>> WiFi connected.");

  // Print the IP address.
  Serial.print(">>> Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  // Setup OTA.
  ArduinoOTA.begin();
  Serial.println(">>> OTA started.");

  // Start the server.
  server.begin();
  Serial.println(">>> Server started.");

  // LED reset.
  ticker.detach();
  digitalWrite(ledPin, ledOff);
  Serial.println(">>> LED reset.");

  // MQTT.
  mqttSetup();
}

void loop() {
  ArduinoOTA.handle();
  httpHandler();
  mqttHandler();
  yield();
}
