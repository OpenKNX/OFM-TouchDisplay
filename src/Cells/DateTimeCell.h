#pragma once
#include "Cell.h"

class DateTimeCell : public Cell
{
    private:
        bool _showDate = false;
        bool _showTime = false;
        bool _lastValid = false;   
        uint16_t _lastYear = 0;
        uint8_t _lastMonth = 0;
        uint8_t _lastHour = 0;
        uint8_t _lastMinute = 0;
        lv_event_cb_t _eventPressed = nullptr;
        bool _clickStarted = false;
        virtual void shortPressed() override;
        virtual void longPressed() override;
        virtual void resetPressed() override;
        void handleClick(int function, uint8_t jumpToPage, uint8_t device);
    public:
        DateTimeCell(bool showDate, bool showTime);
        ~DateTimeCell();
    protected:
        virtual const char* cellType() override;
        virtual void setup() override;
        virtual void loop(bool configured) override;
        void updateTime(bool forceUpdate);
};