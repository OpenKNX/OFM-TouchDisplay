#pragma once

#include <cstdint>
#include <functional>

class DisplayLed;

class IButtonMessageScreen
{
public:
    static IButtonMessageScreen* instance;
    virtual ~IButtonMessageScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetMessageText(const char* text) = 0;
    virtual void SetButtonText(const char* text) = 0;
    virtual void SetPrimaryActionChecked(bool checked) = 0;
    virtual void RegisterPrimaryAction(std::function<void()> callback) = 0;
    virtual void ConnectLed(uint8_t index, DisplayLed* led) = 0;
    virtual void Show() = 0;
};
