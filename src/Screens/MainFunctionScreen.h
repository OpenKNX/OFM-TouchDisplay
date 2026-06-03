#pragma once

#include "ScreenWithLabel.h"
#include <functional>

class IMainFunctionScreen
{
public:
    virtual ~IMainFunctionScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void RegisterScreenPressed(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};

class MainFunctionScreen: public ScreenWithLabel
                         , public IMainFunctionScreen
{
private:
    lv_obj_t* _image;
    lv_obj_t* _value;
    std::function<void()> _onScreenPressed;

    static void OnScreenPressed(lv_event_t* e);

public:
    static MainFunctionScreen* instance;
    MainFunctionScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void RegisterScreenPressed(std::function<void()> callback) override;
    virtual void Show() override;
};