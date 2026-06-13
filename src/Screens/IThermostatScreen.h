#pragma once

#include <functional>

#include "Thermostat/KnxChannelThermostat.h"

class IThermostatScreen
{
public:
    static IThermostatScreen* instance;
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
