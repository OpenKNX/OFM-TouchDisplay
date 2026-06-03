#pragma once

#include <functional>
#include "ScreenWithLabel.h"

class IDimmerScreen
{
public:
    virtual ~IDimmerScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetPercentageValue(uint8_t value) = 0;
    virtual uint8_t GetPercentageValue() const = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void RegisterPercentageChanged(std::function<void(uint8_t)> callback) = 0;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) = 0;
    virtual void RegisterPrimaryAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};

class DimmerScreen: public ScreenWithLabel
                  , public IDimmerScreen
{
private:
    lv_obj_t* _percentageInput;
    lv_obj_t* _value;
    lv_obj_t* _primaryActionImage;
    std::function<void(uint8_t)> _onPercentageChanged;
    std::function<void(uint8_t)> _onPercentageChangeCompleted;
    std::function<void()> _onPrimaryAction;

    static void OnPercentageChanged(lv_event_t* e);
    static void OnPercentageChangeCompleted(lv_event_t* e);
    static void OnPrimaryAction(lv_event_t* e);

public:
    static DimmerScreen* instance;

    DimmerScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetPercentageValue(uint8_t value) override;
    virtual uint8_t GetPercentageValue() const override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void RegisterPercentageChanged(std::function<void(uint8_t)> callback) override;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) override;
    virtual void RegisterPrimaryAction(std::function<void()> callback) override;
    virtual void Show() override;
};