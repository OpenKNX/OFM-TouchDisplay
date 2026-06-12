#include "DoorWindowDeviceBridge.h"

DoorWindowDeviceBridge::DoorWindowDeviceBridge(DetailDevicePage& detailDevicePage)
    : _detailDevicePage(detailDevicePage)
{
}

void DoorWindowDeviceBridge::setup(uint8_t _channelIndex)
{   
    _doorWindowOpenDirection = ParamBRI_CHDoorWindowOpenDirection;
    // <Enumeration Value="0" Id="%ENID%" Text="Nach links"                       />
    // <Enumeration Value="1" Id="%ENID%" Text="Nach rechts"                      />
    // <Enumeration Value="2" Id="%ENID%" Text="Mittig auseinander links/rechts"  />
    // <Enumeration Value="3" Id="%ENID%" Text="Nach oben"                        />
    // <Enumeration Value="4" Id="%ENID%" Text="Nach unten"                       />
    // <Enumeration Value="5" Id="%ENID%" Text="Mittig auseinander oben/unten"    />
    switch (_doorWindowOpenDirection)
    {
        case 0:
            _screen.SetSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_LEFT);
            break;
        case 1:
            _screen.SetSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_RIGHT);
            break;
        case 2:
            _screen.SetSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_LEFT_RIGHT);
            break;
        case 3:
            _screen.SetSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_UP);
            break;
        case 4:
            _screen.SetSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_DOWN);
            break;
        case 5:
            _screen.SetSliderDirection(DoorWindowSliderDirection::DOOR_WINDOW_SLIDER_UP_DOWN);
            break;
    }

    if (ParamBRI_CHDoorWindowMotor)
    {
        if (ParamBRI_CHDoorWindowUsePercent)
        {
            _screen.SetPercentageVisible(true);
        }
        else
        {
            _screen.SetPercentageVisible(false);
        }
    }
    else
        _screen.SetPercentageVisible(false);
    
    _screen.SetLabelText(_channel->getNameInUTF8());
    _screen.RegisterMainAction([this]() { imageClicked(); });
    _screen.RegisterPercentageChangeCompleted([this](uint8_t) { percentageChangeCompleted(); });
    _screen.SetObstructionVisible(false);
    _screen.ClearMovementImage();
    mainFunctionValueChanged();
    _screen.Show();
}

DoorWindowDeviceBridge::~DoorWindowDeviceBridge()
{
    _screen.RegisterMainAction(nullptr);
    _screen.RegisterPercentageChangeCompleted(nullptr);
}

void DoorWindowDeviceBridge::setPosition(uint8_t position)
{
    _screen.SetPercentageValue(position);
}

void DoorWindowDeviceBridge::setMovement(DoorWindowMoveState movement)
{
    switch (movement)
    {
        // <Enumeration Value="0" Id="%ENID%" Text="Nach links"                       />
        // <Enumeration Value="1" Id="%ENID%" Text="Nach rechts"                      />
        // <Enumeration Value="2" Id="%ENID%" Text="Mittig auseinander links/rechts"  />
        // <Enumeration Value="3" Id="%ENID%" Text="Nach oben"                        />
        // <Enumeration Value="4" Id="%ENID%" Text="Nach unten"                       />
        // <Enumeration Value="5" Id="%ENID%" Text="Mittig auseinander oben/unten"    />
        case DoorWindowMoveState::DoorWindowMoveStateOpening:
            switch (_doorWindowOpenDirection)
            {
                case 0:
                    _screen.SetMovementImage("opening_l.png");
                    break;
                case 1:
                    _screen.SetMovementImage("opening_r.png");
                    break;
                case 2:
                    _screen.SetMovementImage("opening_lr.png");
                    break;
                case 3:
                    _screen.SetMovementImage("opening_u.png");
                    break;
                case 4:
                    _screen.SetMovementImage("opening_d.png");
                    break;
                case 5:
                    _screen.SetMovementImage("opening_ud.png");
                    break;
            }
            break;
        case DoorWindowMoveState::DoorWindowMoveStateClosing:
            switch (_doorWindowOpenDirection)
            {
                case 0:
                    _screen.SetMovementImage("closing_r.png");
                    break;
                case 1:
                    _screen.SetMovementImage("closing_l.png");
                    break;
                case 2:
                    _screen.SetMovementImage("closing_lr.png");
                    break;
                case 3:
                    _screen.SetMovementImage("closing_d.png");
                    break;
                case 4:
                    _screen.SetMovementImage("closing_u.png");
                    break;
                case 5:
                    _screen.SetMovementImage("closing_ud.png");
                    break;
            }
            break;
        case DoorWindowMoveState::DoorWindowMoveStateHold:
            _screen.ClearMovementImage();
            break;
    }
}

void DoorWindowDeviceBridge::percentageChangeCompleted()
{
    auto& device = *_channel;
    int32_t value = _screen.GetPercentageValue();
    device.commandPosition(nullptr, value);
}

void DoorWindowDeviceBridge::setObstructionDetected(bool obstructionDetected)
{
    _screen.SetObstructionVisible(obstructionDetected);
}

void DoorWindowDeviceBridge::mainFunctionValueChanged()
{
    auto& device = *_channel;
    auto image = device.mainFunctionImage();
    bool power = device.mainFunctionValue();
    _screen.SetMainIndicatorImage(image.imageFile.c_str(), image.allowRecolor, power);
    _screen.SetValueText(device.currentValueAsString().c_str());
}

void DoorWindowDeviceBridge::imageClicked()
{    
    _channel->commandMainFunctionClick();
}