# IoT_Telegramm_Bot
IoT Telegramm Bot auf ARDUINO oder ESP8266

du musst erst mal den Bot als Kontakt in [https://telegram.org](https://telegram.org/) anlegen 

KontaktName: **IoTNotificationBot** 

der erste Test beteht dann aus einer Testnachricht an den Bot die folgenden Inhalt enthält

**/start**  <<<---- meine Eingabe bei Telegramm 

IoT Notification Bot:
Hi there!
This bot can send you notifications via Telegram, if you make an http(s)
request. This is usefull for your Internet Of Things devices. All you need
to do is register a new device (/register) and then subscribe it
(/subscribe)
Type /help to see all commands!
Go to http://telegramiotbot.com/ for a full description.

**/register**  <<<---- meine Eingabe bei Telegramm 

IoT Notification Bot:
Type a name for the new device:

**mein_neuer_bot**  <<<---- meine Eingabe bei Telegramm ( Bot Name ) 

IoT Notification Bot:
Type a notification message for your device mein_neuer_bot:

**mein_neuer_bot erste Nachricht** <<<---- meine Eingabe bei Telegramm  ( Bot Meldung ) 

IoT Notification Bot:
Your device 'mein_neuer_bot' has been registered.
Your API-Key is: 'xxxxxxxxx'
The Notification message is:
' mein_neuer_bot 
erste Nachricht'
https://telegramiotbot.com/api/notify?token=xxxxxxxxx
Remember, that you need to subscribe first, to get notifications.

Nun deinen Bot anmelden damit du auch die Nachrichten erhältst

**/subscribe mein_neuer_bot**  <<<---- meine Eingabe bei Telegramm ( meinen Bot für mich anmelden )

IoT Notification Bot:
You have subscribed to the device mein_neuer_bot

Wenn nun der richtige Bot Link aufgerufen worden ist sollte die Nachricht 

mein_neuer_bot erste Nachricht

**bei dir im Telegramm ankommen** ---> meine erste Meldung bei Telegram ;-)

Die Weblinks oben sind nur als Demo zu betrachten 

das ganze klappt auch mit eingenem Text

**https://telegramiotbot.com/api/notify?token=xxxxxxxxxxx&message=hallo_bastlernrw**

Quellcode Version 0.2 main_2018_05_06.c 

mögliche Eingangsbeschaltung für ESP8266 NODEMCU Bot esp8266_bot.JPG
