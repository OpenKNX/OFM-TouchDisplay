#include "SceneDeviceBridge.h"

SceneDeviceBridge::SceneDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void SceneDeviceBridge::setup(uint8_t _channelIndex)
{
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterPrimaryActionPressed([this]() { buttonClicked(); });
    _screen.RegisterPrimaryActionReleased([this]() { released(); });
    

    mainFunctionValueChanged();
    _screen.Show();
}

SceneDeviceBridge::~SceneDeviceBridge()
{
    _screen.RegisterPrimaryActionPressed(nullptr);
    _screen.RegisterPrimaryActionReleased(nullptr);
}

void SceneDeviceBridge::setActivating(bool activating)
{

}

void SceneDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    _screen.SetMainIndicatorImage(image.imageFile.c_str(), image.allowRecolor, power);
    _screen.SetValueText(device.currentValueAsString().c_str());
}


void SceneDeviceBridge::buttonClicked()
{    
    auto& device = *_channel;
    auto _channelIndex = device.channelIndex();
    if (ParamBRI_CHSceneLearn)
        _lastButtonPressTime = millis();
    else
        device.commandMainFunctionClick();
}

void SceneDeviceBridge::released()
{
    if (_lastButtonPressTime != 0)
    {
        if (millis() - _lastButtonPressTime < 1000)
        {
            _channel->commandMainFunctionClick();   
        }
        else
        {
            _channel->setMessage("Abgebrochen");
        }
        _lastButtonPressTime = 0;
    }
}

void SceneDeviceBridge::loop()
{
    if (_lastButtonPressTime != 0)
    { 
        unsigned long pressDuration = millis() - _lastButtonPressTime;
        if (pressDuration >= 1000)
        {
            int countDown = max(0, 3 - (int) ((pressDuration - 1000) / 1000));
            if (countDown != _storeCountDown)
            {
                _storeCountDown = countDown;
                if (countDown == 0)
                {
                    // Store scene
                    _channel->learnScene();
                    _lastButtonPressTime = 0;
                    _storeCountDown = 0;
                    _channel->setMessage("Gespeichert");
                }
                else
                {
                    char buffer[20];
                    snprintf(buffer, sizeof(buffer), "Speichern in %ds", countDown);
                    _screen.SetValueText(buffer);
                }
            }
        }
    }
 
}