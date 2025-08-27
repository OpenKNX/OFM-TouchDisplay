#include "DateTimeScreen.h"

DateTimeScreen* DateTimeScreen::instance = nullptr;

DateTimeScreen::DateTimeScreen()
{
    weekday = lv_label_create(screen);
    lv_obj_set_width(weekday, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(weekday, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(weekday, 0);
    lv_obj_set_y(weekday, -60);
    lv_obj_set_align(weekday, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(weekday, &FONT_MEDIUM, LV_PART_MAIN | LV_STATE_DEFAULT); 
  
  
    date = lv_label_create(screen);
    lv_obj_set_width(date, LV_SIZE_CONTENT); 
    lv_obj_set_height(date, LV_SIZE_CONTENT);
    lv_obj_set_x(date, 0);
    lv_obj_set_y(date, -30);
    lv_obj_set_align(date, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(date, &FONT_MEDIUM, LV_PART_MAIN | LV_STATE_DEFAULT); 
  
  
    time = lv_label_create(screen);
    lv_obj_set_width(time, LV_SIZE_CONTENT);
    lv_obj_set_height(time, LV_SIZE_CONTENT);
    lv_obj_set_x(time, 0);
    lv_obj_set_y(time, 30);
    lv_obj_set_align(time, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(time, &FONT_LARGE, LV_PART_MAIN | LV_STATE_DEFAULT); 
  
    message = lv_label_create(screen);
    lv_obj_set_width(message, 250);
    lv_obj_set_height(message, LV_SIZE_CONTENT);
    lv_label_set_long_mode(message, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_align(message, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_align(message, LV_ALIGN_CENTER);
  
}