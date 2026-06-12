#pragma once

#include <cstdint>
#include <functional>

enum class DoorWindowSliderDirection
{
    DOOR_WINDOW_SLIDER_LEFT = 0,
    DOOR_WINDOW_SLIDER_RIGHT,
    DOOR_WINDOW_SLIDER_LEFT_RIGHT,
    DOOR_WINDOW_SLIDER_UP,
    DOOR_WINDOW_SLIDER_DOWN,
    DOOR_WINDOW_SLIDER_UP_DOWN
};

class IDoorWindowScreen
{
public:
    virtual ~IDoorWindowScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetPercentageValue(uint8_t value) = 0;
    virtual uint8_t GetPercentageValue() const = 0;
    virtual void SetSliderDirection(DoorWindowSliderDirection direction) = 0;
    virtual void SetPercentageVisible(bool visible) = 0;
    virtual void SetObstructionVisible(bool visible) = 0;
    virtual void SetMovementImage(const char* imageFile) = 0;
    virtual void ClearMovementImage() = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) = 0;
    virtual void Show() = 0;
};
