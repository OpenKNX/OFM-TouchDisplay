#include "MediaDeviceBridge.h"
#include "../ImageLoader.h"

MediaDeviceBridge::MediaDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void MediaDeviceBridge::setup(uint8_t _channelIndex)
{
    lv_label_set_text(_screen.label, _channel->getNameInUTF8());
    _eventSliderReleased =[](lv_event_t *e) { ((MediaDeviceBridge*) lv_event_get_user_data(e))->sliderReleased(); };
    lv_obj_add_event_cb(_screen.slider, _eventSliderReleased, LV_EVENT_RELEASED, this);
    _eventSliderPressing = [](lv_event_t *e) { ((MediaDeviceBridge*) lv_event_get_user_data(e))->sliderPressing(); };
    lv_obj_add_event_cb(_screen.slider, _eventSliderPressing, LV_EVENT_PRESSING, this);
    _eventButtonPressed = [](lv_event_t *e) { ((MediaDeviceBridge*) lv_event_get_user_data(e))->buttonClicked(); };
    lv_obj_add_event_cb(_screen.image, _eventButtonPressed , LV_EVENT_CLICKED, this);
    _eventButtonPreviousPressed = [](lv_event_t *e) { ((MediaDeviceBridge*) lv_event_get_user_data(e))->buttonPrevious(); };
    lv_obj_add_event_cb(_screen.buttonPrevious, _eventButtonPreviousPressed , LV_EVENT_CLICKED, this);
    _eventButtonNextPressed = [](lv_event_t *e) { ((MediaDeviceBridge*) lv_event_get_user_data(e))->buttonNext(); };
    lv_obj_add_event_cb(_screen.buttonNext, _eventButtonNextPressed , LV_EVENT_CLICKED, this);

    mainFunctionValueChanged();
    _screen.show();
}

MediaDeviceBridge::~MediaDeviceBridge()
{
    if (_eventSliderReleased != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.slider, _eventSliderReleased, this);
    if (_eventSliderPressing != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.slider, _eventSliderPressing, this);
    if (_eventButtonPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.image, _eventButtonPressed, this);
    if (_eventButtonPreviousPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.buttonPrevious, _eventButtonPreviousPressed, this);
    if (_eventButtonNextPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.buttonNext, _eventButtonNextPressed, this);
}

void MediaDeviceBridge::setVolume(uint8_t volume)
{
    if (_lastSliderPressing != 0)
        return;
    lv_arc_set_value(_screen.slider, volume);  
}

void MediaDeviceBridge::setPlay(bool play)
{
    ImageLoader::loadImage(_screen.image, _channel->mainFunctionImage().imageFile, _channel->mainFunctionImage().allowRecolor, play); 
}
void MediaDeviceBridge::setTitle(const char* text)
{
  
}

void MediaDeviceBridge::sliderReleased()
{    
    _lastSliderPressing = 0;
    auto value = lv_arc_get_value(_screen.slider);
    if (_lastSendValue == value)
        return;
    _lastSendValue = 255;
    _channel->commandVolume(nullptr,  value);
}

void MediaDeviceBridge::sliderPressing()
{    
    if (_lastSliderPressing != 0 && millis() - _lastSliderPressing < 200)
        return;
    _lastSliderPressing = max(1L, millis());
    auto value = lv_arc_get_value(_screen.slider);
    if (_lastSendValue == value)
        return;
    _lastSendValue = value;
    _channel->commandVolume(nullptr,  value);
}

void MediaDeviceBridge::buttonClicked()
{    
    _channel->commandMainFunctionClick();   
}

void MediaDeviceBridge::buttonPrevious()
{
    _channel->commandPrevious(nullptr);
}

void MediaDeviceBridge::buttonNext()
{
    _channel->commandNext(nullptr);
}

void MediaDeviceBridge::mainFunctionValueChanged()
{
    lv_label_set_text(_screen.title, _channel->currentValueAsString().c_str());
}