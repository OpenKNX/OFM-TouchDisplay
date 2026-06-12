#pragma once

#include <functional>

class IAlarmScreen
{
public:
    virtual ~IAlarmScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void RegisterScreenPressed(std::function<void()> callback) = 0;
    virtual void Show() = 0;
    virtual void setAlarm(bool alarm) = 0;
    virtual void setUseRedBackgroundForAlarm(bool useRedBackground) = 0;
};
