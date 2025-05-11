#pragma once

#include "ScreenWithLabel.h"

enum DoorWindowSliderDirection
{
    DOOR_WINDOW_SLIDER_LEFT = 0,
    DOOR_WINDOW_SLIDER_RIGHT,
    DOOR_WINDOW_SLIDER_LEFT_RIGHT,
    DOOR_WINDOW_SLIDER_UP,
    DOOR_WINDOW_SLIDER_DOWN,
    DOOR_WINDOW_SLIDER_UP_DOWN
};

class DoorWindowScreen: public ScreenWithLabel
{
public:
    static DoorWindowScreen* instance;
    lv_obj_t* slider;
    lv_obj_t* image;
    lv_obj_t* value;
    lv_obj_t* obstruction;
    lv_obj_t* movement;
    DoorWindowScreen();
    void setSliderDirection(DoorWindowSliderDirection direction);    
};