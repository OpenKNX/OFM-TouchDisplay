<!-- DOC -->
# Touch Display

Über den Abschnitt Touch Round werden die Anzeige und die Seiten definiert.

Das Konfigurationskonzept sieht vor, das im Abschnitt [Geräte](https://github.com/OpenKNX/OFM-SmartHomeBridge/tree/v1/doc/Applikationsbeschreibung-Geräte.md) zuerst die im KNX System vorhanden Geräte mit den entsprechenden Gruppenadressen verknüpft werden.

In diesem Abschnitt wird das Layout der Seiten definiert und bei Bedarf die Verknüpfungen zur Gerätedefinition vorgenommen. 
Durch die Trennung von Geräte- und Seitenkonfiguration, kann das Layout und die Seitenreihenfolge leicht bei angepasst werden, ohne aufwendige Gruppenverknüpfungen erneut vorzunehmen.

<!-- DOC -->
## Allgemeine

In diesem Abshnitt werden globale für das Display notwendige Einstellungen vorgenommen.

<!-- DOCEND -->
### Geräteeinstellungen

<!-- DOC -->
#### Anzeige drehen

Diese Einstellung dient dazu, bei der Einbaurichtung des Display's flexibel zu sein.
Die Anzeige kann über folgende Optionen gedreht werden:

- Nein
- 90°
- 180° 
- 270°

<!-- DOC -->
#### Sensor Tasten Vorhanden

Über diese Einstellung muss festgelegt werden, ob bei der Hardware 2 Touch-Sensor Flächen angeschlossen sind.

- Nein
- Ja
  Die Tasten werden zum Blättern der Seiten verwendet

<!-- DOC -->
#### Links-Rechts tauschen

Die Einstellung ist nur vorhanden, wenn Sensor Tasten vorhanden sind.
Die Konfiguration erlaubt das Tauschen der Tasten.
Dies kann z.B. benutzt werden, um die Tasten oberhalb des Displays zu verwenden anstatt wie normal vorgesehen auf der Unterseite. 
Dazu muss das Display um 180° gedreht verbaut werden, die Einstellung [Anzeige drehen](#anzeige-drehen) ebenfalls auf 180° eingestellt werden und diese Einstellung auf Ja gesetzt werden.


<!-- DOC -->
#### Seitenwechsel über Wischen im unteren Bereich

Ist diese Einstellung auf Ja gesetzt, kann im unteren Bildschirmbereich (in der etwa in der Position wo der Seitenname angezeigt wird) durch wischen nach rechts die Seite vor, bzw. wischen nach links zurück geblättert werden.

<!-- DOCEND -->
### Basiseinstellungen

<!-- DOC -->
#### Anzeige ausschalten nach

Nach der konfigurierten Zeit in der keine Bedienung erfolgt, schaltet sich die Anzeige aus. 
Wird 0 eingestellt, erfolgt keine automatische Abschaltung.

Das Einschalten des Displays erfolgt durch Berührung der Anzeige oder einer der angeschlossenen Sensortasten.

Wichtig, bei Verwendung des Touch Round Displays: wird die Hintergrundbeleuchtung des Display's nicht abgeschalten, ist die Hardware falsch konfiguriert.
In diesem Fall muss der DIP Schalter 2 auf der Rückseite der Display-Platine umgeschalten werden.

<!-- DOC -->
##### Anzeige aus nach Zeit

Gibt die Zeit an, die gewartet wird bis nach der letzten Bedienung gewartet wird, bis das Display abgeschalten wird. 

<!-- DOC -->
##### Anzeige aus nach Zeitbasis

- Sekunde(n)
- Minute(n)
- Stunde(n)

<!-- DOC -->
#### Standard Seite 

Gibt die Seite an, die angezeigt wird, wenn das Display die Busspannung bekommt. 
Weiters kann ein automatischer Rückfall auf die Standardseite konfiguiert werden.

Achtung: Die hier eingestellte Standardseite kann auch über ein Gruppenobjekt überladen werden. Siehe dazu die Einstellung [Rückfall auf Standardseite](#rückfall-auf-standardseite)


<!-- DOC -->
#### Rückfall auf Standardseite 

Nach der konfigurierten Zeit in der keine Bedienung erfolgt, schaltet sich die Anzeige aus. 
Wird 0 eingestellt, erfolgt keine automatische Abschaltung.


<!-- DOC -->
##### Standardseite nach Zeit 

Zeit nach der wenn keine Bedienung stattfindet auf die Standseite gewechselt wird.

<!-- DOC -->
##### Standardseite nach Zeitbasis 

- Sekunde(n)
- Minute(n)
- Stunde(n)

<!-- DOC -->
#### Gruppenobjekt für Standard Seitenauswahl

Blendet ein Gruppenobjekt ein, über dem die Standardseite vom KNX-Bus vorgegeben werden kann.
Als Type wird der Szene Type (DPT 17.001) verwendet.
Die Szenenummer entspricht der Seite.
Die Szene 1 (RAW-Wert 0) wählt somit die Seite 1 als Standardobjekt aus.

<!-- DOCEND -->
### Anzeigemodus


<!-- DOC -->
#### Bei Nacht anders

Dieser Einstellung ermöglich das der Stil und die Farbeinstellungen für Tag und Nacht getrennt eingestellt werden kann.

- Deaktiviert
  Für Tag und Nacht werden die selben Einstellungen benutzt.
- Umschaltobjekt Nacht EIN
  Es wird ein Gruppenobjekt zur Verfügung gestellt, bei dem EIN für die Auswahl der Nachteinstellung anliegen muss.
- Umschaltobjekt Tag EIN
  Es wird ein Gruppenobjekt zur Verfügung gestellt, bei dem EIN für die Auswahl der Tageseinstellung anliegen muss.

<!-- DOC -->
#### Stil 

Gibt den generellen Anzeigestil vor, der die Hintegrundfarbe und Basiselement betrifft.

- Hell
  Der Hintergrund wird weiß dargestellt, Standardtexte schwarz
- Dunkel
  Der Hintergrund wird grau dargestellt, Standardtexte sind weiß
- Schwarz
  Der Hintergrund wird schwarz dargestellt, Standardtexte sind weiß

<!-- DOC -->
#### Farbe Bedienelemente

Wählt die Farbe für Steuerbedienelemente im aktiven Zustand (Z.B. der aktive Teil eines Sliders).

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
- Orange Gelb
- Orange
- Dunkel Orange
- Braun
- Blau-Grau
- Grau

<!-- DOC -->
#### Farbe Bild EIN

Farbe die für die Bildeinfärbung im Zustand EIN verwendet wird.

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
- Orange Gelb
- Orange
- Dunkel Orange
- Braun
- Blau-Grau
- Grau

<!-- DOC -->
### Seiten 

In diesem Abschnitt werden die Seitenanzahl und Seitentypen eingestellt.

<!-- DOC -->
#### Verfügbare Seiten

Anzahl der Seiten die in der Konfiguration zur Verfügung stehen.

<!-- DOC HelpContext="MovePageButtons" -->
#### Seitenreihenfolge anpassen

Über die Tasten kann die Reihenfolge der Seite.

<!-- DOC -->
### Beschreibung

Beschreibung der Seite die in der ETS verwendet werden soll. 
Die Beschreibung wird am Display nicht angezeigt.
Sie dient zur Erleichterung und übersichtlichkeit der Konfiguration.

<!-- DOC -->
### Seitentyp

Hier kann man zwischen verschieden Seitenarten wählen.

- Deaktiviert
  Die Seite ist deaktiviert und wird beim Blättern nicht angesprungen. 
  Wird die Seite über direkte Auswahl durch ein Kommunikationsobjekt oder als Sprungziel angewählt, wird im Display angezeigt, das die Seite deaktiviert ist.
- [Gerät](#seitentype-gerät)
  Ein Gerät aus der Geräteliste wird auf der Seite dargestellt.
  Dabei gibt es die Auswahl ob ein Standardvisualierung (Hauptfunktion) verwendet werden soll, die für jedes Gerät gleich aussieht mit Gerätetype abhängigen Symbol oder eine Spezialseite das mehr Gerätefunktionen für die Steuerung bereitstellt.
  Achtung: Bei manchen einfachen Geräten gibt es in der Visualisierung keinen Unterschied zwischen Standard und Hauptfunktion
- [Mehrere Felder](#seitentype-mehrere-felder)
  Die Seite wird auf mehrere Felder aufgeteilt die jeweils unterschiedlich konfiguriert werden können.
  Jedes Feld kann ein Gerät steueren, als Absprung auf eine andere Seite dienen oder spezial Seiten wie z.B. die Uhrzeit darstellen
- Zeit / Datum
  Seite für die aktuelle Uhrzeit und Datum. 
- System
  Systemseite mit technischen Informationen und KNX-Programmiertaster

<!-- DOCEND -->
## Seitendefinition

Neben der [Beschreibung](#beschreibung) und der [Seitentyp](#seitentyp) Auswahl stehen folgen Einstellungen zur Verfügung:

<!-- DOC -->
### Seite über Blättern erreichbar

Gibt an, ob die Seite über blättern erreicht werden kann.
Wird Nein angewählt, kann die Seite trotzdem über das Kommunikationsobjekt "Gehe zu Seite" oder über den Absprung eines Display Feldes bei der Seitentype "Mehrere Felder" angezeigt werden.

<!-- DOC -->
### Seitenfreigabe über Objekt

Das Display stellt 8 Sperrobjekte zur bereit.
Diese dienen dazu, Seite zu Sperren und damit beim Blättern auszulassen.
Ein Sperrobjekt kann beliebig viele Seiten gleichzeitig sperren.
Beispielsweise kann sinnvoll sein, alle Seiten die für die Heizungsteuerung dienen im Sommer auszublenden.

- Deaktiviert  
  Die Seite wird nicht durch ein Kommunikationsobjekt gesperrt.
- Seitenfreigabe A  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe A" gesperrt.
- Seitenfreigabe B  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe B" gesperrt.
- Seitenfreigabe C  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe C" gesperrt.
- Seitenfreigabe D  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe D" gesperrt.
- Seitenfreigabe E  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe E" gesperrt.
- Seitenfreigabe F  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe F" gesperrt.
- Seitenfreigabe G  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe G" gesperrt.
- Seitenfreigabe H  
  Die Seite wird nicht durch das Kommunikationsobjekt "Seitenfreigabe H" gesperrt.

<!-- DOC -->
## Seitentype Gerät

Mit der Seitentype Gerät

<!-- DOC -->
### Gerät

Ein Gerät aus der Geräteliste wird auf der Seite dargestellt.
Dabei gibt es die Auswahl ob ein Standardvisualierung (Hauptfunktion) verwendet werden soll, die für jedes Gerät gleich aussieht mit Gerätetype abhängigen Symbol oder eine Spezialseite das mehr Gerätefunktionen für die Steuerung bereitstellt.

<!-- DOC -->
### Anzeige

Auswahl welches Gerät auf der Seite angezeigt und gesteuert wird.

<!-- DOC -->
### Layout

Zur Auswahl steht:

- Hauptfunktion
  Die Seite besteht jeweils aus einem Gerätspezifischen Bild, einer Wertanzeige, einem Titel der dem Gerätenamen entspricht. 
  Gesteuert wird die jeweilige Hauptfunktion des Gerätes.
  Beispielsweise wird hier bei einer Jalousie zwar der aktuelle Schließstatus in Prozent angezeigt werden, jedoch kann das Geräte nur Hoch- oder Runtergefahren werden. Eine Steuerung der Lammellen wäre nicht möglich.
- Detailseite
  Viele Geräte stellen eigene Seitenlayouts zur Verfügung die mehrer Gerätefunktionen über eine Seite steuern lässt.
  Bei Geräten mit nur einer Funktion, z.B. bei "Ein- Ausschaltbares Gerät" sieht die Seite gleich wie die "Hauptfunktion" Darstellung aus.

## Seitentype Mehrere Felder

Die Seite wird auf mehrere Felder aufgeteilt die jeweils unterschiedlich konfiguriert werden können.

<!-- DOC -->
### Funktion

- Leer
  Das Feld ist hat keine Funktion und ist leer
- Gerät
  Über das Feld kann ein Gerät gesteuert werden oder die Detailseite eines Gerätes geöffnet werden
- Sprung zu Seite
  Über das Feld kann auf eine andere Seite gesprungen werden
- Zeit
  Im Feld wird die aktuelle Uhrzeit angezeigt
- Datum
  Im Feld wird das aktuelle Datum angezeigt

<!-- DOCEND -->
#### Einstellung für Feldfunktion Gerät

<!-- DOC HelpContext="DeviceSelection" -->
##### Geröt

Die Gerätenummer des Geräts das angezeigt und gesteuert werden soll

<!-- DOC -->
##### Kurzer Druck

Legt fest, was bei einem kurzen Druck passieren soll.

- Nichts
- Hauptfunktion ausführen
  Die jeweilige Gerätehauptfunktion wird ausgeführt.
  Beispielsweise wird eine Jalousie nach oben oder unter bewegt.
- Hauptfunktion von anderem Gerät ausführen
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Detailseite aufrufen
  Die Detailseite eines Gerätes wird geöffnet.
  Achtung: Bei Geräten mit nur einer Funktion, sieht die Detailseite gleich wie die Hauptseite aus (Z.B. Ein- Ausschaltbares Gerät). 
  In diesem Fall ist diese Einstellung nicht sinnvoll.
- Absprung zu Seite
  Beim Klick wird auf die Konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
### Langer Druck

legt fest, was bei einem langen Druck passieren soll.

- Nichts
- Hauptfunktion ausführen
  Die jeweilige Gerätehauptfunktion wird ausgeführt.
  Beispielsweise wird eine Jalousie nach oben oder unter bewegt.
- Hauptfunktion von anderem Gerät ausführen
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Detailseite aufrufen
  Die Detailseite eines Gerätes wird geöffnet.
  Achtung: Bei Geräten mit nur einer Funktion, sieht die Detailseite gleich wie die Hauptseite aus (Z.B. Ein- Ausschaltbares Gerät). 
  In diesem Fall ist diese Einstellung nicht sinnvoll.
- Absprung zu Seite
  Beim Klick wird auf die Konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
#### Einstellung für Feldfunktion Gerät

<!-- DOC HelpContext="ShortPressDateTime" -->
##### Kurzer Druck

Legt fest, was bei einem kurzen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite
  Beim Klick wird auf die Konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC HelpContext="LongPressDateTime" -->
##### Langer Druck

Legt fest, was bei einem kurzen Druck passieren soll.

- Nichts
- Hauptfunktion von Gerät ausführen
  Führt die Hauptfunktion eines anderen Gerätes aus.
- Absprung zu Seite
  Beim Klick wird auf die Konfigurierte Seite gesprungen.

Hinweis: Die gesamte Feldfläche kann für das Drücken verwendet werden. 
Es muss nicht explizit auf das Bild gedrückt werden.

<!-- DOC -->
#### Einstellung für Feldfunktion Sprung zu Seite

In dieser Einstellung, muss die Seitennummer konfiguriert werden, die angesprungen wird.
Es können auch Seiten die aktuell durch ein Kommunikationsobjekt oder die beim Blättern ausgenommen sind, angesprungen werden.

Das ermöglich die Konfiguriation eines Menüssystems.
Es werden übersichtsseiten gebaut, z.B. eine Raumübersicht.
In jedem Felld wird dann auf eine Seite verzweigt die alle Geräte des Raumes in Feldern darstellt.
Die jeweilige Raumseite ist auch über blättern erreichbar, jedoch sollten die einzelnen Geräte nur durch Absprünge erreichbar sein und aus dem Blättern exkludiert werden.

<!-- DOC -->
### Bild für Absprung-Link auf diese Seite


<!-- DOC -->
### Bilddatei







<!-- DOC -->
### Absprung zu

<!-- DOC -->
### Feldanzahl

Legt fest, wieviele Bedien- bzw. Anzeigefelder auf der Seite sind.

<!-- DOC -->
### Felddefintion



<!-- DOC -->
### Darstellung



<!-- DOC -->
### Name

<!-- DOC -->
### Bild


<!-- DOCEND -->