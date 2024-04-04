

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include <iostream>
#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {
        unsigned int m_length{ 0 };

    public:
        Line();
        Line(const char* labels, int len);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}

#endif
