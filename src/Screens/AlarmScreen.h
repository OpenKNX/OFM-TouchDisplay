#pragma once

#include "MainFunctionScreen.h"

class AlarmScreen : public MainFunctionScreen
{
    bool _alarm;
    bool _useRedBackground = false;
protected:
    virtual bool useCustomBackgroundColor() override;
    virtual lv_color_t customBackgroundColor() override;
public:
    static AlarmScreen* instance;
    AlarmScreen();
    void setAlarm(bool alarm);
    void setUseRedBackgroundForAlarm(bool useRedBackground);
};
