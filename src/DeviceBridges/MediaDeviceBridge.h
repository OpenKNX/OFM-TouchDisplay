
#pragma once
#include "../Pages/DetailDevicePage.h"
#include "Media/KnxChannelMedia.h"
#include "../Screens/MediaScreen.h"


class MediaDeviceBridge : public MediaBridge
{
    DetailDevicePage& _detailDevicePage;
    IMediaScreen& _screen = *IMediaScreen::instance;
    unsigned long _lastSliderPressing = 0;
    uint8_t _lastSendValue = 255;
public:
    MediaDeviceBridge(DetailDevicePage& detailDevicePage);
    virtual ~MediaDeviceBridge() override;
    virtual void setup(uint8_t _channelIndex) override;
    virtual void setVolume(uint8_t volume) override;
    virtual void setPlay(bool play) override;
    virtual void setTitle(const char* text) override;
    void percentageChangeCompleted();
    void percentageChanged();
    void buttonClicked();
    void buttonPrevious();
    void buttonNext();
    virtual void mainFunctionValueChanged() override;
};  