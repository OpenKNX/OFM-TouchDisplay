
#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Media/KnxChannelMedia.h"
#include "../Screens/MediaScreen.h"


class MediaDeviceBridge : public MediaBridge
{
    lv_event_cb_t _eventSliderReleased = nullptr;
    lv_event_cb_t _eventSliderPressing = nullptr;
    lv_event_cb_t _eventButtonPressed = nullptr;
    lv_event_cb_t _eventButtonPreviousPressed = nullptr;
    lv_event_cb_t _eventButtonNextPressed = nullptr;

    DetailDevicePage& _detailDevicePage;
    MediaScreen& _screen = *MediaScreen::instance;
    unsigned long _lastSliderPressing = 0;
    uint8_t _lastSendValue = 255;
public:
    MediaDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~MediaDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setVolume(uint8_t volume) override;
    virtual void setPlay(bool play) override;
    virtual void setTitle(const char* text) override;
    void sliderReleased();
    void sliderPressing();
    void buttonClicked();
    void buttonPrevious();
    void buttonNext();
    virtual void mainFunctionValueChanged() override;
};  