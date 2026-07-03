#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Lock/KnxChannelLock.h"
#include "../Screens/ILockScreen.h"

class LockDeviceBridge : public LockBridge
{
    DetailDevicePage& _detailDevicePage;
    ILockScreen& _screen = *ILockScreen::instance;
    bool _automatic = false;
    uint8_t _lockOpenDirection = 0;
 public:
    LockDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~LockDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setLocked(bool lock) override;
    virtual void setBlocked(bool blocked) override;
    virtual void setUnlocking(bool unlocking) override;
    virtual void setLocking(bool locking) override;
    virtual void mainFunctionValueChanged() override;
    void imageClicked();
};
