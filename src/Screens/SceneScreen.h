#pragma once

#include <functional>
#include "ScreenWithLabel.h"

class ISceneScreen
{
public:
    virtual ~ISceneScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) = 0;
    virtual void RegisterPrimaryActionPressed(std::function<void()> callback) = 0;
    virtual void RegisterPrimaryActionReleased(std::function<void()> callback) = 0;
    virtual void Show() = 0;
};

class SceneScreen: public ScreenWithLabel
                 , public ISceneScreen
{
private:
    lv_obj_t* _value;
    lv_obj_t* _image;
    std::function<void()> _onPrimaryActionPressed;
    std::function<void()> _onPrimaryActionReleased;

    static void OnPrimaryActionPressed(lv_event_t* e);
    static void OnPrimaryActionReleased(lv_event_t* e);

public:
    static SceneScreen* instance;

    SceneScreen();

    virtual void SetLabelText(const char* text) override;
    virtual void SetValueText(const char* text) override;
    virtual void SetMainIndicatorImage(const char* imageFile, bool allowRecolor, bool active) override;
    virtual void RegisterPrimaryActionPressed(std::function<void()> callback) override;
    virtual void RegisterPrimaryActionReleased(std::function<void()> callback) override;
    virtual void Show() override;
};