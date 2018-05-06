#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
//----------------------------------------------------------------------------------------------------------------------------
const int inputPin_1 = 5 ; // define Input Port
int inputPin_1_state = LOW ;
int inputPin_1_read = 0 ;
//----------------------------------------------------------------------------------------------------------------------------
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
void WiFi_println_bot_on()
  {
      HTTPClient http;
      String url = SERVER_URL;
      url += STATUS_TOKEN ;
      url += "Tinkerbot%20message%20on";
      http.begin(url);
      // Serial.print("[HTTP] GET...http://telegramiotbot.com");
      int httpCode = http.GET();
      if(httpCode)
        {
          Serial.printf(" Retour code: on %d\n", httpCode);
        } else{
          Serial.print("... failed, no connection or no HTTP server\n");
        }
    }
//----------------------------------------------------------------------------------------------------------------------------
void WiFi_println_bot_off()
     {
         HTTPClient http;
         String url = SERVER_URL;
         url += STATUS_TOKEN ;
         url += "Tinkerbot%20message%20off";
         http.begin(url);
         // Serial.print("[HTTP] GET...http://telegramiotbot.com");
         int httpCode = http.GET();
         if(httpCode)
           {
             Serial.printf(" Retour code Off : %d\n", httpCode);
           } else {
             Serial.print("... failed, no connection or no HTTP server\n");
           }
       }
//----------------------------------------------------------------------------------------------------------------------------
void loop()
{
  // read the state of the pushbutton value:
     inputPin_1_read = digitalRead(inputPin_1);
     // check if the pushbutton is pressed.
     // if it is, the buttonState is HIGH:
     if (inputPin_1_read == HIGH) { //Check if Button was pressed before and being pressed now
       if (inputPin_1_state == LOW)
       {
         // turn LED on:
         //Serial.print("LED ON \n");
          WiFi_println_bot_on();
         inputPin_1_state = HIGH;
       }
     }
     else {
       if (inputPin_1_state == HIGH) {
         //Serial.print("LED OFF \n");
         WiFi_println_bot_off();
         inputPin_1_state = LOW;
       }
     }
}
