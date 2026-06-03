#pragma once

#include "RolladenScreen.h"

class IJalousieAuxScreen
{
public:
    virtual ~IJalousieAuxScreen() = default;
    virtual void SetAuxPercentageValue(uint8_t value) = 0;
    virtual uint8_t GetAuxPercentageValue() const = 0;
    virtual void RegisterAuxPercentageChangeCompleted(std::function<void(uint8_t)> callback) = 0;
};


class JalousieScreen: public RolladenScreen
                   , public IJalousieAuxScreen
{
private:
    lv_obj_t* _sliderAux;
    std::function<void(uint8_t)> _onAuxPercentageChangeCompleted;

    static void OnAuxPercentageChangeCompleted(lv_event_t* e);

public:
    static JalousieScreen* instance;

    JalousieScreen();

    virtual void SetAuxPercentageValue(uint8_t value) override;
    virtual uint8_t GetAuxPercentageValue() const override;
    virtual void RegisterAuxPercentageChangeCompleted(std::function<void(uint8_t)> callback) override;
};