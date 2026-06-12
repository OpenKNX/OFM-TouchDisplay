#include "RGBDeviceBridge.h"

RGBDeviceBridge::RGBDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

RGBDeviceBridge::~RGBDeviceBridge()
{
    _screen.RegisterColorChangeCompleted(nullptr);
    _screen.RegisterMainAction(nullptr);
}

void RGBDeviceBridge::setup(uint8_t channelIndex)
{
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterColorChangeCompleted([this](uint32_t rgb) { colorChanged(rgb); });
    _screen.RegisterMainAction([this]() { buttonClicked(); });
 
    mainFunctionValueChanged();
    
    _screen.Show();
}

void RGBDeviceBridge::buttonClicked()
{
    auto& device = *_detailDevicePage.getDevice();
    device.commandMainFunctionClick();
}

void RGBDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_detailDevicePage.getDevice();
    auto image = device.mainFunctionImage();
    _screen.SetMainIndicatorImage(image.imageFile.c_str(), image.allowRecolor, device.mainFunctionValue());
    _screen.SetValueText(device.currentValueAsString().c_str());
}

void RGBDeviceBridge::colorChanged(uint32_t rgb)
{
    auto& device = *(KnxChannelRGB*) _detailDevicePage.getDevice();
    device.commandRGB(nullptr, rgb);
}

void RGBDeviceBridge::setRGB(uint32_t rgb)
{
    // Logic to set the RGB color
    uint8_t r = (rgb >> 16) & 0xFF;
    uint8_t g = (rgb >> 8) & 0xFF;
    uint8_t b = rgb & 0xFF;
    _screen.SetColorValue(r, g, b);
}

void RGBDeviceBridge::setPower(bool on)
{
    // Not used, becuase mainFunctionValueChanged is used
}