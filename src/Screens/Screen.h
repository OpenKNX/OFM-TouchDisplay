#pragma once
#include "lvgl.h"

class Screen
{
    static bool _blackBackground;
public:
    lv_obj_t *screen;

public:
    static void blackBackground(bool black);
    Screen();
    void show();
    virtual ~Screen();
};