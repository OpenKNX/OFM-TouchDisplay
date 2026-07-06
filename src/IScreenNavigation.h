#pragma once

class TouchDisplayModule;

class IScreenNavigation
{
public:
    static IScreenNavigation *instance;
    virtual ~IScreenNavigation() = default;
    virtual void init(TouchDisplayModule *module) = 0;
};
