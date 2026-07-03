
#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Switch/KnxChannelSwitch.h"
#include "Screens/ISwitchScreen.h"


class SwitchDeviceBridge : public SwitchBridge
{
    DetailDevicePage& _detailDevicePage;
    ISwitchScreen& _screen = *ISwitchScreen::instance;
public:
    SwitchDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~SwitchDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setPower(bool on) override;
    virtual void mainFunctionValueChanged() override;
  
    void buttonClicked();
    void updateText();
};  
