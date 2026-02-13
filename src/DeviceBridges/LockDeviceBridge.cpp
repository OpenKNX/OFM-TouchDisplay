#include "LockDeviceBridge.h"
#include "../ImageLoader.h"

LockDeviceBridge::LockDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void LockDeviceBridge::setup(uint8_t _channelIndex)
{   
    // <Enumeration Value="0" Id="%ENID%" Text="Nach links"                       />
    // <Enumeration Value="1" Id="%ENID%" Text="Nach rechts"                      />
    _lockOpenDirection = ParamBRI_CHLockDirection;


    lv_label_set_text(_screen.label, _channel->getNameInUTF8());
    
    _eventIconPressed = [](lv_event_t *e) { ((LockDeviceBridge*) lv_event_get_user_data(e))->imageClicked(); };
    lv_obj_add_event_cb(_screen.image, _eventIconPressed, LV_EVENT_CLICKED, this);
    
    ImageLoader::loadImage(_screen.blocked, "alert.png");
    ImageLoader::colorImage(_screen.blocked, 255, 0, 0);
    lv_obj_add_flag(_screen.blocked, LV_OBJ_FLAG_HIDDEN);
    ImageLoader::unloadImage(_screen.movement);
    mainFunctionValueChanged();
    _screen.show();
}

LockDeviceBridge::~LockDeviceBridge()
{
    if (_eventIconPressed != nullptr)
        lv_obj_remove_event_cb_with_user_data(_screen.image, _eventIconPressed, this);
}

void LockDeviceBridge::setLocked(bool lock)
{
    // Ignored, because handled in mainFunctionValueChanged via main function image and value
}

void LockDeviceBridge::setBlocked(bool blocked)
{
    logDebugP("Set blocked: %d", blocked);
    if (blocked)
    {
        lv_obj_clear_flag(_screen.blocked, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(_screen.blocked, LV_OBJ_FLAG_HIDDEN);
    }
}

void LockDeviceBridge::setUnlocking(bool unlocking)
{
    logDebugP("Set unlocking: %d", unlocking);
    if (unlocking)
    {
        // <Enumeration Value="0" Id="%ENID%" Text="links"                       />
        // <Enumeration Value="1" Id="%ENID%" Text="rechts"                      />
        if (_lockOpenDirection)
            ImageLoader::loadImage(_screen.movement, "rotate_l.png", true, true);
        else
            ImageLoader::loadImage(_screen.movement, "rotate_r.png", true, true);
       
    }
    else
    {
        ImageLoader::unloadImage(_screen.movement);
    }
}

void LockDeviceBridge::setLocking(bool locking)
{
    logDebugP("Set locking: %d", locking);
    if (locking)
    {
        // <Enumeration Value="0" Id="%ENID%" Text="links"                       />
        // <Enumeration Value="1" Id="%ENID%" Text="rechts"                      />
        if (_lockOpenDirection)
            ImageLoader::loadImage(_screen.movement, "rotate_r.png", true, true);
        else
            ImageLoader::loadImage(_screen.movement, "rotate_l.png", true, true);  
    }
    else
    {
        ImageLoader::unloadImage(_screen.movement);
    }
}


void LockDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    ImageLoader::loadImage(_screen.image, image.imageFile, image.allowRecolor, power);
    lv_label_set_text(_screen.value, device.currentValueAsString().c_str());
}

void LockDeviceBridge::imageClicked()
{    
    _channel->commandMainFunctionClick();
}