#pragma once
#include "../Pages/DetailDevicePage.h"
#include "RGB/KnxChannelRGB.h"
#include "../Screens/RGBScreen.h"

class RGBDeviceBridge : public RGBBridge
{
    IRGBScreen& _screen = *IRGBScreen::instance;
    DetailDevicePage& _detailDevicePage;

    void buttonClicked();
    void colorChanged(uint32_t rgb);
  
public:
    RGBDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~RGBDeviceBridge() override;

    void setup(uint8_t channelIndex) override;
    void setRGB(uint32_t rgb) override;
    void setPower(bool on) override;

 
    virtual void mainFunctionValueChanged() override;
};