#include "AlarmDeviceBridge.h"
#include "../ImageLoader.h"

AlarmDeviceBridge::AlarmDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void AlarmDeviceBridge::setup(uint8_t _channelIndex)
{   
    lv_label_set_text(_screen.label, _channel->getNameInUTF8());
    mainFunctionValueChanged();
    _screen.show();
}

AlarmDeviceBridge::~AlarmDeviceBridge()
{
}

void AlarmDeviceBridge::setDetected(bool detected)
{
    
}

void AlarmDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    ImageLoader::loadImage(_screen.image, device.mainFunctionImage().imageFile, device.mainFunctionImage().allowRecolor, device.mainFunctionValue());
    lv_label_set_text(_screen.value, device.currentValueAsString().c_str());
}
