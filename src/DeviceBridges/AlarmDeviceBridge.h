#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Alarm/KnxChannelAlarm.h"
#include "../Screens/AlarmScreen.h"

class AlarmDeviceBridge : public AlarmBridge
{
    DetailDevicePage& _detailDevicePage;
    AlarmScreen& _screen = *AlarmScreen::instance;
public:
    AlarmDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~AlarmDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setDetected(bool detected) override;
    virtual void mainFunctionValueChanged() override;
};  