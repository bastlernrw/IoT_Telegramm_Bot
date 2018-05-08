# Anforderungsliste

-> per default nach WLAN AP suchen wenn nach 10 Sekunden keiner gefunden in den AP Modus wechseln. Eventuell über Jumper blockieren Alarmkontakt wenn kein AP gefunden.

-> Ausgabe der ersten Statusmeldung per Bot "System Online"

 -> Polling per „Software Ping“ alle 5 Minuten ob Server noch erreichbar ist. Alarmmeldung

-> Abruf von mehr Eingängen. Umbau auf Serielles Einlesen der Eingänge ( 4021 ) ?

Serielle Ausgabe der Anzeige Ausgänge LED ( 74HC595 ) ?

-> Abfragen in Funktionen packen 

# Funktionaufrufe als Überblick ( #include <ESP8266WiFi.h> )


       WiFi.hostname("tinkerfux_bot");                         // DNS Hostname setzen  ( tinkerfux Bot )
       WiFi.begin(ssid, password);                            // Login Username PWD   
       Serial.println("");                                       
       while (WiFi.status() != WL_CONNECTED)                  // Abfrage WLAN aktibe sonst "."
        {
          Serial.print(".");
          delay(500);
        }
        //-------------------------------------------------------------------------------------------------
        // Status message wifi login
        //-------------------------------------------------------------------------------------------------
        Serial.println(" ");
        Serial.println("Wireless network connection established.");

        Serial.print("SSID: ");                         
        Serial.println(ssid);                               // Ausgabe der WLAN SSID  

        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());                    // Ausgabe der Host IP   

        Serial.print("Subnet mask: ");
        Serial.println(WiFi.subnetMask());                 // Ausgabe der Host Subnetzmaske    

        Serial.print("Gateway IP: ");
        Serial.println(WiFi.gatewayIP());                 // Ausgabe der Host Gateway Adresse      

        Serial.print("DNS #1, #2 IP: ");                  // Ausgabe der Host DNS Adressen      
        WiFi.dnsIP().printTo(Serial);
        Serial.print(", ");
        WiFi.dnsIP(1).printTo(Serial);
        Serial.println();

      if (WiFi.status() == WL_CONNECTED)                  // Ausgabe der Host MAC Adresse      
          {
            uint8_t macAddr[6];
            WiFi.macAddress(macAddr);
            Serial.printf("Connected, mac address: %02x:%02x:%02x:%02x:%02x:%02x\n", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
          }




