#pragma once
#include "OpenKNX.h"

class TouchDisplayScreenFactory
{
public:
    virtual ~TouchDisplayScreenFactory() = default;
    virtual void createScreens() = 0;
    virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) = 0;
    virtual void removeBackgroundColor() = 0;
};

TouchDisplayScreenFactory& touchDisplayScreenFactory();