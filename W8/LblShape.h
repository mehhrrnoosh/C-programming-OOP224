#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include <iostream>
#include "Shape.h"

namespace sdds
{
    class LblShape : public Shape
    {
        char* m_label{ nullptr };

    protected:
        const char* label() const;

    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape& other) = delete;
        LblShape& operator=(const LblShape& other) = delete;
        void getSpecs(std::istream& is);
    };
}

#endif
