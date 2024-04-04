// Streamable.hpp
// Streamable
//
// Created by Apple on 2023-07-19.

#ifndef Streamable_hpp
#define Streamable_hpp

#include <iostream> // Use <iostream> instead of <stdio.h> for C++ streams

namespace sdds {
    // Forward declaration of the Streamable class
    class Streamable;

    // Overloaded insertion operator
    std::ostream& operator<<(std::ostream& os, const Streamable& obj);

    // Overloaded extraction operator
    std::istream& operator>>(std::istream& is, Streamable& obj);

    // Interface for Streamable classes
    class Streamable {
    public:
        // Virtual destructor
        virtual ~Streamable();

        // Virtual function to write object data to an ostream
        virtual std::ostream& write(std::ostream& os) const = 0;

        // Virtual function to read object data from an istream
        virtual std::istream& read(std::istream& is) = 0;

        // Virtual function to determine if the ios object is console IO
        virtual bool conIO(std::ios& stream) const = 0;

        // Boolean conversion operator to check object validity
        virtual operator bool() const = 0;
    };

} // namespace sdds

#endif /* Streamable_hpp */
