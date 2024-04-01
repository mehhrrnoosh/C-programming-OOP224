//
//  Canister.cpp
//  w4-p1
//
//  Created by Apple on 2023-06-02.
//

#include "Canister.h"
#include <iostream>
#include <cstring>


using namespace std;

namespace  sdds {

const double PI= 3.14159265;

const double D_MIN=10.0;
const double D_MAX=30.0;

const double D_DEFAULT=10.0;
const double H_DEFAULT=13.0;

const double H_MIN =10.0;
const double H_MAX=40.0;

const double V_DEFAULT=0.0;

const double V_VOL=0.00001;


void Canister::setToDefault()
{
    m_hieght = H_DEFAULT;
    m_diameter =D_DEFAULT;
    m_contentVolume = V_DEFAULT;
    m_contentName = nullptr;
    m_usable=true;
    
}

bool Canister:: isEmpty()const
{
    if(m_contentVolume <V_VOL)
    {
        return true;
    }
    return false;
}

bool Canister::hasSameContent(const Canister& C)const
{
    if(m_contentName && C.m_contentName)
    {
        if(strcmp(m_contentName, C.m_contentName) == 0)
        {
            return true;
        }
    }
    return false;
}

void Canister::setName(const char* Cstr)
{
    if(m_usable && Cstr!=nullptr)
    {
        delete [] m_contentName;
        m_contentName = new char [ strlen(Cstr)+1];
        strcpy(m_contentName,Cstr);
    }
}
//Cosntructors

Canister::Canister()
{
    setToDefault();
}

Canister::Canister(const char* contentName)
{
    
    setToDefault();
    setName(contentName);
}

Canister::Canister(double hieght, double diameter, const char* contentName)
{
    setToDefault();
    
    if (hieght >= H_MIN && hieght <= H_MAX && diameter >= D_MIN && diameter <= D_MAX)
    {
        m_hieght = hieght;
        m_diameter = diameter;
        m_contentVolume = V_DEFAULT;
        
        setName(contentName);
    }
    else {
        m_usable = false;
    }
}

Canister::Canister(int height, int diameter)
{
    if (height >= H_DEFAULT && diameter >= D_MIN && diameter <= D_MAX) {
        m_hieght = static_cast<double>(height);
        m_diameter = static_cast<double>(diameter);
        m_contentVolume = V_DEFAULT;
        m_contentName = nullptr;
        m_usable = true;
    } else {
        setToDefault();
        m_usable = false;
    }
}




Canister :: ~Canister()
{
    delete [] m_contentName;
    m_contentName=nullptr;
}
void Canister::clear()
{
    
    delete [] m_contentName;
    m_contentName=nullptr;
    m_contentVolume=0;
    m_usable=true;
    
}
double Canister::capacity() const
{
    
    double b_height = m_hieght - 0.267;
    double b_diameter = m_diameter / 2;
    double Capacity = PI * b_height * b_diameter * b_diameter;
    
    return Capacity;
    // return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
}


double Canister::volume()const
{
    return m_contentVolume;
    
}


Canister& Canister::setContent(const char* contentName) {
    if (contentName == nullptr) {
        m_usable = false;
    }
    else if (isEmpty())
    {
        /*delete[] m_contentName;
        m_contentName = new char[std::strlen(contentName) + 1];
        std::strcpy(m_contentName, contentName);*/
        setName(contentName);
    }
    else if (std::strcmp(m_contentName, contentName) != 0) {
        m_usable = false;
    }
    return *this;
}



Canister& Canister::pour(double quantity)
{
    /*if (m_usable && quantity > 0.0)
    {
        if( quantity + volume() <= capacity())
        {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
            
        }
        
    }*/

    if (m_usable && quantity > 0 && (quantity + volume()) <= capacity())
    {
        m_contentVolume += quantity;
    }
    else
    {
        m_usable = false;
    }
    
    return *this;
}


Canister& Canister::pour(Canister& C)
{
    setContent(C.m_contentName);
    
    if (C.volume() > (capacity() - volume()))
    {
        C.m_contentVolume -= (capacity() - volume());
        m_contentVolume = capacity();
    }
    else
    {
        pour(C.m_contentVolume);
        C.m_contentVolume = 0.0;
    }
    
    return *this;
}
//std::ostream& Canister::display() const {
//    std::cout.precision(1);
//    std::cout << std::fixed;
//
//    std::cout << std::right;
//
//    // Print capacity
//    std::cout.width(7);
//    std::cout << capacity();
//
//    // Print dimensions
//    std::cout << "cc (" << m_hieght << "x" << m_diameter << ") Canister";
//
//    if (!m_usable) {
//        std::cout << " of Unusable content, discard!";
//    } else if (m_contentName != nullptr) {
//        std::cout << " of ";
//        std::cout.width(7);
//        std::cout << volume() << "cc   " << m_contentName;
//    }
//
////    std::cout;
//
//    return std::cout;
//}
std::ostream& Canister::display() const {
    std::cout.precision(1);
    std::cout << std::fixed;
    
    std::cout << std::right;
    
    // Print capacity
    std::cout.width(7);
    std::cout << capacity();
    
    // Print dimensions
    std::cout << "cc (" << m_hieght << "x" << m_diameter << ") Canister";
    
    if (!m_usable) {
        std::cout << " of Unusable content, discard!";
    } else if (m_contentName != nullptr) {
        std::cout << " of ";
        std::cout.width(7);
        std::cout << volume() << "cc   " << m_contentName;
    }
    
//    std::cout << std::endl;
//
    return std::cout;
}


}
