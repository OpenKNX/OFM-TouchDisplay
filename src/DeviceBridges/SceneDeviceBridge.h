
#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Scene/KnxChannelScene.h"
#include "../Screens/SceneScreen.h"


class SceneDeviceBridge : public SceneBridge
{
    lv_event_cb_t _eventButtonPressed = nullptr;
    DetailDevicePage& _detailDevicePage;
    SceneScreen& _screen = *SceneScreen::instance;
public:
    SceneDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~SceneDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setActivating(bool activating) override;
    virtual void mainFunctionValueChanged() override;
  
    void released();
    void buttonClicked();
    void updateText();
};  