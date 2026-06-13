#pragma once

#include <cstdint>
#include <functional>

class IRGBScreen
{
public:
    static IRGBScreen* instance;
    virtual ~IRGBScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetColorValue(uint8_t r, uint8_t g, uint8_t b) = 0;
    virtual uint32_t GetColorValue() const = 0;
    virtual void RegisterColorChangeCompleted(std::function<void(uint32_t)> callback) = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};
