#pragma once

#include <functional>
#include "ScreenWithLabel.h"

class ISwitchScreen
{
public:
    virtual ~ISwitchScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void RegisterPrimaryAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};

class SwitchScreen: public ScreenWithLabel
                  , public ISwitchScreen
{
private:
    lv_obj_t* _value;
    lv_obj_t* _image;
    std::function<void()> _onPrimaryAction;

    static void OnPrimaryAction(lv_event_t* e);

public:
    static SwitchScreen* instance;

    SwitchScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void RegisterPrimaryAction(std::function<void()> callback) override;
    virtual void Show() override;
};