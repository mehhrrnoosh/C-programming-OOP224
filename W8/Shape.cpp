
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds
{
//    Shape::~Shape() {}

    ostream& operator<<(ostream& os, const Shape& otherShape)
    {
        otherShape.draw(os);

        return os;
    }

    istream& operator>>(istream& is, Shape& otherShape)
    {
        otherShape.getSpecs(is);

        return is;
    }
}
