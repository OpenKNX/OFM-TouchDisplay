#include "JalousieDeviceBridge.h"

JalousieDeviceBridge::JalousieDeviceBridge(DetailDevicePage& detailDevicePage)
    : RolladenDeviceBridge(*IRolladenScreen::instance, detailDevicePage)
{
}

void JalousieDeviceBridge::setup(uint8_t _channelIndex)
{   
    _jalousieScreen.RegisterAuxPercentageChangeCompleted([this](uint8_t) { auxPercentageChangeCompleted(); });
    RolladenDeviceBridge::setup(_channelIndex);
   
}

JalousieDeviceBridge::~JalousieDeviceBridge()
{
    _jalousieScreen.RegisterAuxPercentageChangeCompleted(nullptr);
}

void JalousieDeviceBridge::auxPercentageChangeCompleted() 
{
    ((KnxChannelJalousie*)_channel)->commandSlatPosition(nullptr, _jalousieScreen.GetAuxPercentageValue());
}

void JalousieDeviceBridge::setSlatPosition(uint8_t position)
{
    _jalousieScreen.SetAuxPercentageValue(position);
}
