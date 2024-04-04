#include "Truck.h"
#include "MotorVehicle.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
    Truck::Truck(const char* plateNumber, int year, double capacity, const char* currentAddress)
        : MotorVehicle(plateNumber, year), m_capacity(capacity), m_cargo(0) {
        moveTo(currentAddress);
    }

bool Truck::addCargo(double cargo) {
    bool valid = false;

    if (cargo != 0 && m_capacity != m_cargo) {
        if (m_cargo + cargo <= m_capacity) {
            m_cargo += cargo;
            valid = true;
        } else {
            m_cargo = m_capacity;
            valid = true;
        }
    }

    return valid;
}


    bool Truck::unloadCargo() {
        bool valid = false;
        
        if (m_cargo != 0) {
            m_cargo = 0;
            valid = true;
        }
        
        return valid;
    }

    ostream& Truck::write(ostream& os)  {
        MotorVehicle::write(os);
        os << " | " << fixed << setprecision(0) << m_cargo << "/" << m_capacity;
        return os;
    }

    istream& Truck::read(istream& in) {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_capacity;
        cout << "Cargo: ";
        in >> m_cargo;
        return in;
    }

    ostream& operator<<(ostream& os,  Truck& T) {
        T.write(os);
        return os;
    }

    istream& operator>>(istream& is, Truck& T) {
        T.read(is);
        return is;
    }
}  // namespace sdds
