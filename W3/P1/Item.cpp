//
//  Item.cpp
//  Workshop 3 - p1
//
//  Created by Apple on 2023-05-27.
//
#include <iostream>
#include "Item.h"
#include <cstring>
#include <iomanip>

using namespace std;
namespace  sdds

{
void Item::setName(const char* name) {
    strncpy(m_itemName, name, 20);
    //    m_itemName[20] = '\0';
}
void Item::setEmpty()
{
    m_price=0.0;
    m_itemName[0]='\0';
}


void Item::set(const char* name, double price, bool taxed)
{
    if (name != nullptr && name[0] != '\0' && price >= 0)
    {
        strncpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
        m_price = price;
        m_taxed = taxed;
    }
    else
    {
        setEmpty();
    }
}



double Item::price()const
{
    return m_price;
}
double Item::tax()const

{
    const double taxRate= 0.13;
    
    if (m_taxed == false)
    {
        return 0.0;
    }
    else {
        return m_price *taxRate;
        
    }
    
}
bool Item::isValid() const
{
    return m_itemName[0] != '\0';
}



//void Item::display() const {
//    if (isValid()) {
//        cout << "| ";
//        cout.width(20);
//        cout << left << setfill('.') << m_itemName << " | ";
//
//        cout.width(7);
//        cout << right  << fixed << setprecision(2) << m_price << " | ";
//
//        cout << (m_taxed ? "Yes"  : "No") << "  |" << endl;
//
//
//
//    } else {
//        cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
//    }
//}
//}
void Item::display()const {
    if (isValid()) {
        cout << "| ";
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout.width(20);
        cout.fill('.');
        cout << m_itemName;
        cout.fill(' ');
        cout << " | ";
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout << m_price;
        cout << " | " << (m_taxed ? "Yes |" : "No  |") << endl;
        cout.unsetf(ios::right);
    }
    else {
        cout << "| ";
        cout.width(20);
        cout.fill('x');
        cout << 'x';
        cout << " | ";
        cout.width(7);
        cout << 'x';
        cout << " | xxx |" << endl;
    }
}
}
