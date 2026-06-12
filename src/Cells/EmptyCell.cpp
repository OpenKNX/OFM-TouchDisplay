#include "EmptyCell.h"
#include "CellParameterDefines.h"
#include "../Screens/CellScreen.h"
#include "../ImageLoader.h"

const char* EmptyCell::cellType()
{
    return "Empty";
}

void EmptyCell::setup()
{
    ICellObject& cellObject = *_cellObject;
    cellObject.SetLabelText("");
    cellObject.ClearImage();
    cellObject.SetValueText("");
}