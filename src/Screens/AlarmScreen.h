#pragma once

#include "IAlarmScreen.h"
#include "MainFunctionScreen.h"

class AlarmScreen : public MainFunctionScreen
                 , public IAlarmScreen
{
    bool _alarm;
    bool _useRedBackground = false;
protected:
    virtual bool useCustomBackgroundColor() override;
    virtual lv_color_t customBackgroundColor() override;
public:
    static AlarmScreen* instance;
    AlarmScreen();
    virtual void setAlarm(bool alarm) override;
    virtual void setUseRedBackgroundForAlarm(bool useRedBackground) override;
};
