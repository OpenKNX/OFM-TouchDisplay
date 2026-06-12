#pragma once

#include <functional>

#include "ScreenWithLabel.h"

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

class DoorWindowScreen: public ScreenWithLabel
                      , public IDoorWindowScreen
{
private:
    lv_obj_t* _slider;
    lv_obj_t* _image;
    lv_obj_t* _value;
    lv_obj_t* _obstruction;
    lv_obj_t* _movement;
    std::function<void()> _onMainAction;
    std::function<void(uint8_t)> _onPercentageChangeCompleted;

    static void OnMainAction(lv_event_t* e);
    static void OnPercentageChangeCompleted(lv_event_t* e);

public:
    static DoorWindowScreen* instance;
    DoorWindowScreen();
    void setSliderDirection(DoorWindowSliderDirection direction);

    virtual void SetLabelText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void SetPercentageValue(uint8_t value) override;
    virtual uint8_t GetPercentageValue() const override;
    virtual void SetSliderDirection(DoorWindowSliderDirection direction) override;
    virtual void SetPercentageVisible(bool visible) override;
    virtual void SetObstructionVisible(bool visible) override;
    virtual void SetMovementImage(const char* imageFile) override;
    virtual void ClearMovementImage() override;
    virtual void RegisterMainAction(std::function<void()> callback) override;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) override;
    virtual void Show() override;
};