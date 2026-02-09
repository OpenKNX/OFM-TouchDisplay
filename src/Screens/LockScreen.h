#pragma once

#include "ScreenWithLabel.h"


class LockScreen: public ScreenWithLabel
{
public:
    static LockScreen* instance;
    lv_obj_t* image;
    lv_obj_t* value;
    lv_obj_t* blocked;
    lv_obj_t* movement;
    LockScreen();
 
};