//
//  CalorieList.h
//  w3-p2
//
//  Created by Apple on 2023-06-01.
//

#ifndef CalorieList_h
#define CalorieList_h

#include <stdio.h>

#include <cstring>
#include "Food.h"

namespace sdds {
class CalorieList {
    
    Food* m_foodlist;
    int m_numberFood;
    int m_addedFood;
    
    int totalCalories() const;
    
    void Title ()const;
    void footer ()const;
    void setEmpty();
    bool isValid()const;
    
    public :
    void init(int numberFood);
    bool add(const char* foodName,int calories,int addedNumber );
    void display () const;
    void deallocate();
    
    
};
}


#endif /* CalorieList_h */
