//
//  Truck.hpp
//  MotorVehicle
//
//  Created by Apple on 2023-07-10.
//

#ifndef Truck_hpp
#define Truck_hpp

#include <stdio.h>
#include "MotorVehicle.h"
#include <iostream>
#include <iomanip>

namespace sdds {
class Truck: public MotorVehicle
{
    double m_capacity;
    double m_cargo;
    
public:
    Truck (const char* plateNumber, int year, double capacity, const char* currentAddress);
    bool addCargo(double cargo);
    
    bool unloadCargo();
    
    std::ostream& write(std::ostream& os);
    std::istream& read(std::istream& in);
};

std::ostream& operator<<(std::ostream& os, Truck& T);
std::istream& operator>>(std::istream& is, Truck& T);
}

#endif /* Truck_hpp */
