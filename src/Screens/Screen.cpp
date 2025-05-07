#include "Screen.h"

Screen::Screen()
{
    screen = lv_obj_create(NULL);
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
}

bool Screen::_blackBackground = false;

void Screen::blackBackground(bool black)
{
    _blackBackground = black;
}

void Screen::show()
{
    if (_blackBackground)
        lv_obj_set_style_bg_color(screen, lv_color_black(), 0);
    else
        lv_theme_apply(screen);
    lv_scr_load(screen);
}

Screen::~Screen()
{
    lv_obj_del(screen);
}