
#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Dimmer/KnxChannelDimmer.h"
#include "../Screens/IDimmerScreen.h"


class DimmerDeviceBridge : public DimmerBridge
{
    DetailDevicePage& _detailDevicePage;
    IDimmerScreen& _screen = *IDimmerScreen::instance;
    unsigned long _lastSliderPressing = 0;
    uint8_t _lastSendValue = 255;
public:
    DimmerDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~DimmerDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setBrightness(uint8_t brightness) override;
    void sliderReleased();
    void sliderPressing();
    void buttonClicked();
    void updateText();
    virtual void mainFunctionValueChanged() override;
};  
