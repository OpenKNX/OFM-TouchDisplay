#pragma once
#include "Page.h"
#include "../Screens/DateTimeScreen.h"

class DateTimePage : public Page
{
    DateTimeScreen& _screen = *DateTimeScreen::instance;
    bool _lastValid = false;   
    uint16_t _lastYear = 0;
    uint8_t _lastMonth = 0;
    uint8_t _lastHour = 0;
    uint8_t _lastMinute = 0;

    lv_event_cb_t _eventPressed = nullptr;
    bool _clickStarted = false;
    void shortPressed() override;
    void longPressed() override;
    void resetPressed() override;  
    void handleClick(int function, uint8_t jumpToPage, uint8_t device);

protected:
    virtual const char* pageType() override;
    virtual void setup() override;
    virtual void loop(bool configured) override;
    void updateTime(bool forceUpdate);
    const char* dayOfWeekString(uint8_t dayOfWeek);
    virtual std::string name() override;
    virtual std::string image() override;
public:
    ~DateTimePage();
};