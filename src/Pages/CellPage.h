#pragma once
#include "Page.h"

class Cell;
class ICellScreen;

class CellPage : public Page
{
protected:
    Cell** _cells;
    uint8_t _numberOfCells;
    ICellScreen* _screen;
    virtual const char* pageType() override; 
    virtual void setup() override;
    virtual void loop(bool configured) override;
public:
    virtual ~CellPage();
    virtual std::string name() override;
    virtual std::string image() override;
    void shortPressed() override;
    void longPressed() override;
    void resetPressed() override;
};

