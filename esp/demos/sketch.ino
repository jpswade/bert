// include libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// configure server
ESP8266WebServer server(80);

const char *form = "<center><form action='/'>"
"<button name='dir' type='submit' value='4'>Forward</button><br>"
"<button name='dir' type='submit' value='1'>Left</button>&nbsp;"
"<button name='dir' type='submit' value='2'>Right</button><br>"
"<button name='dir' type='submit' value='3'>Reverse</button><p>"
"<button name='dir' type='submit' value='5'>Stop</button>"
"</form></center>";

void stop(void)
{
    analogWrite(5, 0);
    analogWrite(4, 0);
}

void forward(void)
{
    analogWrite(5, 1023);
    analogWrite(4, 1023);
    digitalWrite(0, HIGH);
    digitalWrite(2, HIGH);
}

void backward(void)
{
    analogWrite(5, 1023);
    analogWrite(4, 1023);
    digitalWrite(0, LOW);
    digitalWrite(2, LOW);
}

void left(void)
{
    analogWrite(5, 1023);
    analogWrite(4, 1023);
    digitalWrite(0, LOW);
    digitalWrite(2, HIGH);
}

void right(void)
{
    analogWrite(5, 1023);
    analogWrite(4, 1023);
    digitalWrite(0, HIGH);
    digitalWrite(2, LOW);
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
            case 1:
                left();
                break;
            case 2:
                right();
                break;
            case 3:
                backward();
                break;
            case 4:
                forward();
                break;
            case 5:
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
    WiFi.begin("Hspace", "3f3ada7d4a");

    // static ip, gateway, netmask
    WiFi.config(IPAddress(192,168,1,2), IPAddress(192,168,1,1), IPAddress(255,255,255,0));

    // connect
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(200);
    }

    // set up the callback for http server
    server.on("/", handle_form);

    // start the webserver
    server.begin();

    pinMode(5, OUTPUT); // 1,2EN aka D1 pwm left
    pinMode(4, OUTPUT); // 3,4EN aka D2 pwm right
    pinMode(0, OUTPUT); // 1A,2A aka D3
    pinMode(2, OUTPUT); // 3A,4A aka D4
}

void loop()
{
    // check for client connections
    server.handleClient();
}
