//
//  CalorieList.cpp
//  w3-p2
//
//  Created by Apple on 2023-06-01.
//

#include "CalorieList.h"
#include <iostream>
#include <cstring>
#include <iomanip>


using namespace std;

namespace  sdds {

void CalorieList::setEmpty()
{
    m_foodlist = nullptr;
//    m_numberFood = 0;
//    m_addedFood = 0;
}


bool CalorieList::isValid() const
{
//    return m_foodlist != nullptr && m_numberFood > 0 && m_addedFood <= m_numberFood;
    if(m_foodlist ==nullptr)
    {
        return false;
    }
    for(int i=0; i<m_numberFood ;i++)
    {
        if(!m_foodlist[i].isValid())
        {
            return false;
        }
    }
    return true;
}


int CalorieList::totalCalories() const
   {
       int total = 0;
       for (int i = 0; i < m_numberFood; i++)
       {
           total += m_foodlist[i].Calorie();
       }
       return total;
   }


void CalorieList::Title() const {
    
    cout << "+----------------------------------------------------+" << endl;

    if (isValid())
    {
        cout << "|  Daily Calorie Consumption                         |" << endl;
    }
    else
    {
        cout << "| Invalid Calorie Consumption list                   |" << endl;
    }

    cout << "+--------------------------------+------+------------+" << endl;
    cout << "| Food name                      | Cals | When       |" << endl;
    cout << "+--------------------------------+------+------------+" << endl;
}

void CalorieList::footer() const {

    cout << "+--------------------------------+------+------------+" << endl;

    if (isValid())
    {
        cout.setf(ios::right);
        cout << "|    Total Calories for today:  ";
        cout.width(7);
        cout << totalCalories() << " | ";
        cout.width(12);
        cout << " |" << endl;
        cout.unsetf(ios::right);
    }
    else
    {
        cout << "|    Invalid Calorie Consumption list                |" << endl;
    }

    cout << "+----------------------------------------------------+" << endl;
}





void CalorieList::init(int size)
{
    if (size <= 0)
    {
        setEmpty();
    }
    else
    {
        m_numberFood = size;
        m_addedFood = 0;
        m_foodlist = new Food[m_numberFood];
        
        for (int i = 0; i < m_numberFood; i++)
        {
            m_foodlist[i].setEmpty();
        }
    }
}


bool CalorieList::add(const char* foodName, int calories, int when)
{
    if (m_addedFood < m_numberFood)
    {
        m_foodlist[m_addedFood].set(foodName, calories, when);
        m_addedFood++;
        return true;
    }
    else {
        return false;
    }
}

void CalorieList::display()const
{
    Title();
    for (int i=0;  i< m_numberFood; i++)
    {
        m_foodlist[i].display();
    }
    footer();
}

void CalorieList::deallocate()
{
    delete [] m_foodlist;
    m_foodlist=nullptr;
}

}
