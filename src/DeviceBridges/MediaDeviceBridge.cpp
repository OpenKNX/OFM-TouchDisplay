#include "MediaDeviceBridge.h"

MediaDeviceBridge::MediaDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void MediaDeviceBridge::setup(uint8_t _channelIndex)
{
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterPercentageChangeCompleted([this](uint8_t) { percentageChangeCompleted(); });
    _screen.RegisterPercentageChanged([this](uint8_t) { percentageChanged(); });
    _screen.RegisterMainAction([this]() { buttonClicked(); });
    _screen.RegisterPreviousAction([this]() { buttonPrevious(); });
    _screen.RegisterNextAction([this]() { buttonNext(); });

    mainFunctionValueChanged();
    _screen.Show();
}

MediaDeviceBridge::~MediaDeviceBridge()
{
    _screen.RegisterPercentageChangeCompleted(nullptr);
    _screen.RegisterPercentageChanged(nullptr);
    _screen.RegisterMainAction(nullptr);
    _screen.RegisterPreviousAction(nullptr);
    _screen.RegisterNextAction(nullptr);
}

void MediaDeviceBridge::setVolume(uint8_t volume)
{
    if (_lastSliderPressing != 0)
        return;
    _screen.SetPercentageValue(volume);
}

void MediaDeviceBridge::setPlay(bool play)
{
    _screen.SetMainIndicatorImage(_channel->mainFunctionImage().imageFile.c_str(), _channel->mainFunctionImage().allowRecolor, play);
}
void MediaDeviceBridge::setTitle(const char* text)
{
  
}

void MediaDeviceBridge::percentageChangeCompleted()
{    
    _lastSliderPressing = 0;
    auto value = _screen.GetPercentageValue();
    if (_lastSendValue == value)
        return;
    _lastSendValue = 255;
    _channel->commandVolume(nullptr,  value);
}

void MediaDeviceBridge::percentageChanged()
{    
    if (_lastSliderPressing != 0 && millis() - _lastSliderPressing < 200)
        return;
    _lastSliderPressing = max(1UL, millis());
    auto value = _screen.GetPercentageValue();
    if (_lastSendValue == value)
        return;
    _lastSendValue = value;
    _channel->commandVolume(nullptr,  value);
}

void MediaDeviceBridge::buttonClicked()
{    
    _channel->commandMainFunctionClick();   
}

void MediaDeviceBridge::buttonPrevious()
{
    _channel->commandPrevious(nullptr);
}

void MediaDeviceBridge::buttonNext()
{
    _channel->commandNext(nullptr);
}

void MediaDeviceBridge::mainFunctionValueChanged()
{
    _screen.SetTitleText(_channel->currentValueAsString().c_str());
}