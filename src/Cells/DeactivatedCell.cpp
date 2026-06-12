#include "DeactivatedCell.h"
#include "CellParameterDefines.h"
#include "../Screens/CellScreen.h"
#include "../ImageLoader.h"

const char* DeactivatedCell::cellType()
{
    return "Deactivated";
}

void DeactivatedCell::setup()
{
    ICellObject& cellObject = *_cellObject;
    cellObject.SetLabelText("Deaktiviert");
    cellObject.ClearImage();
    cellObject.SetValueText("");
}