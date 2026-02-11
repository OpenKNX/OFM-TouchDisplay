#include "SceneDeviceBridge.h"
#include "../ImageLoader.h"

SceneDeviceBridge::SceneDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void SceneDeviceBridge::setup(uint8_t _channelIndex)
{
    lv_label_set_text(_screen.label, _channel->getNameInUTF8());
 
    _eventButtonPressed = [](lv_event_t *e) { ((SceneDeviceBridge*) lv_event_get_user_data(e))->buttonClicked(); };
    lv_obj_add_event_cb(_screen.image, _eventButtonPressed , LV_EVENT_PRESSED, this);
    _eventButtonReleased = [](lv_event_t *e) { ((SceneDeviceBridge*) lv_event_get_user_data(e))->released(); };
    lv_obj_add_event_cb(_screen.image, _eventButtonReleased , LV_EVENT_RELEASED, this);
    

    mainFunctionValueChanged();
    _screen.show();
}

SceneDeviceBridge::~SceneDeviceBridge()
{
    if (_eventButtonPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.image, _eventButtonPressed, this);
    if (_eventButtonReleased != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.image, _eventButtonReleased, this);
}

void SceneDeviceBridge::setActivating(bool activating)
{

}

void SceneDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    ImageLoader::loadImage(_screen.image, image.imageFile, image.allowRecolor, power);
    lv_label_set_text(_screen.value, device.currentValueAsString().c_str());
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
                    lv_label_set_text(_screen.value, buffer);
                }
            }
        }
    }
 
}