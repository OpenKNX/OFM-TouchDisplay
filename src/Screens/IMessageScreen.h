#pragma once

class IMessageScreen
{
public:
    static IMessageScreen* instance;
    virtual ~IMessageScreen() = default;
    virtual void SetLabelText(const char* text) = 0;
    virtual void SetMessageText(const char* text) = 0;
    virtual void Show() = 0;
};