
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

Das Einschalten des Displays erfolgt durch Berührung der Anzeige oder einer der angeschlossen Sensortasten.

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



<!-- DOC -->
### Seitenfreigabe über Objekt







<!-- DOC -->
### Bild für Absprung-Link auf diese Seite

<!-- DOC -->
### Bilddatei

<!-- DOC -->
### Layout



<!-- DOC -->
### Gerät

<!-- DOC -->
### Anzeige

<!-- DOC -->
### Seite über Blättern erreichbar

<!-- DOC -->
### Absprung zu

<!-- DOC -->
### Feldanzahl

Legt fest, wieviele Bedien- bzw. Anzeigefelder auf der Seite sind.

<!-- DOC -->
### Felddefintion

<!-- DOC -->
### Funktion

<!-- DOC -->
### Darstellung

<!-- DOC -->
### Kurzer Druck

<!-- DOC -->
### Langer Druck

<!-- DOC -->
### Name

<!-- DOC -->
### Bild


<!-- DOCEND -->