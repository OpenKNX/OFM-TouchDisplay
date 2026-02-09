#include "LockScreen.h"

LockScreen* LockScreen::instance = nullptr;

LockScreen::LockScreen() 
{
   
    image = lv_img_create(screen);  
    lv_obj_align(image, LV_ALIGN_CENTER, 0, -15); 
    lv_obj_add_flag(image, LV_OBJ_FLAG_CLICKABLE); 

    blocked = lv_img_create(screen);  
  
    movement = lv_img_create(screen);  
   
    value = lv_label_create(screen);
    lv_obj_set_width(value, LV_SIZE_CONTENT);  
    lv_obj_set_height(value, LV_SIZE_CONTENT); 
    lv_obj_set_align(value, LV_ALIGN_CENTER);
    lv_obj_align(value, LV_ALIGN_CENTER, 0, 40);  
    lv_obj_set_style_text_font(value, &FONT_LARGE, LV_PART_MAIN | LV_STATE_DEFAULT); 

}
