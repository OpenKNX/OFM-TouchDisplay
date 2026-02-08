#pragma once
#include "OpenKNX.h"
#include <lvgl.h>

class DisplayLed : public OpenKNX::Led::RGB
{
public:
    static DisplayLed *led1;
    static DisplayLed *led2;
    static DisplayLed *led3;
    static void initLeds();
    static void handleLeds();

private:
    lv_obj_t *_led = nullptr;
    uint8_t _brightness = 0;
    uint8_t _r = 0;
    uint8_t _g = 0;
    uint8_t _b = 0;
    bool _rgbChanged = false;
    bool _brightnessChanged = false;
    virtual void init() override;
    void writeLed(uint8_t brightness);
    void color(uint8_t r, uint8_t g, uint8_t b);
    void handlDipslayLed();

public:
    void setLedObject(lv_obj_t *led);
};
