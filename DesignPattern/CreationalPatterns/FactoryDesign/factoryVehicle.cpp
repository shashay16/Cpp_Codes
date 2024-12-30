#include "factoryVehicle.h"
#include "bike.h"
#include "car.h"
#include "truck.h"
#include "supercar.h"
#include <string>


Vehicle* FactoryVehicle::createVehicle(std::string vehicleType) {
    Vehicle* vehicle;
    if(vehicleType == "bike") {
        vehicle = new Bike();
    }
    else if(vehicleType == "car") {
        vehicle = new Car();
    }
    else if(vehicleType == "truck") {
        vehicle = new Truck();
    }
    else if(vehicleType == "supercar") {
        vehicle = new SuperCar();
    }
    return vehicle;
}