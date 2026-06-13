#pragma once

#include <functional>

class ILockScreen
{
public:
    static ILockScreen* instance;
    virtual ~ILockScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetBlockedVisible(bool visible) = 0;
    virtual void SetMovementImage(const char* imageFile) = 0;
    virtual void ClearMovementImage() = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};
