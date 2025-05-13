#include "DoorWindowScreen.h"

DoorWindowScreen* DoorWindowScreen::instance = nullptr;

DoorWindowScreen::DoorWindowScreen() 
{
    slider = lv_slider_create(screen);
   
    image = lv_img_create(screen);  
    lv_obj_align(image, LV_ALIGN_CENTER, 0, -15); 
    lv_obj_add_flag(image, LV_OBJ_FLAG_CLICKABLE); 

    obstruction = lv_img_create(screen);  
  
    movement = lv_img_create(screen);  
   
    value = lv_label_create(screen);
    lv_obj_set_width(value, LV_SIZE_CONTENT);  
    lv_obj_set_height(value, LV_SIZE_CONTENT); 
    lv_obj_set_align(value, LV_ALIGN_CENTER);
    lv_obj_align(value, LV_ALIGN_CENTER, 0, 40);  
    lv_obj_set_style_text_font(value, &Monserat40WithGermanLetters, LV_PART_MAIN | LV_STATE_DEFAULT); 

    setSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_LEFT);
   
}

void DoorWindowScreen::setSliderDirection(DoorWindowSliderDirection direction) 
{
    switch (direction)
    {
        case DOOR_WINDOW_SLIDER_LEFT:
            lv_obj_align(slider, LV_ALIGN_TOP_MID, 0, 40);  
            lv_obj_set_size(slider, 138, 25);
            lv_slider_set_range(slider, 0, 100);
            lv_obj_align(obstruction, LV_ALIGN_CENTER, 73, -15);  
            lv_obj_align(movement, LV_ALIGN_CENTER, -73, -15);  
            break;
        case DOOR_WINDOW_SLIDER_RIGHT:
            lv_obj_align(slider, LV_ALIGN_TOP_MID, 0, 40);  
            lv_obj_set_size(slider, 138, 25);
            lv_slider_set_range(slider, 100, 0);
            lv_obj_align(obstruction, LV_ALIGN_CENTER, 73, -15);  
            lv_obj_align(movement, LV_ALIGN_CENTER, -73, -15);  
            break;
        case DOOR_WINDOW_SLIDER_LEFT_RIGHT:
            lv_obj_align(slider, LV_ALIGN_TOP_MID, 0, 40); 
            lv_obj_set_size(slider, 138, 25);
            lv_slider_set_range(slider, 0, 100);
            lv_obj_align(obstruction, LV_ALIGN_CENTER, 73, -15);  
            lv_obj_align(movement, LV_ALIGN_CENTER, -73, -15);  
            break;
        case DOOR_WINDOW_SLIDER_UP:
            lv_obj_align(slider, LV_ALIGN_RIGHT_MID, -40, -40);  
            lv_obj_set_size(slider, 138, 25);
            lv_obj_set_size(slider, 25, 80);
            
            lv_slider_set_range(slider, 0, 100);

            lv_obj_align(obstruction, LV_ALIGN_TOP_MID, 0, 15);  
            lv_obj_align(movement, LV_ALIGN_CENTER, -73, -15);  
            break;
        case DOOR_WINDOW_SLIDER_DOWN:
            lv_obj_align(slider, LV_ALIGN_RIGHT_MID, 40, -40);  
            lv_obj_set_size(slider, 25, 80);
            lv_slider_set_range(slider, 100, 0);
            lv_obj_align(obstruction, LV_ALIGN_TOP_MID, 0, 15);  
            lv_obj_align(movement, LV_ALIGN_CENTER, -73, -15);  
            break;
        case DOOR_WINDOW_SLIDER_UP_DOWN:
            lv_obj_align(slider, LV_ALIGN_RIGHT_MID, 40, -40); 
            lv_obj_set_size(slider, 25, 80);
            lv_slider_set_range(slider, 0, 100);
            lv_obj_align(obstruction, LV_ALIGN_TOP_MID, 0, 15);  
            lv_obj_align(movement, LV_ALIGN_CENTER, -73, -15);  
            break;
    }
}