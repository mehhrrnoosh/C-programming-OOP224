//
//  Food.h
//  w3-p2
//
//  Created by Apple on 2023-05-30.
//

#ifndef Food_h
#define Food_h

#include <stdio.h>

namespace sdds{
class Food{
       char m_foodName[31];
        int m_calorieNumber;
        int m_timeOfConsumption;
        void setName(const char* name);


    public:
        void setEmpty();
        void set(const char* name, int calorieNumber, int timeOfConsumption);
        void display() const;
        bool isValid() const;
        int Calorie () const;
        
    };
}




#endif /* Food_h */
