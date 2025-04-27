#include "DateTimePage.h"
#include "../Screens/DateTimeScreen.h"
#include "SmartHomeBridgeModule.h"
#include "TouchDisplayModule.h"

const char* DateTimePage::pageType()
{
    return "DateTime";
}

DateTimePage::~DateTimePage()
{
    if (_eventPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.screen, _eventPressed, this);  
}

void DateTimePage::setup()
{
    updateTime(true);
    _screen.show();
}

void DateTimePage::updateTime(bool forceUpdate)
{
    bool timeValid = openknx.time.isValid();
    if (timeValid != _lastValid)
    {
        _lastValid = timeValid;
        forceUpdate = true;
    }
    if (timeValid)
    {
        auto localTime = openknx.time.getLocalTime();
        if (forceUpdate || (
            _lastYear != localTime.year ||
            _lastMonth != localTime.month ||
            _lastHour != localTime.hour ||
            _lastMinute != localTime.minute
        ))
        {
            _lastYear = localTime.year;
            _lastMonth = localTime.month;
            _lastHour = localTime.hour;
            _lastMinute = localTime.minute;

            lv_label_set_text(_screen.weekday, dayOfWeekString(localTime.dayOfWeek));

            char buffer[50];
            sprintf(buffer, "%02d.%02d.%04d", (int)localTime.day, (int)localTime.month, (int)localTime.year);
            lv_label_set_text(_screen.date, buffer);
       
            sprintf(buffer, "%02d:%02d", (int) localTime.hour, (int)localTime.minute /* , (int)localTime.second*/);
            lv_label_set_text(_screen.time, buffer);
            lv_label_set_text(_screen.message, "");
        }
    }
    else
    {
        if (forceUpdate)
        {
            lv_label_set_text(_screen.weekday, "");
            lv_label_set_text(_screen.date, "");
            lv_label_set_text(_screen.time, "");
            lv_label_set_text(_screen.message, "Zeit nicht vorhanden.\nBitte prüfen ob Uhrzeit/Datum\nin der ETS korrekt verbunden ist");
        }
    }
}

const char* DateTimePage::dayOfWeekString(uint8_t dayOfWeek) 
{
    switch (dayOfWeek)
    {
    case 0:
        return "Sonntag";
    case 1:
        return "Montag";
    case 2:
        return "Dienstag";
    case 3:
        return "Mittwoch";
    case 4:
        return "Donnerstag";
    case 5:
        return "Freitag";
    case 6:
        return "Samstag";
    default:
        return "";
    }
}


void DateTimePage::loop(bool configured)
{
    if (configured)
        updateTime(false);
}

std::string DateTimePage::name()
{
    return "Uhrzeit";
}

std::string DateTimePage::image()
{
    return "DateTime.png";
}


void DateTimePage::shortPressed()
{
    if (_clickStarted)
    {
        handleClick(ParamTCH_CHShortPress1, ParamTCH_CHJumpToShort1, ParamTCH_CHDeviceShort1);
    }
}

void DateTimePage::longPressed()
{
    if (_clickStarted)
    {
        handleClick(ParamTCH_CHLongPress1, ParamTCH_CHJumpToLong1, ParamTCH_CHDeviceLong1);
    }      
}

void DateTimePage::resetPressed()
{
    _clickStarted = false;
}
   

void DateTimePage::handleClick(int function, uint8_t jumpToPage, uint8_t device)
{
    // <Enumeration Text="Nichts" Value="0" Id="%ENID%" />          
    // <Enumeration Text="Absprung zu Seite" Value="3" Id="%ENID%" />
    // <Enumeration Text="Hauptfunktion anderes Gerät ausführen" Value="4" Id="%ENID%" />
    switch(function)
    {
    case 0:
        logDebugP("Nichts");
        return;
    case 3:
        logDebugP("Absprung zu Seite %d", jumpToPage);
        openknxTouchDisplayModule.activatePage(jumpToPage);
        return;
    case 4:
        logDebugP("Hauptfunktion von Geräte %d", device);
        auto deviceBridge = openknxSmartHomeBridgeModule.getChannel(device - 1);
        if (deviceBridge != nullptr)
        {
            deviceBridge->commandMainFunctionClick();
        }
        else
        {
            logErrorP("Device %d not found", device);
        }
        return;
    }
}