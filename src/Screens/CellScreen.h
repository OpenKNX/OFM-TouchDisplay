#pragma once
#include "Screen.h"
class CellObject;

class CellScreen: public Screen
{
public:
    virtual CellObject& getCell(uint8_t index) = 0;
};

enum CellLocation
{
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight,
    Top,
    Bottom
};

class CellObject
{
    CellScreen& _cellPage;
    lv_coord_t _width;
    lv_coord_t _height;
public:
    lv_obj_t* cell;
    lv_obj_t* label;
    lv_obj_t* value;
    lv_obj_t* image;
    CellObject(CellScreen& cellPage, lv_coord_t width, lv_coord_t height, CellLocation cellLocation);
};


class CellScreen2: public CellScreen
{
public:
    static CellScreen2* instance;
    CellObject cellObject1;
    CellObject cellObject2;
    CellScreen2();
    virtual CellObject& getCell(uint8_t index) override;
};

class CellScreen3 : public CellScreen
{
public:
    static CellScreen3* instance;
    CellObject cellObject1;
    CellObject cellObject2;
    CellObject cellObject3;
    CellScreen3();
    virtual CellObject& getCell(uint8_t index) override;
};

class CellScreen4: public CellScreen
{
public:
    static CellScreen4* instance;
    CellObject cellObject1;
    CellObject cellObject2;
    CellObject cellObject3;
    CellObject cellObject4;
    CellScreen4();
    virtual CellObject& getCell(uint8_t index) override;
};


