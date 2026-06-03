#include "FanDeviceBridge.h"

FanDeviceBridge::FanDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void FanDeviceBridge::setup(uint8_t _channelIndex)
{   
    _screen.SetAutomaticVisible(ParamBRI_CHFanAutomatic);
 
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterAutomaticAction([this]() { buttonClicked(); });
    _screen.RegisterMainAction([this]() { imageClicked(); });

    mainFunctionValueChanged();
    _screen.Show(); 
}

FanDeviceBridge::~FanDeviceBridge()
{
    _screen.RegisterAutomaticAction(nullptr);
    _screen.RegisterMainAction(nullptr);
}

void FanDeviceBridge::setAutomatic(bool automatic)
{
    _automatic = automatic;
    _screen.SetAutomaticState(automatic);
}

void FanDeviceBridge::setPower(bool power)
{

}

void FanDeviceBridge::buttonClicked()
{
    auto& device = *_channel;
    device.commandAutomatic(nullptr, !_automatic);
}

void FanDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    _screen.SetMainIndicatorImage(image.imageFile.c_str(), image.allowRecolor, power);
    _screen.SetValueText(device.currentValueAsString().c_str());
}

void FanDeviceBridge::imageClicked()
{    
    _channel->commandMainFunctionClick();
}