#include "RolladenDeviceBridge.h"

RolladenDeviceBridge::RolladenDeviceBridge(DetailDevicePage& detailDevicePage)
    : RolladenDeviceBridge(*IRolladenScreen::instance, detailDevicePage)
{

}

RolladenDeviceBridge::RolladenDeviceBridge(IRolladenScreen& screen, DetailDevicePage& detailDevicePage)
    : _screen(screen), _detailDevicePage(detailDevicePage)
{
}

void RolladenDeviceBridge::setup(uint8_t _channelIndex)
{   
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterPrimaryAction([this]() { buttonUpPressed(); });
    _screen.RegisterSecondaryAction([this]() { buttonDownPressed(); });
    _screen.RegisterMainAction([this]() { buttonMainFunctionPressed(); });
    _screen.RegisterPercentageChangeCompleted([this](uint8_t) { percentageChangeCompleted(); });
    
    mainFunctionValueChanged();
    _screen.Show();
}

RolladenDeviceBridge::~RolladenDeviceBridge()
{
    _screen.RegisterPrimaryAction(nullptr);
    _screen.RegisterSecondaryAction(nullptr);
    _screen.RegisterMainAction(nullptr);
    _screen.RegisterPercentageChangeCompleted(nullptr);
}

void RolladenDeviceBridge::mainFunctionValueChanged() 
{
    auto& device = *_detailDevicePage.getDevice();
    auto image = device.mainFunctionImage();
    _screen.SetMainIndicatorImage(image.imageFile.c_str(), image.allowRecolor, device.mainFunctionValue());
}

void RolladenDeviceBridge::setPosition(uint8_t position)
{
    _screen.SetPercentageValue(position);
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%d%%", (int) position);
    _screen.SetValueText(buffer);
}

void RolladenDeviceBridge::setMovement(MoveState movement)
{
    switch (movement)
    {
        case MoveState::MoveStateHold:
            _screen.SetDirectionalActionState(false, false);
            break;
        case MoveState::MoveStateDown:
            _screen.SetDirectionalActionState(false, true);
            break;
        case MoveState::MoveStateUp:
            _screen.SetDirectionalActionState(true, false);
            break;
    }
}

void RolladenDeviceBridge::percentageChangeCompleted()
{
    _channel->commandPosition(nullptr, _screen.GetPercentageValue());
}

void RolladenDeviceBridge::buttonUpPressed()
{
    _channel->commandPosition(nullptr, 0);
}
   

void RolladenDeviceBridge::buttonDownPressed()
{
    _channel->commandPosition(nullptr, 100);
}


void RolladenDeviceBridge::buttonMainFunctionPressed()
{    
    _channel->commandMainFunctionClick();
}