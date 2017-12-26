// include libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define WIFI_SSID "Hspace"
#define WIFI_PASS "3f3ada7d4a"

// definitions
#define PWMA 5 // 1,2EN aka D1 pwm left
#define DIRA 0 // 1A,2A aka D3
#define PWMB 4 // 3,4EN aka D2 pwm right
#define DIRB 2 // 3A,4A aka D4

#define PWMA D1
#define PWMB D2
#define DIRA D3
#define DIRB D4

#define STOP 0
#define SPEEDHIGH 1024

#define FORWARD 1
#define LEFT 2
#define RIGHT 3
#define BACKWARD 4

// configure server
ESP8266WebServer server(80);
 
const char *form = "<center><form action='/'>"
"<button name='dir' type='submit' value='1'>Forward</button><br>"
"<button name='dir' type='submit' value='2'>Left</button>&nbsp;"
"<button name='dir' type='submit' value='3'>Right</button><br>"
"<button name='dir' type='submit' value='4'>Backward</button><p>"
"<button name='dir' type='submit' value='0'>Stop</button>"
"</form></center>";
 
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
