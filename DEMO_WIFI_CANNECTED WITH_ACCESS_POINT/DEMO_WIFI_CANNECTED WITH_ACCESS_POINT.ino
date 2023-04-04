#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define light D5

void setup() 
{
    Serial.begin(4800);
    WiFi.softAP("IOT_ESP","123456789"); 
    Serial.println();
    Serial.println("NodeMCU is STARTED...");
    Serial.println(WiFi.softAPIP());
   
    server.begin();
    pinMode(light,OUTPUT);
    
}

void loop() 
{
    client = server.available();
    if(client == 1)
    {
        String req = client.readStringUntil('\n');
        Serial.println(req);
        req.trim();
        if(req == "GET /lighton HTTP/1.1")
        {
            digitalWrite(light,HIGH);
        }
        if(req == "GET /lightoff HTTP/1.1")
        {
            digitalWrite(light,LOW);
        }
    }
    client.println("HTTP/1.1 200 OK"); //
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE html>");
    client.println("<html>");
         client.println("<h1><center>WEL_COME TO THE E&TC CLASS ROOM...!(Third Year)</center></h1>");
         client.println("<br>");
         client.println("<a href = \"/lighton\"\"><button>LIGHT ON </button></a>");
         client.println("<a href = \"/lightoff\"\"><button>LIGHT OFF </button></a>");
         
         client.println("<a href = \"/fanon\"\"><button>FAN ON </button></a>");
         client.println("<a href = \"/fanoff\"\"><button>FAN OFF </button></a>");
         client.println("</br>");
    client.println("</html>");

    
    
    
    

}