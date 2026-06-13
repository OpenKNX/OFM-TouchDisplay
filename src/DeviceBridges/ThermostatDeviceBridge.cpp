#include "ThermostatDeviceBridge.h"
#include "../TouchDisplayModule.h"

ThermostatDeviceBridge::ThermostatDeviceBridge(DetailDevicePage& detailDevicePage)
    : ThermostatDeviceBridge(*IThermostatScreen::instance, detailDevicePage)
{

}

ThermostatDeviceBridge::ThermostatDeviceBridge(IThermostatScreen& screen, DetailDevicePage& detailDevicePage)
    : _screen(screen), _detailDevicePage(detailDevicePage)
{
}

void ThermostatDeviceBridge::setup(uint8_t _channelIndex)
{   
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterIncreaseAction([this]() { buttonUpPressed(); });
    _screen.RegisterDecreaseAction([this]() { buttonDownPressed(); });
    _screen.RegisterMainAction([this]() { buttonMainFunctionPressed(); });


    mainFunctionValueChanged();
    _screen.Show();
}

ThermostatDeviceBridge::~ThermostatDeviceBridge()
{
    _screen.RegisterIncreaseAction(nullptr);
    _screen.RegisterDecreaseAction(nullptr);
    _screen.RegisterMainAction(nullptr);
}

void ThermostatDeviceBridge::mainFunctionValueChanged() 
{
    auto& device = *_detailDevicePage.getDevice();
    _screen.SetValueText(device.currentValueAsString().c_str());
}


void ThermostatDeviceBridge::buttonUpPressed()
{
    if (!std::isnan(_targetTemperature))
    {
        _channel->commandTargetTemperature(this, _targetTemperature + 0.5);
    }
    else if (!std::isnan(_currentTemperature))
    {
        _channel->commandTargetTemperature(this, _currentTemperature + 0.5);
    }
}
   

void ThermostatDeviceBridge::buttonDownPressed()
{
    if (!std::isnan(_targetTemperature))
    {
        _channel->commandTargetTemperature(this, _targetTemperature - 0.5);
    }
    else if (!std::isnan(_currentTemperature))
    {
        _channel->commandTargetTemperature(this, _currentTemperature - 0.5);
    }
}


void ThermostatDeviceBridge::buttonMainFunctionPressed()
{    
    _channel->commandMainFunctionClick();
}

void ThermostatDeviceBridge::setTargetTemperature(double temperature)
{
    _targetTemperature = temperature;
}
void ThermostatDeviceBridge::setCurrentTemperature(double temperature)
{
    _currentTemperature = temperature;
    char buffer[30];
    snprintf(buffer, sizeof(buffer), "Raum: %0.1f°", temperature);
    _screen.SetRoomTemperatureText(buffer);
}
void ThermostatDeviceBridge::setMode(ThermostatMode mode)
{
    switch (mode)
    {
    case ThermostatMode::ThermostatModeOff:
        _screen.SetModeText("Aus");
        _screen.SetMainIndicatorImage("thermostatOff.png", true, _channel->mainFunctionValue());
        break;
    case ThermostatMode::ThermostatModeHeating:
        _screen.SetModeText("Heizen");
        _screen.SetMainIndicatorImage("thermostatHeading.png", true, _channel->mainFunctionValue());
        break;
    case ThermostatMode::ThermostatModeCooling:
        _screen.SetModeText("Kühlen");
        _screen.SetMainIndicatorImage("thermostatCooling.png", true, _channel->mainFunctionValue());
        break;
    case ThermostatMode::ThermostatModeAutoHeatingCooling:
        _screen.SetModeText("Auto");
        _screen.SetMainIndicatorImage("thermostatAuto.png", true, _channel->mainFunctionValue());
        break;
    default:
        break;
    }
}
void ThermostatDeviceBridge::setCurrentState(ThermostatCurrentState currentState)
{
    _screen.SetCurrentState(currentState);
}