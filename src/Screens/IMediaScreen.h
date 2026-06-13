#pragma once

#include <cstdint>
#include <functional>

class IMediaScreen
{
public:
    static IMediaScreen* instance;
    virtual ~IMediaScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetTitleText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetPercentageValue(uint8_t value) = 0;
    virtual uint8_t GetPercentageValue() const = 0;
    virtual void RegisterPercentageChanged(std::function<void(uint8_t)> callback) = 0;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void RegisterPreviousAction(std::function<void()> callback) = 0;
    virtual void RegisterNextAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};
