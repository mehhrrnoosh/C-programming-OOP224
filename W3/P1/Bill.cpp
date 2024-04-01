//
//  Bill.cpp
//  Workshop 3 - p1
//
//  Created by Apple on 2023-05-27.
//

#include "Bill.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace  sdds {


void Bill::setEmpty()
{
    m_items =nullptr;
    m_title[0]='\0';
}


bool Bill::isValid()const
{
    if(m_title [0]!='\0' && m_items !=nullptr)
    {
        for(int i=0; i<m_noOfItems; i++)
        {
            if (!m_items[i].isValid())
                return false;
        }
        return true;
    }
    return false;
}


double Bill::totalTax()const
{
    double sumOfTax=0.0;
    
    if(m_items != nullptr)
    {
        for(int i=0; i<m_noOfItems; i++)
        {
            sumOfTax+= m_items[i].tax();
        }
    }
    
    return sumOfTax;
}

double Bill::totalPrice()const
{
    double sumOfPrice=0.0;
    
    if(m_items != nullptr)
    {
        for(int i=0; i<m_noOfItems; i++)
        {
            sumOfPrice+= m_items[i].price();
        }
    }
    return sumOfPrice;
}

void Bill::Title() const {
    cout << "+--------------------------------------+" << endl;

    if (isValid()) {
        cout << "| ";
        cout.width(36);
        cout << left << setfill(' ') << m_title << " |" << endl;
    } else {
        cout << "| Invalid Bill                         |" << endl;
    }

    cout << "+----------------------+---------+-----+" << endl;
    cout << "| Item Name            | Price   + Tax |" << endl;
    cout << "+----------------------+---------+-----+" << endl;
}




void Bill::footer()const
{
    
    cout << "+----------------------+---------+-----+" << endl;
    
    if (isValid()) {
        cout << "|                Total Tax: ";
        cout.width(10);
        cout << right << fixed << setprecision(2) << totalTax() << " |" << endl;
        
        cout << "|              Total Price: ";
        cout.width(10);
        cout << right <<fixed << setprecision(2) << totalPrice() << " |" << endl;
        
        cout << "|          Total After Tax: ";
        cout.width(10);
        cout << right <<fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;
    } else {
        cout << "| Invalid Bill                         |" << endl;
    }
    
    cout << "+--------------------------------------+" << endl;
}


void Bill::init(const char* title, int noOfItems)
{
    m_items = nullptr;
    m_title[0] = '\0';
    
    if (title == nullptr || noOfItems <= 0)
    {
        setEmpty();
    }
    else
    {
        strncpy(m_title, title, 35);
               m_title[35] = '\0'; // Ensure null-termination
               m_noOfItems = noOfItems;
               m_itemsAdded = 0;
               m_items = new Item[noOfItems];
        for (int i = 0; i < m_noOfItems; i++)
                {
                    m_items[i].setEmpty();
                }
    }
}

bool Bill::add(const char* item_name, double price, bool taxed){
    
    if (m_itemsAdded < m_noOfItems)
    {
        m_items[m_itemsAdded].set(item_name, price,  taxed);
        
        m_itemsAdded ++;
        return true;
    }
    else {
        return false;
    }
    
}
void Bill::display() const {
    Title();
    for (int i = 0; i < m_noOfItems; i++) {
        m_items[i].display();
    }
    footer();
}



void Bill::deallocate()
{
    delete[] m_items;
    m_items =nullptr;
}

}
    




