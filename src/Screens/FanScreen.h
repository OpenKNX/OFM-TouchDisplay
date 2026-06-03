#pragma once

#include <functional>

#include "ScreenWithLabel.h"

class IFanScreen
{
public:
    virtual ~IFanScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetAutomaticVisible(bool visible) = 0;
    virtual void SetAutomaticState(bool automatic) = 0;
    virtual void RegisterAutomaticAction(std::function<void()> callback) = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};

class FanScreen: public ScreenWithLabel
               , public IFanScreen
{
private:
    lv_obj_t* _buttonAuto;
    lv_obj_t* _buttonAutoLabel;
    lv_obj_t* _image;
    lv_obj_t* _value;
    std::function<void()> _onAutomaticAction;
    std::function<void()> _onMainAction;

    static void OnAutomaticAction(lv_event_t* e);
    static void OnMainAction(lv_event_t* e);

public:
    static FanScreen* instance;

    FanScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void SetAutomaticVisible(bool visible) override;
    virtual void SetAutomaticState(bool automatic) override;
    virtual void RegisterAutomaticAction(std::function<void()> callback) override;
    virtual void RegisterMainAction(std::function<void()> callback) override;
    virtual void Show() override;
};