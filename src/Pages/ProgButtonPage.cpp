#include "ProgButtonPage.h"
#include "DisplayLed.h"
#include "OpenKNX.h"


const char* ProgButtonPage::pageType()
{
    return "ProgButton";
}

void ProgButtonPage::buttonClicked()
{
    knx.progMode(!knx.progMode());
}


ProgButtonPage::~ProgButtonPage()
{
    DisplayLed::led1->setLedObject(nullptr);
    DisplayLed::led2->setLedObject(nullptr);
    DisplayLed::led3->setLedObject(nullptr);
    _screen.RegisterPrimaryAction(nullptr);
}


void ProgButtonPage::loop(bool configured)
{
    if (_progMode != knx.progMode())
    {
        _progMode = knx.progMode();
        updateButtonState();
    }
}

void ProgButtonPage::updateButtonState()
{
    _screen.SetPrimaryActionChecked(_progMode);
}

void ProgButtonPage::setup()
{
    _screen.ConnectLed(0, DisplayLed::led1);
    _screen.ConnectLed(1, DisplayLed::led2);
    _screen.ConnectLed(2, DisplayLed::led3);
   
   
    auto label = openknx.info.humanIndividualAddress();
    if (label == "15.15.255")
        label = (const char*) u8"Keine Adresse";
    _screen.SetLabelText(label.c_str());
    
    std::string message;
    message += "v" + openknx.info.humanFirmwareVersion() + "   " + openknx.info.humanFirmwareNumber().c_str();
    message += "\nOpenKNX ";
#ifdef OPENKNX_DISPLAY_NAME
    message += OPENKNX_DISPLAY_NAME;
#else
    message += MAIN_FirmwareName;
#endif
    if (!knx.configured())
        message += (const char*)u8"\nBitte übertragen Sie die\nETS Applikation";
    _screen.SetMessageText(message.c_str());
    _screen.SetButtonText((const char*)u8"Programmier Modus");

    _screen.RegisterPrimaryAction([this]() { buttonClicked(); });
 
    _progMode = knx.progMode();
    updateButtonState();
    _screen.Show();
}

std::string ProgButtonPage::name()
{
    return (const char*) u8"System";
}

std::string ProgButtonPage::image()
{
    return "System.png";
}

