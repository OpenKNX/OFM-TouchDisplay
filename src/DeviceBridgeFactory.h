#pragma once

#include "SmartHomeBridgeModule.h"

class DetailDevicePage;

class DeviceBridgeFactory : BridgeBase
{
    friend class DetailDevicePage;
    DetailDevicePage* _currentDevicePage;

    public:
        virtual const std::string name() override;
  
        virtual SwitchBridge* createSwitch(KnxChannelSwitch& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual DimmerBridge* createDimmer(KnxChannelDimmer& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual RGBBridge* createRGB(KnxChannelRGB& channel, uint8_t channelIndex, uint8_t deviceType) override;
        virtual RolladenBridge* createJalousien(KnxChannelJalousie& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual RolladenBridge* createRolladen(KnxChannelRolladen& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual SceneBridge* createScene(KnxChannelScene& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual ThermostatBridge* createThermostat(KnxChannelThermostat& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual DeviceBridge* createDisplay(KnxChannelDisplay& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual AlarmBridge*createSensor(KnxChannelAlarm& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual FanBridge* createFan(KnxChannelFan& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
        virtual DoorWindowBridge* createDoorWindow(KnxChannelDoorWindow& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;     
        virtual MediaBridge* createMedia(KnxChannelMedia& channel, uint8_t _channelIndex /* this parameter is used in macros, do not rename */, uint8_t deviceType) override;
};