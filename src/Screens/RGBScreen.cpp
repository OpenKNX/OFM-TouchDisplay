#include "RGBScreen.h"
#include "OpenKNX.h"

RGBScreen* RGBScreen::instance = nullptr;

RGBScreen::RGBScreen()
{
    value = lv_label_create(screen);
    lv_obj_set_width(value, LV_SIZE_CONTENT); 
    lv_obj_set_height(value, LV_SIZE_CONTENT);
    lv_obj_set_align(value, LV_ALIGN_RIGHT_MID);
    lv_obj_align(value, LV_ALIGN_RIGHT_MID, -115, -20);  
    lv_obj_set_style_text_font(value, &Monserat40WithGermanLetters, LV_PART_MAIN | LV_STATE_DEFAULT); 
  
    image = lv_img_create(screen);  
    lv_obj_align(image, LV_ALIGN_CENTER, 40, -20);  
    lv_obj_add_flag(image, LV_OBJ_FLAG_CLICKABLE);

    currentColor = lv_arc_create(screen);
    lv_obj_set_size(currentColor, 240, 240);
    lv_arc_set_range(currentColor,0, 100);
    lv_arc_set_value(currentColor, 0);
    lv_arc_set_bg_angles(currentColor, 0, 360);
    lv_obj_remove_style(currentColor, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(currentColor, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/
    lv_obj_align(currentColor, LV_ALIGN_CENTER, 0, 0);
    
    lv_style_init(&colorStyle);
    lv_style_set_arc_color(&colorStyle, lv_color_make(128,128,128)); 
    lv_style_set_arc_width(&colorStyle, 10);
    lv_obj_add_style(currentColor, &colorStyle, LV_PART_MAIN);

    lv_event_cb_t _eventHandleChanged =[](lv_event_t *e) { ((RGBScreen*) lv_event_get_user_data(e))->colorChanged(e); };
  
    const int32_t hueSliderWidth = 170;
    const int32_t heuSliderPosY = 40;

    static const int canvasWidth = hueSliderWidth;
    static lv_color_t canvas_buf[canvasWidth];

    int canvasHight = 16;
    for (size_t i = 0; i < canvasHight; i++)
    {
        lv_obj_t* canvas = lv_canvas_create(screen);
        lv_canvas_set_buffer(canvas, canvas_buf, canvasWidth, 1, LV_COLOR_FORMAT_NATIVE);
        lv_obj_align(canvas, LV_ALIGN_CENTER, 0, heuSliderPosY + i - canvasHight / 2);

        // Fill canvas with hue gradient
        for (int x = 0; x < canvasWidth; x++) {
            lv_color_hsv_t hsv;
            hsv.h = (x * 359) / canvasWidth;;    // Hue (0-359)
            hsv.s = 100; 
            hsv.v = 100;
            lv_color_t color = lv_color_hsv_to_rgb(hsv.h, hsv.s, hsv.v);
            lv_canvas_set_px(canvas, x, 0, color, LV_OPA_COVER);
        }
    }

    hueSlider = lv_slider_create(screen);
    lv_obj_set_size(hueSlider, hueSliderWidth, 25);
    lv_slider_set_range(hueSlider, 0, 359);
    lv_obj_align(hueSlider, LV_ALIGN_CENTER, 0, heuSliderPosY);  
    lv_obj_add_event_cb(hueSlider, _eventHandleChanged, LV_EVENT_RELEASED, this);
    lv_obj_add_event_cb(hueSlider, _eventHandleChanged, LV_EVENT_PRESSING, this);
    lv_obj_set_style_bg_opa(hueSlider, LV_OPA_TRANSP, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(hueSlider, LV_OPA_TRANSP, LV_PART_MAIN);
  

    lv_obj_set_style_border_width(hueSlider, 6, LV_PART_KNOB); 
    lv_obj_set_style_border_color(hueSlider, lv_obj_get_style_bg_color(hueSlider, LV_PART_KNOB), LV_PART_KNOB);
    lv_obj_set_style_bg_opa(hueSlider, LV_OPA_TRANSP, LV_PART_KNOB);
  


    const int32_t diameterBrigtnessAndSaturation = 220;
    brightnessSlider = lv_arc_create(screen);
    lv_obj_set_width(brightnessSlider, diameterBrigtnessAndSaturation);
    lv_obj_set_height(brightnessSlider, diameterBrigtnessAndSaturation);
    lv_obj_set_align(brightnessSlider, LV_ALIGN_CENTER);
    lv_arc_set_value(brightnessSlider, 0);
    lv_arc_set_bg_angles(brightnessSlider, 180, 260);
    lv_arc_set_range(brightnessSlider, 0, 100);
    lv_obj_set_style_arc_width(brightnessSlider, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_flag(brightnessSlider, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_add_event_cb(brightnessSlider, _eventHandleChanged, LV_EVENT_RELEASED, this);
    lv_obj_add_event_cb(brightnessSlider, _eventHandleChanged, LV_EVENT_PRESSING, this); 
    lv_arc_set_mode(brightnessSlider, LV_ARC_MODE_REVERSE);
  
    lv_obj_set_style_border_width(brightnessSlider, 6, LV_PART_KNOB); 
    lv_obj_set_style_border_color(brightnessSlider, lv_obj_get_style_bg_color(brightnessSlider, LV_PART_KNOB), LV_PART_KNOB);
    lv_obj_set_style_bg_color(brightnessSlider, lv_color_make(0,0,0), LV_PART_KNOB);
  


    saturationSlider = lv_arc_create(screen);
    lv_obj_set_width(saturationSlider, diameterBrigtnessAndSaturation);
    lv_obj_set_height(saturationSlider, diameterBrigtnessAndSaturation);
    lv_obj_set_align(saturationSlider, LV_ALIGN_CENTER);
    lv_arc_set_value(saturationSlider, 0);
    lv_arc_set_bg_angles(saturationSlider, 290, 0);
    lv_arc_set_range(saturationSlider, 0, 100);
    lv_obj_set_style_arc_width(saturationSlider, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_flag(saturationSlider, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_add_event_cb(saturationSlider, _eventHandleChanged, LV_EVENT_RELEASED, this);
    lv_obj_add_event_cb(saturationSlider, _eventHandleChanged, LV_EVENT_PRESSING, this);

    lv_obj_set_style_border_width(saturationSlider, 6, LV_PART_KNOB); 
    lv_obj_set_style_border_color(saturationSlider, lv_obj_get_style_bg_color(saturationSlider, LV_PART_KNOB), LV_PART_KNOB);
    lv_obj_set_style_bg_color(saturationSlider, lv_color_make(255,255,255), LV_PART_KNOB);
  
}

void RGBScreen::setRGB(uint8_t r, uint8_t g, uint8_t b) 
{
    if (isPressed) {
        return;
    }
    red = r;
    green = g;
    blue = b;
    auto lv_color_hsv_t = lv_color_rgb_to_hsv(r, g, b);
   
    updateColor();
    updateSlider(r, g, b);
}

bool RGBScreen::isDeviationGreaterThanOne(uint8_t current, uint8_t newValue) {
    int diff = static_cast<int>(current) - static_cast<int>(newValue);
    return std::abs(diff) > 1;
}
void RGBScreen::colorChanged(lv_event_t* e)
{
    isPressed = lv_event_get_code(e) == LV_EVENT_PRESSING;
    auto hue = lv_slider_get_value(hueSlider);
    auto saturation = 100 - lv_arc_get_value(saturationSlider);
    auto brightness = 100 - lv_arc_get_value(brightnessSlider);
    auto color = lv_color_hsv_to_rgb(hue, saturation, brightness);
#if LVGL_VERSION_MAJOR >= 9
    uint8_t r = color.red;
    uint8_t g = color.green;
    uint8_t b = color.blue;
#else
    uint8_t r = color.ch.red;
    uint8_t g = color.ch.green;
    uint8_t b = color.ch.blue;
#endif
    if (isDeviationGreaterThanOne(red, r) || isDeviationGreaterThanOne(green, g) || isDeviationGreaterThanOne(blue, b)) {
        logError("RGBScreen", "Color changed: %d %d %d", (int) static_cast<int>(red) - static_cast<int>(r), (int) static_cast<int>(green) - static_cast<int>(g), (int) static_cast<int>(blue) - static_cast<int>(b));
        red = r;
        green = g;
        blue = b;
        updateColor();
    }
    else {
        logError("RGBScreen", "Color not changed");
    }
}

void RGBScreen::updateSlider(uint8_t r, uint8_t g, uint8_t b)
{
    auto hsv = lv_color_rgb_to_hsv(r, g, b);
    logError("RGBScreen", "RGB: %d %d %d, HSV: %d %d %d", (int) r, (int)g, (int)b, (int)hsv.h, (int)hsv.s, (int)hsv.v);
    lv_arc_set_value(brightnessSlider, 100 - hsv.v);
    lv_arc_set_value(saturationSlider, 100 - hsv.s);
    if (initialized)
    {
        if (r == 0 && g == 0 && b == 0 || (r == 255 && g == 255 && b == 255)) {
            return;
        }
    }
    initialized = true;
    lv_slider_set_value(hueSlider, hsv.h, LV_ANIM_OFF);
}

void RGBScreen::updateColor()
{
    lv_style_set_arc_color(&colorStyle, lv_color_make(red, green, blue));
    lv_obj_add_style(currentColor, &colorStyle, LV_PART_MAIN);
}
