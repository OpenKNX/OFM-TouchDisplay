#include "AlarmDeviceBridge.h"

AlarmDeviceBridge::AlarmDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void AlarmDeviceBridge::setup(uint8_t _channelIndex)
{   
    _screen.SetLabelText(_channel->getNameInUTF8());
    mainFunctionValueChanged();
    _screen.setUseRedBackgroundForAlarm(_channel->isUseRedBackgroundForAlarm());
    _screen.Show();
}

AlarmDeviceBridge::~AlarmDeviceBridge()
{
}

void AlarmDeviceBridge::setDetected(bool detected)
{
    _screen.setAlarm(detected);    
}

void AlarmDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    _screen.SetMainIndicatorImage(device.mainFunctionImage().imageFile.c_str(), device.mainFunctionImage().allowRecolor, device.mainFunctionValue());
    _screen.SetValueText(device.currentValueAsString().c_str());
}
