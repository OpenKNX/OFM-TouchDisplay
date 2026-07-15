#include "DeviceMainFunctionCell.h"
#include "CellParameterDefines.h"
#include "SmartHomeBridgeModule.h"
#include "../ImageLoader.h"
#include "../TouchDisplayModule.h"

const char* DeviceMainFunctionCell::cellType()
{
    return "DeviceMainFunction";
}

DeviceMainFunctionCell::~DeviceMainFunctionCell()
{
    if (_device != nullptr)
        _device->removeChangedHandler(_handler);
    if (_cellObject != nullptr)
        _cellObject->RegisterPressed(nullptr);
}

void DeviceMainFunctionCell::init(KnxChannelBase* device, uint8_t deviceIndex)
{
    _device = device;
    _deviceIndex = deviceIndex;
}

void DeviceMainFunctionCell::setup()
{
    KnxChannelBase& device = *_device;
    ICellObject& cellObject = *_cellObject;
    cellObject.SetLabelText(device.getNameInUTF8());
    cellObject.SetPreferValueDisplay(device.mainFunctionPreferValueDisplay());
    
    cellObject.RegisterPressed([this]() { _clickStarted = true; });
 
    cellObject.SetLabelText(device.getNameInUTF8());
    cellObject.SetValueText("");
    cellObject.ClearImage();

    _handler = [this](KnxChannelBase& channel)
    {
       channelValueChanged(channel);
    };
    device.addChangedHandler(_handler);

}


void DeviceMainFunctionCell::channelValueChanged(KnxChannelBase& channel)
{
    ICellObject& cellObject = *_cellObject;
    const std::string valueText = channel.currentValueAsString();
    const auto image = channel.mainFunctionImage();
    cellObject.SetValueText(valueText.c_str());
    cellObject.SetMainFunctionImage(image.imageFile.c_str(), image.allowRecolor, channel.mainFunctionValue());
}

void DeviceMainFunctionCell::shortPressed()
{
    if (_clickStarted)
        handleClick(ParamTCH_CHShortPressDevice1, ParamTCH_CHJumpToShort1, ParamTCH_CHDeviceShort1);
}

void DeviceMainFunctionCell::resetPressed()
{
    _clickStarted = false;
}

void DeviceMainFunctionCell::longPressed()
{
    if (_clickStarted)
        handleClick(ParamTCH_CHLongPressDevice1, ParamTCH_CHJumpToLong1, ParamTCH_CHDeviceLong1);
}

void DeviceMainFunctionCell::handleClick(int function, uint8_t jumpToPage, uint8_t device)
{
    // <Enumeration Text="Nichts" Value="0" Id="%ENID%" />          
    // <Enumeration Text="Hauptfunktion ausführen" Value="1" Id="%ENID%" />
    // <Enumeration Text="Detailseite aufrufen" Value="2" Id="%ENID%" />
    // <Enumeration Text="Absprung zu Seite" Value="3" Id="%ENID%" />
    // <Enumeration Text="Hauptfunktion anderes Gerät ausführen" Value="4" Id="%ENID%" />
    switch(function)
    {
    case 0:
        logDebugP("Nichts");
        return;
    case 1:    
        logDebugP("Hauptfunktion");
        if (_device->supportMainFunctionClick())
            _device->commandMainFunctionClick();
        return;
    case 2:
        logDebugP("Detailseite");
        openknxTouchDisplayModule.showDetailDevicePage(_channelIndex, _deviceIndex);
        return;
    case 3:
        logDebugP("Absprung zu Seite %d", jumpToPage);
        openknxTouchDisplayModule.activatePage(jumpToPage);
        return;
    case 4:
        logDebugP("Hauptfunktion von Geräte %d", device);
        auto deviceBridge = openknxSmartHomeBridgeModule.getChannel(device - 1);
        if (deviceBridge != nullptr)
        {
            deviceBridge->commandMainFunctionClick();
        }
        else
        {
            logErrorP("Device %d not found", device);
        }
        return;
    }
}

