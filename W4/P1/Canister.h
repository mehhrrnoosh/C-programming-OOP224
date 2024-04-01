//
//  Canister.h
//  w4-p1
//
//  Created by Apple on 2023-06-02.
//

#ifndef Canister_h
#define Canister_h

#include <iostream>
#include <cstring>


namespace  sdds {
class Canister {
    private :
    
        char* m_contentName; // points to a dynamically allocated Cstring.
        double m_diameter; // in centimeters
        double m_hieght;   // in centimeters
        double m_contentVolume;  // in CCs
        bool m_usable;
        
        void setToDefault();
        bool isEmpty()const;
        bool hasSameContent(const Canister& C)const;
        void setName(const char* Cstr);
   
public:
        Canister();
        Canister(const char* contentName);
        Canister(double hieght, double diameter, const char* contentName);
        Canister(int height, int diameter);

        ~Canister();
    
    
        void clear();
        double capacity()const;
        double volume()const;
        Canister& setContent(const char* contentName);
        Canister& pour(double quantity);
        Canister& pour(Canister& C);
        std::ostream& display() const;



};
}
 // a flag to identify if the Canister is usable or unusable
//overload constructor //unknow = dynamic ///macro for H and D not majic number //second cunstroct get a char ( name) // we can not call one cunstruct in another one
// cahnge the label
#endif /* Canister_h */
