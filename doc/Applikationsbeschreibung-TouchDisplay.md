<!-- DOC -->
# Touch Display

Über den Abschnitt Touch Round werden die Anzeige und die Seiten definiert.

Das Konfigurationskonzept sieht vor, dass im Abschnitt [Geräte](https://github.com/OpenKNX/OFM-SmartHomeBridge/tree/v1/doc/Applikationsbeschreibung-Geräte.md) zuerst die im KNX-System vorhandenen Geräte mit den entsprechenden Gruppenadressen verknüpft werden.

In diesem Abschnitt wird das Layout der Seiten definiert und bei Bedarf die Verknüpfungen zur Gerätedefinition vorgenommen. 
Durch die Trennung von Geräte- und Seitenkonfiguration kann das Layout und die Seitenreihenfolge leicht angepasst werden, ohne aufwendige Gruppenverknüpfungen erneut vorzunehmen.

## Allgemein

In diesem Abschnitt werden globale, für das Display notwendige Einstellungen vorgenommen.

<!-- DOCEND -->
### Geräteeinstellungen

<!-- DOC -->
#### Anzeige drehen

Diese Einstellung dient dazu, bei der Einbaurichtung des Displays flexibel zu sein.
Die Anzeige kann über folgende Optionen gedreht werden:

- Nein
- 90°
- 180° 
- 270°

<!-- DOC HelpContext="Sensor-Tasten" -->
#### Sensor-Tasten vorhanden

Über diese Einstellung muss festgelegt werden, ob bei der Hardware zwei Touch-Sensorflächen angeschlossen sind.

- Nein
- Ja  
  Die Tasten werden zum Blättern der Seiten verwendet.

<!-- DOC -->
#### Links-Rechts tauschen

Die Einstellung ist nur vorhanden, wenn Sensor-Tasten vorhanden sind.
Die Konfiguration erlaubt das Tauschen der Tasten.
Dies kann z. B. benutzt werden, um die Tasten oberhalb des Displays zu verwenden, anstatt wie normal vorgesehen auf der Unterseite. 
Dazu muss das Display um 180° gedreht verbaut werden, die Einstellung [Anzeige drehen](#anzeige-drehen) ebenfalls auf 180° eingestellt werden und diese Einstellung auf Ja gesetzt werden.

<!-- DOC -->
#### Seitenwechsel über Wischen im unteren Bereich

Ist diese Einstellung auf Ja gesetzt, kann im unteren Bildschirmbereich (etwa in der Position, wo der Seitenname angezeigt wird) durch Wischen nach rechts die Seite vor, bzw. durch Wischen nach links zurück geblättert werden.

<!-- DOCEND -->
### Basiseinstellungen

<!-- DOC -->
#### Anzeige ausschalten nach

Nach der konfigurierten Zeit, in der keine Bedienung erfolgt, schaltet sich die Anzeige aus. 
Wird 0 eingestellt, erfolgt keine automatische Abschaltung.

Das Einschalten des Displays erfolgt durch Berührung der Anzeige oder einer der angeschlossenen Sensortasten.

Wichtig: Bei Verwendung des Touch Round Displays – wird die Hintergrundbeleuchtung des Displays nicht abgeschaltet, ist die Hardware falsch konfiguriert.
In diesem Fall muss der DIP-Schalter 2 auf der Rückseite der Display-Platine umgeschaltet werden.

<!-- DOC -->
##### Anzeige aus nach Zeit

Gibt die Zeit an, die gewartet wird, bis nach der letzten Bedienung das Display abgeschaltet wird. 

<!-- DOC -->
##### Anzeige aus nach Zeitbasis

- Sekunde(n)
- Minute(n)
- Stunde(n)

<!-- DOC -->
#### Objekt 'Gehe zu Seite' schaltet Anzeige ein

Wenn über 'Gehe zu Seite' eine Seite gewählt wird, wird die Anzeige eingeschalten

<!-- DOC -->
#### Standardseite 

Gibt die Seite an, die angezeigt wird, wenn das Display die Busspannung bekommt. 
Weiters kann ein automatischer Rückfall auf die Standardseite konfiguriert werden.

Achtung: Die hier eingestellte Standardseite kann auch über ein Gruppenobjekt überladen werden. Siehe dazu die Einstellung [Rückfall auf Standardseite](#rückfall-auf-standardseite).


<!-- DOC -->
#### Rückfall auf Standardseite 

Nach der konfigurierten Zeit, in der keine Bedienung erfolgt, schaltet sich die Anzeige aus. 
Wird 0 eingestellt, erfolgt keine automatische Abschaltung.

<!-- DOC -->
##### Standardseite nach Zeit 

Zeit, nach der – wenn keine Bedienung stattfindet – auf die Standardseite gewechselt wird.

<!-- DOC -->
##### Standardseite nach Zeitbasis 

- Sekunde(n)
- Minute(n)
- Stunde(n)

<!-- DOC -->
#### Gruppenobjekt für Standardseitenauswahl

Blendet ein Gruppenobjekt ein, über das die Standardseite vom KNX-Bus vorgegeben werden kann.
Als Typ wird der Szenen-Typ (DPT 17.001) verwendet.
Die Szenennummer entspricht der Seite.
Die Szene 1 (RAW-Wert 0) wählt somit die Seite 1 als Standardobjekt aus.

<!-- DOC -->
#### Objekt 'Standardseite' schaltet Anzeige ein

Wenn über 'Standardseite' eine Standard-Seite gesetzt wird, wird die Anzeige eingeschalten


<!-- DOCEND -->
### Anzeigemodus

<!-- DOC -->
#### Bei Nacht anders

Diese Einstellung ermöglicht, dass der Stil und die Farbeinstellungen für Tag und Nacht getrennt eingestellt werden können.

- Deaktiviert  
  Für Tag und Nacht werden dieselben Einstellungen benutzt.
- Umschaltobjekt Nacht EIN  
  Es wird ein Gruppenobjekt zur Verfügung gestellt, bei dem EIN für die Auswahl der Nachteinstellung anliegen muss.
- Umschaltobjekt Tag EIN  
  Es wird ein Gruppenobjekt zur Verfügung gestellt, bei dem EIN für die Auswahl der Tageseinstellung anliegen muss.

<!-- DOC -->
#### Stil 

Gibt den generellen Anzeigestil vor, der die Hintergrundfarbe und Basiselemente betrifft.

- Hell  
  Der Hintergrund wird weiß dargestellt, Standardtexte schwarz.
- Dunkel  
  Der Hintergrund wird grau dargestellt, Standardtexte sind weiß.
- Schwarz  
  Der Hintergrund wird schwarz dargestellt, Standardtexte sind weiß.

<!-- DOC -->
#### Farbe Bedienelemente

Wählt die Farbe für Steuerbedienelemente im aktiven Zustand (z. B. der aktive Teil eines Sliders).

- Rot
- Pink
- Lila
- Dunkel Lila
- Indigo
- Blau
- Hellblau
- Cyan
- Türkis
- Grün
- Hellgrün
- Limette
- Gelb
- Orangegelb
- Orange
- Dunkel Orange
- Braun
- Blau-Grau
- Grau

<!-- DOC -->
#### Farbe Bild EIN

Farbe, die für die Bildeinfärbung im Zustand EIN verwendet wird.

- Rot
- Pink
- Lila
- Dunkel Lila
- Indigo
- Blau
- Hellblau
- Cyan
- Türkis
- Grün
- Hellgrün
- Limette
- Gelb
- Orangegelb
- Orange
- Dunkel Orange
- Braun
- Blau-Grau
- Grau

<!-- DOC -->
## Seiten 

In diesem Abschnitt werden die Seitenanzahl und Seitentypen eingestellt.

<!-- DOC -->
### Verfügbare Seiten

Anzahl der Seiten, die in der Konfiguration zur Verfügung stehen.

<!-- DOC HelpContext="MovePageButtons" -->
### Seitenreihenfolge anpassen

Über die Tasten kann die Reihenfolge der Seiten angepasst werden.

<!-- DOC -->
## Beschreibung

Beschreibung der Seite, die in der ETS verwendet werden soll. 
Die Beschreibung wird am Display nicht angezeigt.
Sie dient zur Erleichterung und Übersichtlichkeit der Konfiguration.

<!-- DOC -->
## Seitentyp

Hier kann man zwischen verschiedenen Seitenarten wählen.

- Deaktiviert  
  Die Seite ist deaktiviert und wird beim Blättern nicht angesprungen. 
  Wird die Seite über direkte Auswahl durch ein Kommunikationsobjekt oder als Sprungziel angewählt, wird im Display angezeigt, dass die Seite deaktiviert ist.
- [Gerät](#seitentype-gerät)  
  Ein Gerät aus der Geräteliste wird auf der Seite dargestellt.
  Dabei gibt es die Auswahl, ob eine Standardvisualisierung (Hauptfunktion) verwendet werden soll, die für jedes Gerät gleich aussieht mit gerätetypabhängigem Symbol, oder eine Spezialseite, die mehr Gerätefunktionen für die Steuerung bereitstellt.
  Achtung: Bei manchen einfachen Geräten gibt es in der Visualisierung keinen Unterschied zwischen Standard und Hauptfunktion.
- [Mehrere Felder](#seitentype-mehrere-felder)  
  Die Seite wird auf mehrere Felder aufgeteilt, die jeweils unterschiedlich konfiguriert werden können.
  Jedes Feld kann ein Gerät steuern, als Absprung auf eine andere Seite dienen oder Spezialseiten wie z. B. die Uhrzeit darstellen.
- Zeit / Datum  
  Seite für die aktuelle Uhrzeit und das Datum. 
- System  
  Systemseite mit technischen Informationen und KNX-Programmiertaster.

<!-- DOCEND -->
## Seitendefinition

Neben der [Beschreibung](#beschreibung) und der [Seitentyp](#seitentyp)-Auswahl stehen folgende Einstellungen zur Verfügung:

<!-- DOC -->
### Navigationsleiste 

Gibt an, ob und wo eine Navigationsleiste eingeblendet werden soll.

- Deaktivert
- Links
- Rechts
- Oben
- Unten

<!-- DOCEND -->
Diese Option ist nicht bei allen Geräten verfügbar.

<!-- DOC -->
### Seite über Blättern erreichbar

Gibt an, ob die Seite über Blättern erreicht werden kann.
Wird Nein angewählt, kann die Seite trotzdem über das Kommunikationsobjekt "Gehe zu Seite" oder über den Absprung eines Display-Feldes bei dem Seitentyp "Mehrere Felder" angezeigt werden.

<!-- DOCEND -->
Diese Option ist nicht bei allen Geräten verfügbar.

<!-- DOC -->
### Seitenfreigabe über Objekt

Das Display stellt 8 Sperrobjekte zur Verfügung.
Diese dienen dazu, Seiten zu sperren und damit beim Blättern auszulassen.
Ein Sperrobjekt kann beliebig viele Seiten gleichzeitig sperren.
Beispielsweise kann es sinnvoll sein, alle Seiten, die für die Heizungssteuerung dienen, im Sommer auszublenden.

- Deaktiviert  
  Die Seite wird nicht durch ein Kommunikationsobjekt gesperrt.
- Seitenfreigabe A  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe A" gesperrt.
- Seitenfreigabe B  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe B" gesperrt.
- Seitenfreigabe C  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe C" gesperrt.
- Seitenfreigabe D  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe D" gesperrt.
- Seitenfreigabe E  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe E" gesperrt.
- Seitenfreigabe F  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe F" gesperrt.
- Seitenfreigabe G  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe G" gesperrt.
- Seitenfreigabe H  
  Die Seite wird durch das Kommunikationsobjekt "Seitenfreigabe H" gesperrt.

<!-- DOC -->
#### Freigabe bei

- EIN - 1 
  Wenn am Freigabe-Kommunikationsobjekt 1 anliegt, ist die Seite verfügbar
- AUS - 0 (Invertiert)
  Wenn am Freigabe-Kommunikationsobjekt 0 anliegt, ist die Seite verfügbar

<!-- DOC -->
## Seitentyp "Gerät"

Ein Gerät aus der Geräteliste wird auf der Seite dargestellt.
Dabei gibt es die Auswahl, ob eine Standardvisualisierung (Hauptfunktion) verwendet werden soll, die für jedes Gerät gleich aussieht mit gerätetypabhängigem Symbol, oder eine Spezialseite, die mehr Gerätefunktionen für die Steuerung bereitstellt.

<!-- DOC -->
### Gerät

Auswahl, welches Gerät auf der Seite angezeigt und gesteuert wird.

<!-- DOC -->
### Anzeige

Hier wird festgelegt, wie das Gerät dargestellt werden soll:

- Hauptfunktion  
  Die Seite besteht jeweils aus einem gerätespezifischen Bild, einer Wertanzeige, einem Titel, der dem Gerätenamen entspricht. 
  Gesteuert wird die jeweilige Hauptfunktion des Gerätes.
  Beispielsweise wird hier bei einer Jalousie zwar der aktuelle Schließstatus in Prozent angezeigt, jedoch kann das Gerät nur hoch- oder runtergefahren werden. Eine Steuerung der Lamellen wäre nicht möglich.
- Detailseite  
  Viele Geräte stellen eigene Seitenlayouts zur Verfügung, die mehrere Gerätefunktionen über eine Seite steuern lassen.
  Bei Geräten mit nur einer Funktion, z. B. bei "Ein-/Ausschaltbares Gerät", sieht die Seite gleich wie die "Hauptfunktion"-Darstellung aus.

<!-- DOC -->
## Seitentyp "Mehrere Felder"

Die Seite wird auf mehrere Felder aufgeteilt, die jeweils unterschiedlich konfiguriert werden können.

<!-- DOC -->
### Layout

Legt fest, wie viele Bedien- bzw. Anzeigefelder auf der Seite sind.

<!-- DOC HelpContext="Felddefintion" -->
### Feld 1-n

Pro Feld wird das Verhalten und Aussehen definiert.

<!-- DOC -->
### Funktion

- Leer  
  Das Feld hat keine Funktion und ist leer.
- Gerät  
  Über das Feld kann ein Gerät gesteuert werden oder die Detailseite eines Gerätes geöffnet werden.
- Sprung zu Seite  
  Über das Feld kann auf eine andere Seite gesprungen werden.
- Zeit  
  Im Feld wird die aktuelle Uhrzeit angezeigt.
- Datum  
  Im Feld wird das aktuelle Datum angezeigt.

<!-- DOCEND -->
### Einstellung für Feldfunktion "Gerät"

<!-- DOC HelpContext="DeviceSelection" -->
#### Gerät

Die Gerätenummer des Geräts, das angezeigt und gesteuert werden soll.

<!-- DOC -->
#### Kurzer Druck

Legt fest, was bei einem kurzen Druck passieren soll.

- Nichts
- Hauptfunktion ausführen  
  Die jeweilige Gerätehauptfunktion wird ausgeführt.
  Beispielsweise wird eine Jalousie nach oben oder unten bewegt.
- Hauptfunktion von anderem Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Detailseite aufrufen  
  Die Detailseite eines Gerätes wird geöffnet.
  Achtung: Bei Geräten mit nur einer Funktion sieht die Detailseite gleich wie die Hauptseite aus (z. B. Ein-/Ausschaltbares Gerät). 
  In diesem Fall ist diese Einstellung nicht sinnvoll.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
#### Langer Druck

Legt fest, was bei einem langen Druck passieren soll.

- Nichts
- Hauptfunktion ausführen  
  Die jeweilige Gerätehauptfunktion wird ausgeführt.
  Beispielsweise wird eine Jalousie nach oben oder unten bewegt.
- Hauptfunktion von anderem Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Detailseite aufrufen  
  Die Detailseite eines Gerätes wird geöffnet.
  Achtung: Bei Geräten mit nur einer Funktion sieht die Detailseite gleich wie die Hauptseite aus (z. B. Ein-/Ausschaltbares Gerät). 
  In diesem Fall ist diese Einstellung nicht sinnvoll.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
#### Einstellung für Feldfunktion "Sprung zu Seite"

In dieser Einstellung muss die Seitennummer konfiguriert werden, die angesprungen wird.
Es können auch Seiten, die aktuell durch ein Kommunikationsobjekt oder beim Blättern ausgenommen sind, angesprungen werden.

Das ermöglicht die Konfiguration eines Menüsystems.
Es werden Übersichtsseiten gebaut, z. B. eine Raumübersicht.
In jedem Feld wird dann auf eine Seite verzweigt, die alle Geräte des Raumes in Feldern darstellt.
Die jeweilige Raumseite ist auch über Blättern erreichbar, jedoch sollten die einzelnen Geräte nur durch Absprünge erreichbar sein und aus dem Blättern exkludiert werden.

<!-- DOC -->
##### Absprung zu

Seitennummer, die bei Druck auf das Feld angesprungen wird.

<!-- DOC -->
##### Verknüpfung auf diese Seite

In diesem Abschnitt kann ein Name und ein Bild für die Seite vergeben werden. Beides wird nicht auf dieser Seite dargestellt, sondern wird verwendet, wenn von einer anderen Feld-Seite auf diese Seite verwiesen wird.

<!-- DOC -->
###### Name

Name, der auf einem Absprung-Feld angezeigt wird, das auf diese Seite verweist.

<!-- DOC -->
###### Bild

Bild, das auf einem Absprung-Feld angezeigt wird, das auf diese Seite verweist.

- Benutzerdefiniert  
  Blendet die Konfiguration für ein benutzerspezifisches Bild ein.
- Ein-/Ausschaltbares Gerät
- Steckdose
- Lampe
- Jalousie
- Rollladen
- Markise
- Thermostat
- Temperatur
- Luftfeuchtigkeit
- Helligkeit
- Regenprognose
- Schneeprognose
- Wind
- Prozent
- Individuell
- Text
- Kontakt
- Bewegungsmelder
- Präsenzmelder
- Leckmelder
- Rauchmelder
- Kohlendioxidmelder (CO2)
- Kohlenmonoxidmelder (CO)
- Lüfter
- Fenster
- Tür
- Garagentor
- Szene
- Mediensteuerung

<!-- DOC -->
###### Bilddatei

Diese Einstellung wird nun angezeigt, wenn Bild auf "Benutzerdefiniert" eingestellt ist.

<!-- DOC -->
#### Einstellung für Feldfunktion "Zeit"

Die Funktion Zeit benötigt keine Touch-Bedienung. 
Jedoch kann über einen kurzen bzw. langen Druck eine anderweitige Funktion ausgelöst werden.

<!-- DOC HelpContext="ShortPressDateTime" -->
##### Kurzer Druck

Legt fest, was bei einem kurzen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC HelpContext="LongPressDateTime" -->
##### Langer Druck

Legt fest, was bei einem langen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
#### Einstellung für Feldfunktion "Datum"

Die Funktion Datum benötigt keine Touch-Bedienung. 
Jedoch kann über einen kurzen bzw. langen Druck eine anderweitige Funktion ausgelöst werden.

<!-- DOCEND -->
##### Kurzer Druck

Legt fest, was bei einem kurzen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

##### Langer Druck

Legt fest, was bei einem langen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
## Seitentyp "Zeit / Datum"

Die Seite zeigt den aktuellen Wochentag, das Datum und die Uhrzeit an.
Voraussetzung ist, dass das Gerät über Gruppenadressen mit Zeit und Datum bzw. mit einem kombinierten Gruppenobjekt Zeit/Datum mit der aktuellen Uhrzeit vom Bus versorgt wird.
Mehr dazu ist im Abschnitt "OpenKNX | Allgemein" zu finden.

<!-- DOCEND -->
### Kurzer Druck

Legt fest, was bei einem kurzen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOCEND -->
### Langer Druck

Legt fest, was bei einem langen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen  
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite  
  Beim Klick wird auf die konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
## Seitentyp "System"

Die Systemseite zeigt die Softwareversion des Gerätes und erlaubt über einen Touch-Taster den KNX-Adress-Programmiermodus zu aktivieren.
