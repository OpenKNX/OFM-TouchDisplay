#include "SwitchDeviceBridge.h"

SwitchDeviceBridge::SwitchDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void SwitchDeviceBridge::setup(uint8_t _channelIndex)
{
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterPrimaryAction([this]() { buttonClicked(); });

    mainFunctionValueChanged();
    _screen.Show();
}

SwitchDeviceBridge::~SwitchDeviceBridge()
{
    _screen.RegisterPrimaryAction(nullptr);
}

void SwitchDeviceBridge::setPower(bool on)
{

}

void SwitchDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    _screen.SetMainIndicatorImage(image.imageFile.c_str(), image.allowRecolor, power);
    _screen.SetValueText(device.currentValueAsString().c_str());
}


void SwitchDeviceBridge::buttonClicked()
{    
    _channel->commandMainFunctionClick();   
}