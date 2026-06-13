#pragma once
#include "../Pages/DetailDevicePage.h"
#include "RolladenDeviceBridge.h"
#include "Jalousie/KnxChannelJalousie.h"
#include "../Screens/JalousieScreen.h"

class JalousieDeviceBridge : public RolladenDeviceBridge
{
    IJalousieScreen& _jalousieScreen = *JalousieScreen::instance;
    void auxPercentageChangeCompleted();
    
 public:
    JalousieDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~JalousieDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setSlatPosition(uint8_t position) override;
    
};  