#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

#include "LblShape.h"

using namespace std;

namespace sdds
{
    const char* LblShape::label() const
    {
        return m_label;
    }

    LblShape::LblShape()
    {
        m_label = nullptr;
    }

    LblShape::LblShape(const char* label)
    {
        if (label != nullptr)
        {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
        else
        {
            m_label = nullptr;
        }
    }

    LblShape::~LblShape()
    {
        if (m_label != nullptr)
        {
            delete[] m_label;
            m_label = nullptr;
        }
    }

    void LblShape::getSpecs(istream& is)
    {
        string currentLabel;
        getline(is, currentLabel, ',');

        delete[] m_label;
        m_label = new char[strlen(currentLabel.c_str()) + 1];
        strcpy(m_label, currentLabel.c_str());
    }
}
