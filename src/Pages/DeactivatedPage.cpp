#include "DeactivatedPage.h"

const char* DeactivatedPage::pageType()
{
    return "Deactivated";
}

void DeactivatedPage::setup()
{
    screen.SetLabelText("");
    screen.SetMessageText("Seite ist deaktiviert");
    screen.Show();
}

std::string DeactivatedPage::name()
{
    return "";
}

std::string DeactivatedPage::image()
{
    return "";
}