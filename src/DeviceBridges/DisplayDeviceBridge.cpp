#include "DisplayDeviceBridge.h"

DisplayDeviceBridge::DisplayDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void DisplayDeviceBridge::setup(uint8_t _channelIndex)
{   
    _screen.SetLabelText(_channel->getNameInUTF8());
    mainFunctionValueChanged();
    _screen.Show();
}

DisplayDeviceBridge::~DisplayDeviceBridge()
{
}

void DisplayDeviceBridge::setValue(double value)
{
}

void DisplayDeviceBridge::setValue(const char* value)
{
}

void DisplayDeviceBridge::mainFunctionValueChanged() 
{
    auto& device = *_channel;
    _screen.SetValueText(device.currentValueAsString().c_str());
    _screen.SetMainIndicatorImage(device.mainFunctionImage().imageFile.c_str(), device.mainFunctionImage().allowRecolor, device.mainFunctionValue());
}
 

