#pragma once
#include "../Pages/DetailDevicePage.h"
#include "DoorWindow/KnxChannelDoorWindow.h"
#include "../Screens/DoorWindowScreen.h"

class DoorWindowDeviceBridge : public DoorWindowBridge
{
    lv_event_cb_t _eventIconPressed = nullptr;
    lv_event_cb_t _eventSliderReleased = nullptr;
    DetailDevicePage& _detailDevicePage;
    DoorWindowScreen& _screen = *DoorWindowScreen::instance;
    bool _automatic = false;
    uint8_t _doorWindowOpenDirection = 0;
 public:
    DoorWindowDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~DoorWindowDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setPosition(uint8_t position) override;
    virtual void setMovement(DoorWindowMoveState movement) override;
    virtual void setObstructionDetected(bool obstructionDetected) override;
    virtual void mainFunctionValueChanged() override;
    void sliderReleased();
    void imageClicked();
};