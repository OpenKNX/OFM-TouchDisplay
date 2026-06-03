#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Thermostat/KnxChannelThermostat.h"
#include "../Screens/ThermostatScreen.h"

class ThermostatDeviceBridge : public ThermostatBridge
{
    MainFunctionChangedHandler _handler;
  
    IThermostatScreen& _screen;
    double _targetTemperature = NAN;
    double _currentTemperature = NAN;
protected:
    DetailDevicePage& _detailDevicePage;
    ThermostatDeviceBridge(ThermostatScreen& screen, DetailDevicePage& detailDevicePage);
 public:
    ThermostatDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~ThermostatDeviceBridge() override;
    virtual void mainFunctionValueChanged() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setTargetTemperature(double temperature) override;
    virtual void setCurrentTemperature(double temperature) override;
    virtual void setMode(ThermostatMode mode) override;
    virtual void setCurrentState(ThermostatCurrentState currentState) override;

    void buttonUpPressed();
    void buttonDownPressed();
    void buttonMainFunctionPressed();
};  