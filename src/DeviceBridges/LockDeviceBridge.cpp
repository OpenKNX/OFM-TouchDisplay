#include "LockDeviceBridge.h"

LockDeviceBridge::LockDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void LockDeviceBridge::setup(uint8_t _channelIndex)
{   
    // <Enumeration Value="0" Id="%ENID%" Text="Nach links"                       />
    // <Enumeration Value="1" Id="%ENID%" Text="Nach rechts"                      />
    _lockOpenDirection = ParamBRI_CHLockDirection;


    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterMainAction([this]() { imageClicked(); });
    _screen.SetBlockedVisible(false);
    _screen.ClearMovementImage();
    mainFunctionValueChanged();
    _screen.Show();
}

LockDeviceBridge::~LockDeviceBridge()
{
    _screen.RegisterMainAction(nullptr);
}

void LockDeviceBridge::setLocked(bool lock)
{
    // Ignored, because handled in mainFunctionValueChanged via main function image and value
}

void LockDeviceBridge::setBlocked(bool blocked)
{
    logDebugP("Set blocked: %d", blocked);
    _screen.SetBlockedVisible(blocked);
}

void LockDeviceBridge::setUnlocking(bool unlocking)
{
    logDebugP("Set unlocking: %d", unlocking);
    if (unlocking)
    {
        // <Enumeration Value="0" Id="%ENID%" Text="links"                       />
        // <Enumeration Value="1" Id="%ENID%" Text="rechts"                      />
        if (_lockOpenDirection)
            _screen.SetMovementImage("rotate_l.png");
        else
            _screen.SetMovementImage("rotate_r.png");
       
    }
    else
    {
        _screen.ClearMovementImage();
    }
}

void LockDeviceBridge::setLocking(bool locking)
{
    logDebugP("Set locking: %d", locking);
    if (locking)
    {
        // <Enumeration Value="0" Id="%ENID%" Text="links"                       />
        // <Enumeration Value="1" Id="%ENID%" Text="rechts"                      />
        if (_lockOpenDirection)
            _screen.SetMovementImage("rotate_r.png");
        else
            _screen.SetMovementImage("rotate_l.png");
    }
    else
    {
        _screen.ClearMovementImage();
    }
}


void LockDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    _screen.SetMainIndicatorImage(image.imageFile.c_str(), image.allowRecolor, power);
    _screen.SetValueText(device.currentValueAsString().c_str());
}

void LockDeviceBridge::imageClicked()
{    
    _channel->commandMainFunctionClick();
}