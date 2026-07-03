#include "CellPage.h"
#include "Cells/Cell.h"
#include "Screens/ICellScreen.h"
#include "Screens/ICellObject.h"
#include "Screens/ICellScreenFactory.h"
#include "ISO8859_15ToUTF8.h"

const char* CellPage::pageType()
{
    return "Cell";
}

void CellPage::setup()
{
    _numberOfCells = ParamTCH_CHNumbeOfFields;
    logDebugP("setup %d cells", (int) _numberOfCells);
    if (_numberOfCells == 0)
    {
        errorInSetup(name().c_str(), "Seite hat keine Felder");
        return;
    }
    _screen = ICellScreenFactory::instance->getCellScreen(_numberOfCells);
    if (_screen == nullptr)
    {
        errorInSetup(name().c_str(), "Zellenanzahl nicht unterstützt");
        return;
    }
  
    _cells = new Cell*[_numberOfCells];    
    for (size_t cellIndex = 0; cellIndex < _numberOfCells; cellIndex++)
    {
        logDebugP("Get cell object %d", cellIndex);
        ICellObject& cellObject =  _screen->getCell(cellIndex);
        _cells[cellIndex] = Cell::createCell(_channelIndex, cellIndex, cellObject);
    }
    for (size_t cellIndex = 0; cellIndex < _numberOfCells; cellIndex++)
    {
        logDebugP("Setup cell");
        _cells[cellIndex]->setup();
    }
    _screen->show();

}

void CellPage::loop(bool configured)
{
    Page::loop(configured);
    if (_cells == nullptr)
        return;
    for (size_t cellIndex = 0; cellIndex < _numberOfCells; cellIndex++)
    {
        _cells[cellIndex]->loop(configured);
    }
}

void CellPage::shortPressed()
{
    if (_cells == nullptr)
        return;
    for (size_t cellIndex = 0; cellIndex < _numberOfCells; cellIndex++)
    {
        _cells[cellIndex]->shortPressed();
    }
}

void CellPage::longPressed()
{
    if (_cells == nullptr)
        return;
    for (size_t cellIndex = 0; cellIndex < _numberOfCells; cellIndex++)
    {
        _cells[cellIndex]->longPressed();
    }
}


void CellPage::resetPressed()
{
    if (_cells == nullptr)
        return;
    for (size_t cellIndex = 0; cellIndex < _numberOfCells; cellIndex++)
    {
        _cells[cellIndex]->resetPressed();
    }
}

CellPage::~CellPage()
{
    if (_cells == nullptr)
        return;
    for (uint8_t i = 0; i < _numberOfCells; i++)
    {
        delete _cells[i];
    }
    delete[] _cells;
}

std::string CellPage::name()
{
    char* pageName1252 = (char *) ParamTCH_CHPageName;
    const char* utf8 = convertISO8859_15ToUTF8(pageName1252);
    auto result = std::string(utf8);
    if (pageName1252 != utf8)
        free((void*) utf8);
    return result;
}

std::string CellPage::image()
{
    uint8_t icon = ParamTCH_CHIconSelection;
    if (icon == 0)
    {
        // custom icon
        auto name = (const char*)ParamTCH_CHIconName;

        return std::string(name, 8) + ".png";
    }
    if (icon > 99)
    {
        // icon out of range
        return std::string("Type") + std::to_string(icon / 10) + "_" + std::to_string(icon % 100) + ".png";
    }
    return std::string("Type") + std::to_string(icon) + ".png";
}
