#pragma once

#include <cstdint>
#include <functional>

class IJalousieScreen
{
public:
    virtual ~IJalousieScreen() = default;
    virtual void SetAuxPercentageValue(uint8_t value) = 0;
    virtual uint8_t GetAuxPercentageValue() const = 0;
    virtual void RegisterAuxPercentageChangeCompleted(std::function<void(uint8_t)> callback) = 0;
};
