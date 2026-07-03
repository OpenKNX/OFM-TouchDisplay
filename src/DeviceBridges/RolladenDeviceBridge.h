#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Rolladen/KnxChannelRolladen.h"
#include "../Screens/IRolladenScreen.h"

class RolladenDeviceBridge : public RolladenBridge
{
    IRolladenScreen& _screen;
protected:
    DetailDevicePage& _detailDevicePage;
    RolladenDeviceBridge(IRolladenScreen& screen, DetailDevicePage& detailDevicePage);
 public:
    RolladenDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~RolladenDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setPosition(uint8_t position) override;
    virtual void setMovement(MoveState movement) override;
    virtual void mainFunctionValueChanged() override;

    void buttonUpPressed();
    void buttonDownPressed();
    void buttonMainFunctionPressed();
    void percentageChangeCompleted();
};  
