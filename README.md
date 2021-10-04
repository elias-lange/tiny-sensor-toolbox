[![License](https://img.shields.io/badge/license-Apache%202-blue.svg)](LICENSE)

# Tiny-Sensor-Toolbox

Dieses Repository enthält eine kleine Toolbox zur Programmierung von IoT-Sensoren mit Mikrocontrollern (insbesondere dem ESP32) mit der Arduino IDE. Es bietet Funktionen zum Auslesen der Messwerte verschiedener Messfühler/Sensorelemente und zur Übertragung an entfernte Dienste bzw. über einschlägige Protokolle. Außerdem bietet die Toolbox einen einfachen aber erweiterbaren Logging-Mechanismus.

* [AbstractSensor-Klasse](#abstractsensor-klasse)
* [Unterstützte Messfühler/Sensorelemente](#unterstützte-messfühlersensorelemente)

## AbstractSensor-Klasse

Die Klasse [`AbstractSensor`](src/sensor/AbstractSensor.h) definiert eine einheitliche Schnittstelle zum Auslesen der Messfühler/Sensorelemente:

* `void setup()` sollte einmal, zur Initialisierung aufgerufen werden.
* `void loop()` sollte regelmäßig, mindestens vor dem Auslesen des aktuellen Messwerts, aufgerufen werden und triggert je nach Messprinzip eine Messung.
* `boolean hasNewData()` gibt an, ob ein neuer Messwert vorliegt.
* `T& getData(bool resetNewDataFlag = true):` Diese Funktion liefert den neuesten verfügbaren Messwert zurück.

Zur Implementierung eigener Klassen zum Auslesen von Messfühlern/Sensorelementen müssen mindestens die ersten beiden Funktionen implementiert werden.

## Unterstützte Messfühler/Sensorelemente

Aktuell unterstützt die Tiny-Sensor-Toolbox folgende Messfühler/Sensorelemente. In Klammern ist der Datentyp des Messwerts angegeben.:

* **DS18B20Sensor.h (float):** Der Temperaturfühler DS18B20 von Maxim Integrated Products, Inc.
* **LevelSensor.h (int):** Prüft an einer gegebenen Sequenz von Pins _P0_, _P1_, ..., _Pn_, an welcher Teilsequenz _P0_ bis _Pm_ eine einstellbare Mindestspannung liegt und gibt die Anzahl _m+1_ als Messwert zurück. Mit einer Kaskade schaltender Sensoren (z.B. unterschiedlich lange Drähte in einer Flüssigkeit) kann so ein Füllstandsmesser o.ä. gebaut werden.
* **SignalEdgeSensor.h (int)** Zählt Ereignisse (Signalflanken) an einem Pin per Interrupt und liefert die Rate (Ereignisse pro Sekunde) zurück. Das Messintervall kann beliebig eingestellt werden.
* **VoltageSensor (float)** Liest einen analogen Spannungswert an einem gegebenen Pin mit `analogRead(..)` aus, liefert aber eine Gleitkommazahl statt einer ganzzahligen Repräsentation. Der Spannungsbereich und der Bereich der ganzzahligen Repräsentation wird im Konstruktor eingestellt.

## Unterstützte Dienste/Protokolle

Aktuell wird nur ein Dienst unterstützt:

* **ThingSpeakSender.h:** Sendet einen Messwert über ein angegebenens WLAN an den IoT-Analytics-Dienst (ThingSpeak)[https://thingspeak.com/]. Die WLAN-Verbindung wird für jede Übertragung neu aufgebaut.

## Weitere Funktionen:

* **AbstractLogger.h** definiert ein Makro `LOG(..)` zum Logging im printf-Stil. **SerialLogger.h** implementiert die Übertragung der Logging-Daten per `Serial`.
* **PeriodicTimer.h** erlaubt die Realisierung periodischer Timer, z.B. zum periodischen Auslesen eines Messfühlers/Sensorelements.