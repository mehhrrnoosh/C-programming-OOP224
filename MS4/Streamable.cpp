// Streamable.cpp
// Streamable
//
// Created by Apple on 2023-07-19.

#include "Streamable.h"

namespace sdds {
    // Implementation of the virtual destructor
    Streamable::~Streamable() {}

    // Implementation of the insertion operator
    std::ostream& operator<<(std::ostream& os, const Streamable& obj) {
        if (obj) {
            obj.write(os);
        }
        return os;
    }

    // Implementation of the extraction operator
    std::istream& operator>>(std::istream& is, Streamable& obj) {
        return obj.read(is);
    }
}
