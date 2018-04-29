#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


const int message_1 = 2 ;
int message_1_state = 0 ;

const char * ssid = "********";                                 // Wifi SSID
const char * password = "********";                      		// Wifif password

#define SERVER_URL "http://telegramiotbot.com/api/notify?token=";     // Telegram Bot url
#define MSG_TOKEN "********";                           // Token code message
#define STATUS_TOKEN "********";                        // Token code Status
void setup()
  {
  // initialize serial port for debugging purpose:
  Serial.begin(115200);

  pinMode(message_1, INPUT);

  // connect to the wireless network:
  WiFi.begin(ssid, password);
  Serial.println("");
    while (WiFi.status() != WL_CONNECTED)
        {
          Serial.print(".");
          delay(500);
        }
        //----------------------------------------------------------------------------------------------------------------------------
        // Status message wifi login
        //----------------------------------------------------------------------------------------------------------------------------
        Serial.println(" ");
        Serial.println("Wireless network connection established.");
        Serial.print("SSID: ");
        Serial.println(ssid);
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        //----------------------------------------------------------------------------------------------------------------------------
        // Status message online
        //----------------------------------------------------------------------------------------------------------------------------
        HTTPClient http;
        String url = SERVER_URL;
        url += MSG_TOKEN ;
        url += "Tinkerbot%20online";
        http.begin(url);
        Serial.print("[HTTP] GET...http://telegramiotbot.com");
        int httpCode = http.GET();
        if(httpCode)
          {
            Serial.printf(" Retour code: %d\n", httpCode);
          } else{
            Serial.print("... failed, no connection or no HTTP server\n");
          }
      }
//----------------------------------------------------------------------------------------------------------------------------
 void WiFi_println_bot()
  {
      HTTPClient http;
      String url = SERVER_URL;
      url += MSG_TOKEN ;
      url += "Tinkerbot%20message";
      http.begin(url);
      Serial.print("[HTTP] GET...http://telegramiotbot.com");
      int httpCode = http.GET();
      if(httpCode)
        {
          Serial.printf(" Retour code: %d\n", httpCode);
        } else{
          Serial.print("... failed, no connection or no HTTP server\n");
        }
    }
//----------------------------------------------------------------------------------------------------------------------------

void loop()
{
// noch one funktionen 
}
