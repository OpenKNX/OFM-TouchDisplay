#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Fan/KnxChannelFan.h"
#include "../Screens/FanScreen.h"

class FanDeviceBridge : public FanBridge
{
    DetailDevicePage& _detailDevicePage;
    IFanScreen& _screen = *IFanScreen::instance;
    bool _automatic = false;
 public:
    FanDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~FanDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setPower(bool on) override;
    virtual void setAutomatic(bool automatic) override;
    virtual void mainFunctionValueChanged() override;
    void buttonClicked();
    void imageClicked();
};