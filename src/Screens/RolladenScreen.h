#pragma once

#include <functional>

#include "ScreenWithLabel.h"

class IRolladenScreen
{
public:
    virtual ~IRolladenScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetPercentageValue(uint8_t value) = 0;
    virtual uint8_t GetPercentageValue() const = 0;
    virtual void SetDirectionalActionState(bool primaryActive, bool secondaryActive) = 0;
    virtual void RegisterPrimaryAction(std::function<void()> callback) = 0;
    virtual void RegisterSecondaryAction(std::function<void()> callback) = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) = 0;
    virtual void Show() = 0;
};

class RolladenScreen: public ScreenWithLabel
                    , public IRolladenScreen
{
private:
    lv_obj_t* _image;
    lv_obj_t* _value;
    lv_obj_t* _buttonPrimary;
    lv_obj_t* _buttonSecondary;
    lv_obj_t* _percentageInput;
    std::function<void()> _onPrimaryAction;
    std::function<void()> _onSecondaryAction;
    std::function<void()> _onMainAction;
    std::function<void(uint8_t)> _onPercentageChangeCompleted;

    static void OnPrimaryAction(lv_event_t* e);
    static void OnSecondaryAction(lv_event_t* e);
    static void OnMainAction(lv_event_t* e);
    static void OnPercentageChangeCompleted(lv_event_t* e);

public:
    static RolladenScreen* instance;

    RolladenScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void SetPercentageValue(uint8_t value) override;
    virtual uint8_t GetPercentageValue() const override;
    virtual void SetDirectionalActionState(bool primaryActive, bool secondaryActive) override;
    virtual void RegisterPrimaryAction(std::function<void()> callback) override;
    virtual void RegisterSecondaryAction(std::function<void()> callback) override;
    virtual void RegisterMainAction(std::function<void()> callback) override;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) override;
    virtual void Show() override;
};