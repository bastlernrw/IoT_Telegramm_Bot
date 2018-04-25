# IoT_Telegramm_Bot
IoT Telegramm Bot auf ARDUINO oder ESP8266

du musst erst mal den Bot als Kontakt in [Telegramm](https://telegram.org/) anlegen 

KontaktName: **IoTNotificationBot**

der erste Test beteht dann aus einer Testnachricht an den Bot die folgenden Inhalt enthält

**/start**

IoT Notification Bot:
Hi there!
This bot can send you notifications via Telegram, if you make an http(s)
request. This is usefull for your Internet Of Things devices. All you need
to do is register a new device (/register) and then subscribe it
(/subscribe)
Type /help to see all commands!
Go to http://telegramiotbot.com/ for a full description.

**/register** 

IoT Notification Bot:
Type a name for the new device:

**mein_neuer_bot**

IoT Notification Bot:
Type a notification message for your device mein_neuer_bot:

mein_neuer_bot erste Nachricht

IoT Notification Bot:
Your device 'mein_neuer_bot' has been registered.
Your API-Key is: '*********'
The Notification message is:
' mein_neuer_bot 
erste Nachricht'
https://telegramiotbot.com/api/notify?token=********
Remember, that you need to subscribe first, to get notifications.

Nun deinen Bot anmelden damit du auch die Nachrichten erhältst

**/subscribe mein_neuer_bot**

IoT Notification Bot:
You have subscribed to the device mein_neuer_bot

Wenn nun der richtige Bot Link aufgerufen worden ist sollte die Nachricht 

mein_neuer_bot erste Nachricht

bei dir im Telegramm ankommen

