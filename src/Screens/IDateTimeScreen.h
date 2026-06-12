#pragma once

#include <functional>

class IDateTimeScreen
{
public:
    virtual ~IDateTimeScreen() = default;
    virtual void SetWeekdayText(const char* text) = 0;
    virtual void SetDateText(const char* text) = 0;
    virtual void SetTimeText(const char* text) = 0;
    virtual void SetMessageText(const char* text) = 0;
    virtual void RegisterScreenPressed(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};
