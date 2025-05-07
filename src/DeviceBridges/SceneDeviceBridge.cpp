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
    lv_obj_add_event_cb(_screen.image, _eventButtonPressed , LV_EVENT_CLICKED, this);

    mainFunctionValueChanged();
    _screen.show();
}

SceneDeviceBridge::~SceneDeviceBridge()
{
    if (_eventButtonPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.image, _eventButtonPressed, this);
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
    _channel->commandMainFunctionClick();   
}