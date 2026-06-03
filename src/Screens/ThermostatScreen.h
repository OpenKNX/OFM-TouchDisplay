#pragma once

#include <functional>

#include "ScreenWithLabel.h"
#include "Thermostat/KnxChannelThermostat.h"

class IThermostatScreen
{
public:
    virtual ~IThermostatScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetModeText(const char* text) = 0;
    virtual void SetRoomTemperatureText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetCurrentState(ThermostatCurrentState currentState) = 0;
    virtual void RegisterIncreaseAction(std::function<void()> callback) = 0;
    virtual void RegisterDecreaseAction(std::function<void()> callback) = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};

class ThermostatScreen: public ScreenWithLabel
                      , public IThermostatScreen
{
private:
    lv_obj_t* _labelMode;
    lv_obj_t* _labelValue;
    lv_obj_t* _buttonIncrease;
    lv_obj_t* _buttonDecrease;
    lv_obj_t* _image;
    lv_obj_t* _value;
    std::function<void()> _onIncreaseAction;
    std::function<void()> _onDecreaseAction;
    std::function<void()> _onMainAction;

    static void OnIncreaseAction(lv_event_t* e);
    static void OnDecreaseAction(lv_event_t* e);
    static void OnMainAction(lv_event_t* e);

public:
    static ThermostatScreen* instance;

    ThermostatScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetModeText(const char* text) override;
    virtual void SetRoomTemperatureText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void SetCurrentState(ThermostatCurrentState currentState) override;
    virtual void RegisterIncreaseAction(std::function<void()> callback) override;
    virtual void RegisterDecreaseAction(std::function<void()> callback) override;
    virtual void RegisterMainAction(std::function<void()> callback) override;
    virtual void Show() override;
};