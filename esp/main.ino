#include <ESPAsyncWebServer.h>

/* Setup IP */
IPAddress apIP(192, 168, 4, 1);

/* Setup DNS */
const uint8_t DNS_PORT = 53;
DNSServer dnsServer;

/* Setup WebServer */
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

/* */
void setup() {

}
