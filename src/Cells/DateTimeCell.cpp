#include "DateTimeCell.h"
#include "CellParameterDefines.h"
#include "../ImageLoader.h"
#include "../TouchDisplayModule.h"
#include "SmartHomeBridgeModule.h"

const char* DateTimeCell::cellType()
{
    return "DateTime";
}

DateTimeCell::~DateTimeCell()
{
    if (_cellObject != nullptr)
        _cellObject->RegisterPressed(nullptr);
}

DateTimeCell::DateTimeCell(bool showDate, bool showTime)
{
    _showDate = showDate;
    _showTime = showTime;
}

void DateTimeCell::setup()
{
    ICellObject& cellObject = *_cellObject;
    cellObject.RegisterPressed([this]() { _clickStarted = true; });
 
    if (_showDate && _showTime)
    {
        cellObject.SetLabelText("Datum/Zeit");
    }
    else if (_showDate)
    {
        cellObject.SetLabelText("Datum");
    }
    else if (_showTime)
    {
        cellObject.SetLabelText("Zeit");
    }
    cellObject.ClearImage();
    updateTime(true);
}

void DateTimeCell::loop(bool configured)
{
    if (configured)
        updateTime(false);
}

void DateTimeCell::updateTime(bool forceUpdate)
{
    ICellObject& cellObject = *_cellObject;

    bool timeValid = openknx.time.isValid();
    if (timeValid != _lastValid || forceUpdate)
    {
        _lastValid = timeValid;
        forceUpdate = true;
        cellObject.SetImageState(timeValid);
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
            cellObject.SetValueText(buffer);
        }
    }
    else
    {
        if (forceUpdate)
        {
            if (_showTime && _showDate)
            {
                cellObject.SetValueText("??.??.???? ??:??:??");
            }
            else if (_showDate)
            {
                cellObject.SetValueText("??.??.????");
            }
            else if (_showTime)
            {
                cellObject.SetValueText("??:??:??");
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
