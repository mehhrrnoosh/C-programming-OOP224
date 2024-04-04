

#include <iostream>
#include <cstring>
#include "Rectangle.h"

using namespace std;

namespace sdds
{
    Rectangle::Rectangle() : LblShape()
    {
        m_width = 0;
        m_height = 0;
    }

Rectangle::Rectangle(const char* labels, int width, int height) : LblShape(labels)
{
    if (height > 3 && width > static_cast<int>(strlen(LblShape::label())) + 2)
    {
        m_width = width;
        m_height = height;
    }
}


    void Rectangle::getSpecs(istream& is)
    {
        int width;
        int height;
        char ch;
        bool valid = false;

        do {
            LblShape::getSpecs(is);

            is >> width >> ch >> height;

            if (!is)
            {
                is.clear();
                is.ignore(32767, '\n');
            }
            else
            {
                is.ignore();
                m_width = width;
                m_height = height;
                valid = true;
            }
        } while (!valid);
    }

    void Rectangle::draw(std::ostream& os) const
    {
        if (m_width > 0 && m_height >> 0)
        {
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+' << endl;

            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << left << LblShape::label() << '|' << endl;

            for ( int i = 0; i < (m_height - 3); i++)
            {
                os << '|';
                os.width(m_width - 2);
                os.fill(' ');
                os << ' ' << '|' << endl;
            }

            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+';
        }
    }
}
