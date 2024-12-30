#include <iostream>
#include "factoryVehicle.h"

using namespace std;

int main()
{
    string vehicleType;
    cout << "Enter Vehicle: ";
    cin >> vehicleType;
    Vehicle* vehicle = FactoryVehicle::createVehicle(vehicleType);
    vehicle->createVehicle();
    return 0;
}


// g++ -c all c++ files 
// ar ru library_name.a all .o files 
// g++ -o client client.cpp library_name.a