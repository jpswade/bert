// motor web - a simple concept to drive motors from a web form

// include libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "FS.h"

#define WIFI_SSID "Hspace"
#define WIFI_PASS "3f3ada7d4a"

// definitions
#define PWMA 5 // 1,2EN aka D1 pwm left
#define DIRA 0 // 1A,2A aka D3
#define PWMB 4 // 3,4EN aka D2 pwm right
#define DIRB 2 // 3A,4A aka D4

#define STOP 0
#define SPEEDHIGH 1023

#define FORWARD 1
#define LEFT 2
#define RIGHT 3
#define BACKWARD 4

// configure server
ESP8266WebServer server(80);

String form = "";

void stop(void)
{
    analogWrite(PWMA, STOP);
    analogWrite(PWMB, STOP);
}

void forward(void)
{
    analogWrite(PWMA, SPEEDHIGH);
    analogWrite(PWMB, SPEEDHIGH);
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, HIGH);
}

void backward(void)
{
    analogWrite(PWMA, SPEEDHIGH);
    analogWrite(PWMB, SPEEDHIGH);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, LOW);
}

void left(void)
{
    analogWrite(PWMA, SPEEDHIGH);
    analogWrite(PWMB, SPEEDHIGH);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
}

void right(void)
{
    analogWrite(PWMA, SPEEDHIGH);
    analogWrite(PWMB, SPEEDHIGH);
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
}

void displayFile(){

  Serial.println("Prepare file system");
  bool result = SPIFFS.begin();
  Serial.println("SPIFFS opened: " + result);

  File file = SPIFFS.open("/form.html", "r");
  if (file) {
    Serial.println("file open success");

    while (file.available()) {
      String line = file.readStringUntil('\n');
      form += line + "\n";
    }
    file.close();
  } else {
    Serial.println("file open failed");
  }
}

void handle_form()
{
    // only move if we submitted the form
    if (server.arg("dir"))
    {
        // get the value of request argument "dir"
        int direction = server.arg("dir").toInt();

        // chose direction
        switch (direction)
        {
            case LEFT:
                left();
                break;
            case RIGHT:
                right();
                break;
            case BACKWARD:
                backward();
                break;
            case FORWARD:
                forward();
                break;
            case STOP:
                stop();
                break;
        }

        // move for 300ms, gives chip time to update wifi also
        delay(300);
    }

    // in all cases send the response
    server.send(200, "text/html", form);
}

void setup()
{
    // connect to wifi network
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // static ip, gateway, netmask
    //WiFi.config(IPAddress(192,168,1,2), IPAddress(192,168,1,1), IPAddress(255,255,255,0));

    // connect
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(200);
    }

    // set up the callback for http server
    server.on("/", handle_form);

    // start the webserver
    server.begin();

    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(DIRA, OUTPUT);
    pinMode(DIRB, OUTPUT);
}

void loop()
{
    // check for client connections
    server.handleClient();
}
