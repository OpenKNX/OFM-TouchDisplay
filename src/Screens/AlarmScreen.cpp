#include "AlarmScreen.h"

AlarmScreen* AlarmScreen::instance = nullptr;

AlarmScreen::AlarmScreen()
 : MainFunctionScreen()
{
}

bool AlarmScreen::useCustomBackgroundColor()
{
    return _alarm;
}   

lv_color_t AlarmScreen::customBackgroundColor()
{
    if (_alarm)
        return lv_color_make(255, 0, 0);
    return MainFunctionScreen::customBackgroundColor();
}

void AlarmScreen::setAlarm(bool alarm)
{
    if (_alarm != alarm)
    {
        _alarm = alarm;
        updateBackgroundColor();
    }
}