//
//  Food.cpp
//  w3-p2
//
//  Created by Apple on 2023-05-30.
//

#include "Food.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace  sdds {


void Food::setName(const char* name)
{
    strncpy(m_foodName, name, 30);
    m_foodName[30] = '\0';
}

void Food::setEmpty()
{
    m_foodName[0]='\0';
    m_calorieNumber=0;
    m_timeOfConsumption=-1;
    
    
}


void Food::set(const char* name, int calorieNumber, int timeOfConsumption) {
    if (name != nullptr && name[0] != '\0' && calorieNumber >= 0) {
        
        setName(name);
        m_calorieNumber = calorieNumber;
        m_timeOfConsumption = timeOfConsumption;
    } else {
        setEmpty();
    }
}


bool Food::isValid() const
{
    if( m_foodName[0]!='\0' && m_calorieNumber > 0 && m_calorieNumber <=3000 && m_timeOfConsumption >0 && m_timeOfConsumption <= 4){
        return true;
    }else {
        return false;
    }
    
}

//void Food::display() const {
//    if (isValid()) {
//        cout << "| ";
//        cout.width(30);
//        cout.setf(ios::left);
//        cout.fill('.');
//        cout << m_foodName;
//        cout.unsetf(ios::left);
//        cout.fill(' ');
//        cout << " | ";
//        cout.width(4);
//        cout.setf(ios::right);
//        cout << m_calorieNumber;

void Food::display() const
{
    
    if (isValid())
    {
        cout << "| ";
        cout.setf(ios::left);
        cout.width(30);
        cout.fill('.');
        cout << m_foodName << " | ";
        cout.fill(' ');
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(4);
        cout << m_calorieNumber << " | ";
        
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout.width(10);
        
        char mealtime[10];
        if (m_timeOfConsumption == 1) {
            strncpy(mealtime, "Breakfast", sizeof(mealtime) - 1);
        } else if (m_timeOfConsumption == 2) {
            strncpy(mealtime, "Lunch", sizeof(mealtime) - 1);
        } else if (m_timeOfConsumption == 3) {
            strncpy(mealtime, "Dinner", sizeof(mealtime) - 1);
        } else if (m_timeOfConsumption == 4) {
            strncpy(mealtime, "Snack", sizeof(mealtime) - 1);
        } else {
            strncpy(mealtime, "Unknown", sizeof(mealtime) - 1);
        }
        mealtime[sizeof(mealtime) - 1] = '\0';
        
        //        cout << " | ";
        //        cout.width(10);
        //        cout.setf(ios::left);
        //        cout << mealtime;
        //        cout.unsetf(ios::left);
        //        cout << " |" << endl;
        //    } else {
        //        cout << "| ";
        //        cout.width(30);
        //        cout.fill('x');
        //        cout << 'x';
        //        cout << " | ";
        //        cout.width(4);
        //        cout << 'x';
        //        cout << " | ";
        //        cout.width(10);
        //        cout << "xxx";
        //        cout << " |" << endl;
        //    }
        //}
        cout << mealtime << " |" << endl;
        
    }
    else
    {
        cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
    }
    
}

int Food::Calorie () const
{
    return m_calorieNumber;
}
}
       
       
       


