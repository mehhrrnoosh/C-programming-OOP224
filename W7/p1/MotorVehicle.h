//
//  MotorVehicle.hpp
//  MotorVehicle
//
//  Created by Apple on 2023-07-09.
//

#ifndef MotorVehicle_hpp
#define MotorVehicle_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>

namespace sdds {


class MotorVehicle {
    
    char m_licensePlateNumber [10];
    char m_address[64];
    int m_madeYear;
    
public:
    MotorVehicle( const char* licensePlateNumber, int year );
    
    void moveTo(const char* address);
    
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& in);
    
};
std::ostream& operator<<(std::ostream& os, const MotorVehicle& theVehicle);
std::istream& operator>>(std::istream& in, MotorVehicle& theVehicle);
}
#endif /* MotorVehicle_hpp */
