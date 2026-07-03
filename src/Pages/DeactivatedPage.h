#pragma once
#include "Page.h"
#include "Screens/IMessageScreen.h"


class DeactivatedPage : public Page
{
    IMessageScreen& screen = *IMessageScreen::instance;
protected:
    virtual const char* pageType() override;
    virtual void setup() override;
    virtual std::string name() override;
    virtual std::string image() override;
};
