#pragma once

#include "ScreenWithLabel.h"

class MediaScreen: public ScreenWithLabel
{
    public:
    static MediaScreen* instance;
    lv_obj_t* slider;
    lv_obj_t* title;
    lv_obj_t* image;
    lv_obj_t* buttonPrevious;
    lv_obj_t* buttonNext;


    MediaScreen();
};