#include "JalousieScreen.h"
#include "../ImageLoader.h"


JalousieScreen* JalousieScreen::instance = nullptr;

JalousieScreen::JalousieScreen()
{
    sliderSlat = lv_slider_create(screen);
    lv_obj_set_size(sliderSlat, 25, 110);
    lv_obj_add_flag(sliderSlat, LV_OBJ_FLAG_CLICKABLE);
#if LVGL_VERSION_MAJOR < 9
    lv_slider_set_range(sliderSlat, 0, 100);  
#else
    lv_slider_set_range(sliderSlat, 100, 0);
#endif
    lv_obj_align(sliderSlat, LV_ALIGN_RIGHT_MID, -35, -10);     
}
