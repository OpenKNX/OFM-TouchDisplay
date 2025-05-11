#include "DoorWindowDeviceBridge.h"
#include "../ImageLoader.h"

DoorWindowDeviceBridge::DoorWindowDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void DoorWindowDeviceBridge::setup(uint8_t _channelIndex)
{   
    _doorWindowOpenDirection = ParamBRI_CHDoorWindowOpenDirection;
    // <Enumeration Value="0" Id="%ENID%" Text="Nach links"                       />
    // <Enumeration Value="1" Id="%ENID%" Text="Nach rechts"                      />
    // <Enumeration Value="2" Id="%ENID%" Text="Mittig auseinander links/rechts"  />
    // <Enumeration Value="3" Id="%ENID%" Text="Nach oben"                        />
    // <Enumeration Value="4" Id="%ENID%" Text="Nach unten"                       />
    // <Enumeration Value="5" Id="%ENID%" Text="Mittig auseinander oben/unten"    />
    switch (_doorWindowOpenDirection)
    {
        case 0:
            _screen.setSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_LEFT);
            break;
        case 1:
            _screen.setSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_RIGHT);
            break;
        case 2:
            _screen.setSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_LEFT_RIGHT);
            break;
        case 3:
            _screen.setSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_UP);
            break;
        case 4:
            _screen.setSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_DOWN);
            break;
        case 5:
            _screen.setSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_UP_DOWN);
            break;
    }

    if (ParamBRI_CHDoorWindowMotor)
    {
        lv_obj_clear_flag(_screen.slider, LV_OBJ_FLAG_HIDDEN);
        if (ParamBRI_CHDoorWindowUsePercent)
            lv_obj_set_style_bg_opa(_screen.slider, LV_OPA_COVER, LV_PART_KNOB);
        else
            lv_obj_set_style_bg_opa(_screen.slider, LV_OPA_TRANSP, LV_PART_KNOB);
    }
    else
        lv_obj_add_flag(_screen.slider, LV_OBJ_FLAG_HIDDEN);
    
    lv_label_set_text(_screen.label, _channel->getNameInUTF8());
    
    _eventIconPressed = [](lv_event_t *e) { ((DoorWindowDeviceBridge*) lv_event_get_user_data(e))->imageClicked(); };
    lv_obj_add_event_cb(_screen.image, _eventIconPressed, LV_EVENT_CLICKED, this);
    _eventSliderReleased = [](lv_event_t *e) { ((DoorWindowDeviceBridge*) lv_event_get_user_data(e))->sliderReleased(); };
    lv_obj_add_event_cb(_screen.slider, _eventSliderReleased, LV_EVENT_RELEASED, this);
    
    ImageLoader::loadImage(_screen.obstruction, "alert.png");
    ImageLoader::colorImage(_screen.obstruction, 255, 0, 0);
    lv_obj_add_flag(_screen.obstruction, LV_OBJ_FLAG_HIDDEN);
    ImageLoader::unloadImage(_screen.movement);
    mainFunctionValueChanged();
    _screen.show();

}

DoorWindowDeviceBridge::~DoorWindowDeviceBridge()
{
    if (_eventIconPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.image, _eventIconPressed, this);
    if (_eventSliderReleased != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.image, _eventSliderReleased, this);
}

void DoorWindowDeviceBridge::setPosition(uint8_t position)
{
    lv_slider_set_value(_screen.slider, position, LV_ANIM_ON);
}

void DoorWindowDeviceBridge::setMovement(DoorWindowMoveState movement)
{
    switch (movement)
    {
        // <Enumeration Value="0" Id="%ENID%" Text="Nach links"                       />
        // <Enumeration Value="1" Id="%ENID%" Text="Nach rechts"                      />
        // <Enumeration Value="2" Id="%ENID%" Text="Mittig auseinander links/rechts"  />
        // <Enumeration Value="3" Id="%ENID%" Text="Nach oben"                        />
        // <Enumeration Value="4" Id="%ENID%" Text="Nach unten"                       />
        // <Enumeration Value="5" Id="%ENID%" Text="Mittig auseinander oben/unten"    />
        case DoorWindowMoveState::DoorWindowMoveStateOpening:
            switch (_doorWindowOpenDirection)
            {
                case 0:
                    ImageLoader::loadImage(_screen.movement, "opening_l.png", true, true);
                    break;
                case 1:
                    ImageLoader::loadImage(_screen.movement, "opening_r.png", true, true);
                    break;
                case 2:
                    ImageLoader::loadImage(_screen.movement, "opening_lr.png", true, true);
                    break;
                case 3:
                    ImageLoader::loadImage(_screen.movement, "opening_u.png", true, true);
                    break;
                case 4:
                    ImageLoader::loadImage(_screen.movement, "opening_d.png", true, true);
                    break;
                case 5:
                    ImageLoader::loadImage(_screen.movement, "opening_up.png", true, true);
                    break;
            }
            break;
        case DoorWindowMoveState::DoorWindowMoveStateClosing:
            switch (_doorWindowOpenDirection)
            {
                case 0:
                    ImageLoader::loadImage(_screen.movement, "closing_l.png", true, true);
                    break;
                case 1:
                    ImageLoader::loadImage(_screen.movement, "closing_r.png", true, true);
                    break;
                case 2:
                    ImageLoader::loadImage(_screen.movement, "closing_lr.png", true, true);
                    break;
                case 3:
                    ImageLoader::loadImage(_screen.movement, "closing_u.png", true, true);
                    break;
                case 4:
                    ImageLoader::loadImage(_screen.movement, "closing_d.png", true, true);
                    break;
                case 5:
                    ImageLoader::loadImage(_screen.movement, "closing_up.png", true, true);
                    break;
            }
            break;
        case DoorWindowMoveState::DoorWindowMoveStateHold:
            ImageLoader::unloadImage(_screen.movement);
            break;
    }
}

void DoorWindowDeviceBridge::sliderReleased()
{
    auto& device = *_channel;
    int32_t value = lv_slider_get_value(_screen.slider);
    device.commandPosition(nullptr, value);
}

void DoorWindowDeviceBridge::setObstructionDetected(bool obstructionDetected)
{
    if (obstructionDetected)
    {
        lv_obj_clear_flag(_screen.obstruction, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(_screen.obstruction, LV_OBJ_FLAG_HIDDEN);
    }
}

void DoorWindowDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    ImageLoader::loadImage(_screen.image, image.imageFile, image.allowRecolor, power);
    lv_label_set_text(_screen.value, device.currentValueAsString().c_str());
}

void DoorWindowDeviceBridge::imageClicked()
{    
    _channel->commandMainFunctionClick();
}