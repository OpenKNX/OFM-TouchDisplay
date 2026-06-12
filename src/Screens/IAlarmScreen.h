#pragma once

class IAlarmScreen
{
public:
    virtual ~IAlarmScreen() = default;
    virtual void setAlarm(bool alarm) = 0;
    virtual void setUseRedBackgroundForAlarm(bool useRedBackground) = 0;
};
