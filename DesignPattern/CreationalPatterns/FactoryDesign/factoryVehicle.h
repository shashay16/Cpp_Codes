#pragma once
#include "vehicle.h"
#include <string>

class FactoryVehicle {
public:
    static Vehicle* createVehicle(std::string vehicleType);
};