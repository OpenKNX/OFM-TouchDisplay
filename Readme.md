# OFM-TouchDisplay

Diese Modul stellt die Anbindung an ein Touch Display zur Verfügung. 
Das Modul benötigt die [OFM-SmartHomeBridge](https://github.com/OpenKNX/OFM-SmartHomeBridge) für die Gerätedefinitionen.

## Features
- Unterstützung alle Gerätetypen der [OFM-SmartHomeBridge](https://github.com/OpenKNX/OFM-SmartHomeBridge)
  - Anzeige von Detailseiten je nach Gerätetype
  - Anzeige von Hauptfunktionsseiten zur Basissteuerung des Gerätes
- Anzeige von Uhrzeit und Datum
- Seite mit mehreren Felden, beliebig mit folgenden Funktionen programmierbar:
  - Uhrzeit
  - Datum
  - Geräte-Hauptfunktion
  - Absprung auf andere Seite
- Seite zum aktivieren des Programmiermodus

## Fertige Firmewares

- [OAM-TouchRound](https://github.com/OpenKNX/OAM-TouchRound) 

## Anwenderdokumentation

Die Anwenderdokumentation ist [hier](./doc/Applikationsbeschreibung.md) zu finden.


## Hardware Unterstützung

|Prozessor | Status               | Anmerkung                  |
|----------|----------------------|----------------------------|
|RP2040    | Beta                 |                            |
|RP3050    | Beta                 |                            |
|ESP32     | Untested             |                            |

Getestete Hardware:
- [OpenKNX Ready Touch Round](https://www.ab-smarthouse.com/produkt/openknx-touch-display/?v=7d0db380a5b9 )

## Einbindung in die Anwendung

Das OAM muss die [OFM-SmartHomeBridge](https://github.com/OpenKNX/OFM-SmartHomeBridge) einbinden

In das Anwendungs XML müssen folgend config Werte und die OFM-SmartHomeBridge und OFM-TouchRound aufgenommen werden:

```xml
    <op:config name="%BRI_TabName%" value="Geräte" />
    <op:config name="%BRI_TabIcon%" value="home-edit-outline" />
    <op:config name="%BRI_DisplaySettings%" value="1" />
    <op:config name="%BRI_BridgeSettings%" value="0" />
    <op:config name="%BRI_HomeKitSupport%" value="0" />
    <op:config name="%BRI_HueSupport%" value="0" />
    <op:config name="%BRI_NumChannelsDefault%" value="0" />
    <op:config name="%BRI_DefaultType%" value="0" />
    
    <op:config name="%BRI_NumChannels%" value="50" />


    <op:define prefix="BRI" 
              ModuleType="2"
              share="../lib/OFM-SmartHomeBridge/src/SmartHomeBridge.share.xml"
              template="../lib/OFM-SmartHomeBridge/src/SmartHomeBridge.templ.xml"
              NumChannels="%BRI_NumChannels%" 
              KoOffset="600" >
        <op:verify File="../lib/OFM-SmartHomeBridge/library.json" ModuleVersion="%BRI_VerifyVersion%" /> 
    </op:define>

    <op:define prefix="TCH"
        share="../lib/OFM-TouchDisplay/src/TouchDisplay.share.xml"
        template="../lib/OFM-TouchDisplay/src/TouchDisplay.templ.xml"
        ModuleType="14"
        KoSingleOffset="500"
        KoOffset="520"
        NumChannels="50" >
      <op:verify File="../lib/OFM-TouchDisplay/library.json" ModuleVersion="%TCH_VerifyVersion%" />
    </op:define>
```

In main.cpp muss die OFM-SmartHomeBridge und das OFM-TouchDispay hinzugefügt werden:

```
[...]
#include "SmartHomeBridgeModule.h"
#include "TouchDisplayModule.h"
[...]

void setup()
{
    [...]
    openknx.addModule(7, openknxSmartHomeBridgeModule);
    openknx.addModule(1, openknxTouchDisplayModule);
    [...]
}
```

Zur Integration der Display Hardware müssen folgende Funktionen implementiert werden:

- bool touchIsPressed()
- void displayInit()
- void touchInit()
- void backgroundLight(bool on)


Beispiel:

```cpp
bool touchIsPressed()
{
    return chsc6x_is_pressed();
}

void displayInit()
{
    lv_xiao_disp_init();
}

void touchInit()
{
    lv_xiao_touch_init();
}

void backgroundLight(bool on)
{
    digitalWrite(XIAO_BL, on ? HIGH : LOW);
}
```

Anpassung des Displaydrivers:

Das OFM-TouchDisplay Modul muss zwischen der Touch Erkennung des Displays geschalten werden.
Dazu wird die Touch Erkennung in der oben genannten Funktion touchIsPressed dem OFM-TouchDisplay zur Verfügung gestellt.
Der Aufruf der Touch Erkennung im Display Modul muss durch den Aufruf touchIsPressedForLgvl() der im OFM-TouchDisplay zur Verügung gestellt wird, aufgerufen werden.

Beispiel lv_xiao_round_screen.h:
```cpp
extern bool touchIsPressedForLgvl();

#include <Arduino.h>
#include <lvgl.h>
#include <SPI.h>
#include <Wire.h>
[...]

void chsc6x_read( lv_indev_t * indev_driver, lv_indev_data_t * data )
{
    lv_coord_t touchX, touchY;
    if( !touchIsPressedForLgvl() )
    {
        data->state = LV_INDEV_STATE_RELEASED;
    } else {
        data->state = LV_INDEV_STATE_PRESSED;
        touchX = data->point.x;
        touchY = data->point.y;
        chsc6x_get_xy(&touchX, &touchY);
        /*Set the coordinates*/
        if (touchX >= SCREEN_WIDTH) touchX = SCREEN_WIDTH - 1;
        if (touchY >= SCREEN_HEIGHT) touchY = SCREEN_HEIGHT - 1;        
        data->point.x = touchX;
        data->point.y = touchY;
    }
}
```

## Architektur

To Do

## Lizenz

[GNU GPL v3](LICENSE)