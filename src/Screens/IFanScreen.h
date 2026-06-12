#pragma once

#include <functional>

class IFanScreen
{
public:
    virtual ~IFanScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetAutomaticVisible(bool visible) = 0;
    virtual void SetAutomaticState(bool automatic) = 0;
    virtual void RegisterAutomaticAction(std::function<void()> callback) = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};
