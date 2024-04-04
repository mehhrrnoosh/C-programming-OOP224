#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds
{
    Line::Line() : LblShape()
    {
        m_length = 0;
    }

    Line::Line(const char* labels, int len) : LblShape(labels)
    {
        if (len > 0)
        {
            m_length = len;
        }
    }

    void Line::getSpecs(istream& is)
    {
        int len;
        bool valid = false;

        do
        {
            LblShape::getSpecs(is);

            is >> len;

            if (!is)
            {
                is.clear();
                is.ignore(32767, '\n');
            }
            else
            {
                is.ignore();
                m_length = len;
                valid = true;
            }
        } while (!valid);
    }

    void Line::draw(ostream& os) const
    {
        if (m_length > 0 && LblShape::label())
        {
            os << LblShape::label() << endl;

            os.width(m_length);
            os.fill('=');
            os << '=';
        }
    }
}
