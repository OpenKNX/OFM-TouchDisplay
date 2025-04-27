#include "DateTimeCell.h"
#include "CellParameterDefines.h"
#include "../Screens/CellScreen.h"
#include "../ImageLoader.h"
#include "../TouchDisplayModule.h"
#include "SmartHomeBridgeModule.h"

const char* DateTimeCell::cellType()
{
    return "DateTime";
}

DateTimeCell::~DateTimeCell()
{
    if (_eventPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_cellObject->cell, _eventPressed, this);
}

DateTimeCell::DateTimeCell(bool showDate, bool showTime)
{
    _showDate = showDate;
    _showTime = showTime;
}

void DateTimeCell::setup()
{
    CellObject& cellObject = *_cellObject;
    _eventPressed = [](lv_event_t *e) {((DateTimeCell*)lv_event_get_user_data(e))->_clickStarted = true; };
    lv_obj_add_event_cb(cellObject.cell, _eventPressed, LV_EVENT_PRESSED, this);
 
    if (_showDate && _showTime)
    {
        lv_label_set_text(cellObject.label, "Datum/Zeit");
    }
    else if (_showDate)
    {
        lv_label_set_text(cellObject.label, "Datum");
    }
    else if (_showTime)
    {
        lv_label_set_text(cellObject.label, "Zeit");
    }
    ImageLoader::loadImage(cellObject.image, "");
    updateTime(true);
}

void DateTimeCell::loop(bool configured)
{
    if (configured)
        updateTime(false);
}

void DateTimeCell::updateTime(bool forceUpdate)
{
    CellObject& cellObject = *_cellObject;

    bool timeValid = openknx.time.isValid();
    if (timeValid != _lastValid || forceUpdate)
    {
        _lastValid = timeValid;
        forceUpdate = true;
        ImageLoader::colorState(cellObject.image, true, timeValid);
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
            char buffer[50] = {0};
            if (_showTime && _showDate)
            {
                sprintf(buffer, "%02d.%02d.%04d %02d:%02d", (int)localTime.day, (int)localTime.month, (int)localTime.year, (int)localTime.hour, (int)localTime.minute/*, (int)localTime.second*/);
            }
            else if (_showDate)
            {
                sprintf(buffer, "%02d.%02d.%04d", (int)localTime.day, (int)localTime.month, (int)localTime.year);
            }
            else if (_showTime)
            {
                sprintf(buffer, "%02d:%02d", (int) localTime.hour, (int)localTime.minute/*, (int)localTime.second*/);
            }
            lv_label_set_text(cellObject.value, buffer);
        }
    }
    else
    {
        if (forceUpdate)
        {
            if (_showTime && _showDate)
            {
                lv_label_set_text(cellObject.value, "??.??.???? ??:??:??");
            }
            else if (_showDate)
            {
                lv_label_set_text(cellObject.value, "??.??.????");
            }
            else if (_showTime)
            {
                lv_label_set_text(cellObject.value, "??:??:??");
            }
        }
    }

}

void DateTimeCell::shortPressed()
{
    if (_clickStarted)
        handleClick(ParamTCH_CHShortPress1, ParamTCH_CHJumpToShort1, ParamTCH_CHDeviceShort1);
}

void DateTimeCell::resetPressed()
{
    _clickStarted = false;
}

void DateTimeCell::longPressed()
{
    if (_clickStarted)
        handleClick(ParamTCH_CHLongPress1, ParamTCH_CHJumpToLong1, ParamTCH_CHDeviceLong1);
}

void DateTimeCell::handleClick(int function, uint8_t jumpToPage, uint8_t device)
{
    // <Enumeration Text="Nichts" Value="0" Id="%ENID%" />          
    // <Enumeration Text="Absprung zu Seite" Value="3" Id="%ENID%" />
    // <Enumeration Text="Hauptfunktion Gerät ausführen" Value="4" Id="%ENID%" />
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