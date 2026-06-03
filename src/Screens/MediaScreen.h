#pragma once

#include <functional>

#include "ScreenWithLabel.h"

class IMediaScreen
{
public:
    virtual ~IMediaScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetTitleText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void SetPercentageValue(uint8_t value) = 0;
    virtual uint8_t GetPercentageValue() const = 0;
    virtual void RegisterPercentageChanged(std::function<void(uint8_t)> callback) = 0;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) = 0;
    virtual void RegisterMainAction(std::function<void()> callback) = 0;
    virtual void RegisterPreviousAction(std::function<void()> callback) = 0;
    virtual void RegisterNextAction(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};

class MediaScreen: public ScreenWithLabel
                 , public IMediaScreen
{
private:
    lv_obj_t* _percentageInput;
    lv_obj_t* _title;
    lv_obj_t* _image;
    lv_obj_t* _buttonPrevious;
    lv_obj_t* _buttonNext;
    std::function<void(uint8_t)> _onPercentageChanged;
    std::function<void(uint8_t)> _onPercentageChangeCompleted;
    std::function<void()> _onMainAction;
    std::function<void()> _onPreviousAction;
    std::function<void()> _onNextAction;

    static void OnPercentageChanged(lv_event_t* e);
    static void OnPercentageChangeCompleted(lv_event_t* e);
    static void OnMainAction(lv_event_t* e);
    static void OnPreviousAction(lv_event_t* e);
    static void OnNextAction(lv_event_t* e);

public:
    static MediaScreen* instance;

    MediaScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetTitleText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void SetPercentageValue(uint8_t value) override;
    virtual uint8_t GetPercentageValue() const override;
    virtual void RegisterPercentageChanged(std::function<void(uint8_t)> callback) override;
    virtual void RegisterPercentageChangeCompleted(std::function<void(uint8_t)> callback) override;
    virtual void RegisterMainAction(std::function<void()> callback) override;
    virtual void RegisterPreviousAction(std::function<void()> callback) override;
    virtual void RegisterNextAction(std::function<void()> callback) override;
    virtual void Show() override;
};