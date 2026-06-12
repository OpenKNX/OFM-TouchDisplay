#include "JumpCell.h"
#include "CellParameterDefines.h"
#include "../Screens/CellScreen.h"
#include "../TouchDisplayModule.h"
#include "../Pages/Page.h"
#include "../ImageLoader.h"

const char* JumpCell::cellType()
{
    return "Jump";
}

JumpCell::~JumpCell()
{
    if (_cellObject != nullptr)
        _cellObject->RegisterClicked(nullptr);
}

void JumpCell::setup()
{
    ICellObject& cellObject = *_cellObject;
    cellObject.RegisterClicked([this]() { _clicked = true; });
  
    logDebug("JumpCell", "Setup JumpCell %d", (int) ParamTCH_CHJumpToShort1 - 1); 
    Page* page = Page::createPage(ParamTCH_CHJumpToShort1 - 1);
    logDebug("JumpCell", "Setup JumpCell %s", page->name().c_str()); 
    cellObject.SetLabelText(page->name().c_str());
    cellObject.SetImage(page->image().c_str(), true, false);
    delete page;
    cellObject.SetValueText("");
}

void JumpCell::loop(bool configured)
{
    Cell::loop(configured);
    if (_clicked)
    {
        _clicked = false;
        clicked();
    }
}

void JumpCell::clicked()
{
    openknxTouchDisplayModule.activatePage(ParamTCH_CHJumpToShort1);
}