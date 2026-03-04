#include "DisplayLed.h"
#include "OpenKNX.h"

DisplayLed* DisplayLed::led1 = new DisplayLed();
DisplayLed* DisplayLed::led2 = new DisplayLed();
DisplayLed* DisplayLed::led3 = new DisplayLed();

void DisplayLed::initLeds()
{
    led1->init();
    led2->init();
    led3->init();
    openknx.leds.addLed(led1, OpenKNX::Led::LED_TYPE_INFO1);
    openknx.leds.addLed(led2, OpenKNX::Led::LED_TYPE_INFO2);
    openknx.leds.addLed(led3, OpenKNX::Led::LED_TYPE_INFO3);


}

void DisplayLed::handleLeds()
{
    led1->handlDipslayLed();
    led2->handlDipslayLed();
    led3->handlDipslayLed();
}

void DisplayLed::init()
{
    _initialized = true;
}

void DisplayLed::writeLed(uint8_t brightness)
{
    if (_brightness == brightness)
        return;
    _brightness = brightness;
    _brightnessChanged = true;
}
void DisplayLed::color(uint8_t r, uint8_t g, uint8_t b)
{
    if (_r == r && _g == g && _b == b)
        return;
    _r = r;
    _g = g;
    _b = b;
    _rgbChanged = true;
}

void DisplayLed::setLedObject(lv_obj_t *led)
{
    if (_led != nullptr)
    {
        lv_led_off(_led);
        lv_led_set_brightness(_led, 0);
        lv_led_set_color(_led, lv_color_make(128, 128, 128));
    }
    _led = led;
    _brightnessChanged = true;
    _rgbChanged = true;
}

void DisplayLed::handlDipslayLed()
{
    RGB::loop();
    lv_obj_t *led = _led;
    if (led == nullptr)
        return;
    if (_rgbChanged)
    {
        lv_led_set_color(_led, lv_color_make(_r, _g, _b));
        _rgbChanged = false;
    }
    if (_brightnessChanged)
    {
        lv_led_set_brightness(_led, _brightness);
        if (_brightness == 0)
            lv_led_off(_led);
        else
            lv_led_on(_led);
        _brightnessChanged = false;
    }
}