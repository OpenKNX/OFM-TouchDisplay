
#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Scene/KnxChannelScene.h"
#include "../Screens/ISceneScreen.h"


class SceneDeviceBridge : public SceneBridge
{
    unsigned long _lastButtonPressTime = 0;
    DetailDevicePage& _detailDevicePage;
    ISceneScreen& _screen = *ISceneScreen::instance;
    int _storeCountDown = 0;
public:
    SceneDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~SceneDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setActivating(bool activating) override;
    virtual void mainFunctionValueChanged() override;
  
    void released();
    void buttonClicked();
    void updateText();
    void loop() override;
};  
