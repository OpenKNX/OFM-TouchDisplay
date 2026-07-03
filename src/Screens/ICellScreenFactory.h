#pragma once
#include "OpenKNX.h"

class ICellScreen;

class ICellScreenFactory
{
public:
    static ICellScreenFactory* instance;
    virtual ICellScreen* getCellScreen(uint8_t numberOfCells) = 0;
    
};
