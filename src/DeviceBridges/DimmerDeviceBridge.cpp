#include "DimmerDeviceBridge.h"

#include <cstdio>

DimmerDeviceBridge::DimmerDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void DimmerDeviceBridge::setup(uint8_t _channelIndex)
{
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterPercentageChangeCompleted([this](uint8_t) { sliderReleased(); });
    _screen.RegisterPercentageChanged([this](uint8_t) { sliderPressing(); });
    _screen.RegisterPrimaryAction([this]() { buttonClicked(); });

    mainFunctionValueChanged();
    _screen.Show();
}

DimmerDeviceBridge::~DimmerDeviceBridge()
{
    _screen.RegisterPercentageChangeCompleted(nullptr);
    _screen.RegisterPercentageChanged(nullptr);
    _screen.RegisterPrimaryAction(nullptr);
}

void DimmerDeviceBridge::setBrightness(uint8_t brightness)
{
    if (_lastSliderPressing != 0)
        return;
    _screen.SetPercentageValue(brightness);
    _screen.SetMainIndicatorImage(_channel->mainFunctionImage().imageFile.c_str(), _channel->mainFunctionImage().allowRecolor, brightness != 0);
    updateText(); 
}

void DimmerDeviceBridge::updateText()
{
    char text[8];
    std::snprintf(text, sizeof(text), "%u%%", _screen.GetPercentageValue());
    _screen.SetValueText(text);
}

void DimmerDeviceBridge::sliderReleased()
{    
    _lastSliderPressing = 0;
    auto value = _screen.GetPercentageValue();
    if (_lastSendValue == value)
        return;
    _lastSendValue = 255;
    _channel->commandBrightness(nullptr,  value);
    updateText();
}

void DimmerDeviceBridge::sliderPressing()
{    
    if (_lastSliderPressing != 0 && millis() - _lastSliderPressing < 200)
        return;
    _lastSliderPressing = max(1UL, millis());
    auto value = _screen.GetPercentageValue();
    if (_lastSendValue == value)
        return;
    _lastSendValue = value;
    _channel->commandBrightness(nullptr,  value);
    updateText();
}

void DimmerDeviceBridge::buttonClicked()
{    
    _channel->commandMainFunctionClick();   
}

void DimmerDeviceBridge::mainFunctionValueChanged()
{
    
}