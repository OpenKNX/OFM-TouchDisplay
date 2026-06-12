#pragma once

#include <functional>

class ICellObject
{
public:
    virtual ~ICellObject() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetValueText(const char* text) = 0;
    virtual void SetImage(const char* imageFile, bool allowRecolor = false, bool active = false) = 0;
    virtual void ClearImage() = 0;
    virtual void SetImageState(bool active) = 0;
    virtual void RegisterPressed(std::function<void()> callback) = 0;
    virtual void RegisterClicked(std::function<void()> callback) = 0;
};
