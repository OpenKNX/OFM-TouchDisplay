#pragma once

#include <functional>

class ISwitchScreen
{
public:
    static ISwitchScreen* instance;
    virtual ~ISwitchScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void RegisterPrimaryAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};
