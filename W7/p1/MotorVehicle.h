#include "MotorVehicle.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
    MotorVehicle::MotorVehicle(const char* licensePlateNumber, int year) {
        strcpy(m_licensePlateNumber, licensePlateNumber);
        strcpy(m_address, "Factory");
        m_madeYear = year;
    }
//
//    void MotorVehicle::moveTo(const char* address) {
//        if (address != nullptr) {
//            if (strcmp(m_address, address) != 0) {
//                cout << "|";
//                cout.width(8);
//                cout << right << m_licensePlateNumber;
//                cout << "| |";
//                cout << right << m_address;
//                cout << " ---> ";
//                cout.width(20);
//                cout << left << address;
//                cout << "|";
//                cout << endl;
//            }
//        }
//    }
void MotorVehicle::moveTo(const char* address) {
    if (address != nullptr) {
        if (strcmp(m_address, address) != 0) {
            cout << "|";
            cout.width(8);
            cout << right << m_licensePlateNumber;
            cout << "| |";
            cout.width(20);
            cout << right << m_address;
            cout << " ---> ";
            cout.width(20);
            cout << left << address;
            cout << "|" << endl;
            strcpy(m_address, address);
        }
    }
}



    ostream& MotorVehicle::write(ostream& os) const {
        os << "| ";
        os << m_madeYear;
        os << " | ";
        os << m_licensePlateNumber;
        os << " | ";
        os << m_address;
        return os;
    }

    istream& MotorVehicle::read(istream& in) {
        cout << "Built year: ";
        in >> m_madeYear;
        cout << "License plate: ";
        in >> m_licensePlateNumber;
        cout << "Current location: ";
        in >> m_address;
        return in;
    }

    ostream& operator<<(ostream& os, const MotorVehicle& theVehicle) {
        return theVehicle.write(os);
    }

    istream& operator>>(istream& in, MotorVehicle& theVehicle) {
        return theVehicle.read(in);
    }
}  // namespace sdds
