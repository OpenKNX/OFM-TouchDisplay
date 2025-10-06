#pragma once

#include "MainFunctionScreen.h"

class AlarmScreen : public MainFunctionScreen
{
    bool _alarm;
protected:
    virtual bool useCustomBackgroundColor() override;
    virtual lv_color_t customBackgroundColor() override;
public:
    static AlarmScreen* instance;
    AlarmScreen();
    void setAlarm(bool alarm);
};
