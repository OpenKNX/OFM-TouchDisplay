#pragma once

#include "ScreenWithLabel.h"

class SceneScreen: public ScreenWithLabel
{
    public:
    static SceneScreen* instance;
    lv_obj_t* value;
    lv_obj_t* image;


    SceneScreen();
};