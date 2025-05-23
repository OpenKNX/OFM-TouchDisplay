#include "MainFunctionPage.h"
#include "SmartHomeBridgeModule.h"
#include "../TouchDisplayModule.h"
#include "../ImageLoader.h"


MainFunctionPage::~MainFunctionPage()
{
    if (_device != nullptr)
        _device->removeChangedHandler(_handler);
   
    if (_eventPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.screen, _eventPressed, this);  
}

const char* MainFunctionPage::pageType()
{
    return "MainFunction";
}

KnxChannelBase* MainFunctionPage::getDevice()
{
    if (_device == nullptr)
        _device = openknxSmartHomeBridgeModule.getChannel(ParamTCH_CHDeviceSelection1 - 1);
    return _device;
}

void MainFunctionPage::setup()
{
    _device = getDevice();
    if (_device == nullptr)
    {
        char label[30];
        snprintf(label, sizeof(label), "Seite %d", _channelIndex + 1);
        char message[30];
        snprintf(message, sizeof(message), "Gerät %d ist deaktiviert", (int) ParamTCH_CHDeviceSelection1);
        errorInSetup(label, message);
        return;
    }
    auto& device = *_device;
    _eventPressed = [](lv_event_t *e) { ((MainFunctionPage*) lv_event_get_user_data(e))->_clickStarted = true; };
    lv_obj_add_event_cb(_screen.screen, _eventPressed, LV_EVENT_PRESSED, this);
    lv_label_set_text(_screen.label, device.getNameInUTF8());

    _handler = [this](KnxChannelBase& channel)
    {
       channelValueChanged(channel);
    };
    device.addChangedHandler(_handler);

    _screen.show();
}

void MainFunctionPage::channelValueChanged(KnxChannelBase& channel)
{
    lv_label_set_text(_screen.value, channel.currentValueAsString().c_str());
    MainFunctionStateImage image = channel.mainFunctionImage();
    ImageLoader::loadImage(_screen.image, image.imageFile, image.allowRecolor, channel.mainFunctionValue());
}

void MainFunctionPage::shortPressed()
{
    if (_clickStarted)
    {
        handleClick(ParamTCH_CHShortPressDevice1, ParamTCH_CHJumpToShort1, ParamTCH_CHDeviceShort1);
    }
}

void MainFunctionPage::longPressed()
{
    if (_clickStarted)
    {
        handleClick(ParamTCH_CHLongPressDevice1, ParamTCH_CHJumpToLong1, ParamTCH_CHDeviceLong1);
    }      
}

void MainFunctionPage::resetPressed()
{
    _clickStarted = false;
}
   

void MainFunctionPage::handleClick(int function, uint8_t jumpToPage, uint8_t device)
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
        openknxTouchDisplayModule.showDetailDevicePage(_channelIndex, ParamTCH_CHDeviceSelection1 - 1);
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

std::string MainFunctionPage::name()
{
    KnxChannelBase* device = getDevice();
    if (device != nullptr)
        return device->getNameInUTF8();
    return "Nicht definiert";
}

std::string MainFunctionPage::image()
{
    KnxChannelBase* device = getDevice();
    if (device != nullptr)
        return device->mainFunctionImage().imageFile; 
    return "";  
}