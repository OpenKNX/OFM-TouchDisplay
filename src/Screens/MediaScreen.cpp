#include "MediaScreen.h"
#include "../ImageLoader.h"

MediaScreen* MediaScreen::instance = nullptr;

MediaScreen::MediaScreen()
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
    lv_obj_align(image, LV_ALIGN_TOP_MID, 0, 56);  
    lv_obj_add_flag(image, LV_OBJ_FLAG_CLICKABLE); 

    title = lv_label_create(screen);
    lv_obj_set_width(title, LV_SIZE_CONTENT); 
    lv_obj_set_height(title, LV_SIZE_CONTENT); 
    lv_obj_set_align(title, LV_ALIGN_CENTER);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 119);  

    buttonPrevious = lv_img_create(screen);
    ImageLoader::loadImage(buttonPrevious, "left.png", true, false);
    lv_obj_add_flag(buttonPrevious, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_align(buttonPrevious, LV_ALIGN_TOP_MID, -30, 140);  
   
    buttonNext = lv_img_create(screen);
    ImageLoader::loadImage(buttonNext, "right.png", true, false);
    lv_obj_add_flag(buttonNext, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_align(buttonNext, LV_ALIGN_TOP_MID, 30, 140);  
}
  