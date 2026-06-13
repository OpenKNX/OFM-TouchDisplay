#pragma once

#include <functional>

class ISceneScreen
{
public:
    static ISceneScreen* instance;
    virtual ~ISceneScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void RegisterPrimaryActionPressed(std::function<void()> callback) = 0;
    virtual void RegisterPrimaryActionReleased(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};
