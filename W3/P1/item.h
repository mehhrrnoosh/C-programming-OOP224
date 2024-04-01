//
//  Item.hpp
//  Workshop 3 - p1
//
//  Created by Apple on 2023-05-27.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>

namespace sdds{
class Item{
private:
    char m_itemName[21];  // holds the item name up to 20 chars
    double m_price;
    bool m_taxed;
    void setName(const char* name);
public:
void setEmpty();
void set(const char* name, double price, bool taxed);
    double price()const;
    double tax()const;
    bool isValid()const;
    void display()const;
};

}

#endif /* Item_hpp */
