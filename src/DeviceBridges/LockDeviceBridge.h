#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Lock/KnxChannelLock.h"
#include "../Screens/LockScreen.h"

class LockDeviceBridge : public LockBridge
{
    lv_event_cb_t _eventIconPressed = nullptr;
    DetailDevicePage& _detailDevicePage;
    LockScreen& _screen = *LockScreen::instance;
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