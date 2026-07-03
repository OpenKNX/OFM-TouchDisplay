#pragma once
#include "OpenKNX.h"

class ICellObject;

class ICellScreen
{
public:
    virtual ICellObject& getCell(uint8_t index) = 0;  
    virtual void show() = 0;
};
