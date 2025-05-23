#include "DimmerScreen.h"

DimmerScreen* DimmerScreen::instance = nullptr;

DimmerScreen::DimmerScreen()
{
    slider = lv_arc_create(screen);
    lv_obj_set_width(slider, 200);
    lv_obj_set_height(slider, 200);
    lv_obj_set_align(slider, LV_ALIGN_CENTER);
    lv_arc_set_value(slider, 0);
    lv_arc_set_bg_angles(slider, 160, 20);
    lv_arc_set_range(slider, 0, 100);
    lv_obj_set_style_arc_width(slider, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
   
    image = lv_img_create(screen);     
    lv_obj_align(image, LV_ALIGN_CENTER, 0, -32);  
    lv_obj_add_flag(image, LV_OBJ_FLAG_CLICKABLE); 

    value = lv_label_create(screen);
    lv_obj_set_width(value, LV_SIZE_CONTENT); 
    lv_obj_set_height(value, LV_SIZE_CONTENT); 
    lv_obj_set_align(value, LV_ALIGN_CENTER);
    lv_obj_align(value, LV_ALIGN_CENTER, 0, 34);  
    lv_obj_set_style_text_font(value, &Monserat40WithGermanLetters, LV_PART_MAIN | LV_STATE_DEFAULT); 
}
  