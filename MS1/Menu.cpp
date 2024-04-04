//------------------------------------------------------------
// Student Name: Mehrnoosh Sarang
// Student ID  : 128498227
// Email       : msarang@myseneca.ca
// -----------------------------------------------------------
// Final Project Milestone 1
// Menu Module
// File    Menu.cpp
// Version 1.0
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
// -----------------------------------------------------------
// I Have Done All The Coding By Myself And Only Copied The
// Code That My Professor Provided To Complete My
// Workshops And Assignments.

#include "Menu.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {

    MenuItem::MenuItem()
    {
        m_item = nullptr;
    }

    MenuItem::MenuItem(const char* _value)
    {
        if (_value != nullptr)
        {

            m_item = new char[strlen(_value) + 1];
            strcpy(m_item, _value);
        }
        else
        {
            m_item = nullptr;
        }
    }

    MenuItem::~MenuItem()
    {
        if (m_item != nullptr)
        {
            delete[] m_item;
            m_item = nullptr;
        }
    }

MenuItem::operator bool() const
{
    if (m_item != nullptr)
    {
        return true;
    }
    return false;
}

    MenuItem::operator const char*() const
    {
        return m_item;
    }

ostream& MenuItem::displayItem(ostream& os)
    {
        if (m_item)
        {
            os << m_item;
        }
        return os;
    }

    Menu::Menu()
    {
        m_countPtr = 0;
    }

    Menu::Menu(const char* title) : m_title(title) {};

    Menu::~Menu()
    {
        unsigned int i;
        for ( i= 0; i < MAX_MENU_ITEMS; i++)
        {
            delete m_itemPtr[i];
        }
    }

std::ostream& Menu::displayMenuTitle(std::ostream& os)
    {
        if (m_title)
        {
            m_title.displayItem();
        }
        return os;
    }

std::ostream& Menu::display(std::ostream& os)
    {
        if (m_title )
        {
            m_title.displayItem();
            os << ":" << std::endl;
        }
    unsigned int i;

        for (i = 0; i < m_countPtr; i++)
        {
            os.width(2);
            os.setf(ios::right);
            os.fill(' ');
            os << i + 1 << "- ";
            os.unsetf(ios::right);
            m_itemPtr[i]->displayItem(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";
        return os;
    }

    int getInput(int minRange, int maxRange)
    {
        int userInput;
        bool Valid = false;
        while (!Valid)
        {
            cin >> userInput;
            if (!cin || userInput < minRange || userInput > maxRange)
            {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                while (cin.get() != '\n')
                    continue;
            }
            else
            {
                Valid = true;
            }
        }
        return userInput;
    }

    int Menu::run()
    {
        int _userInput;
        display();
        _userInput = getInput(0, m_countPtr);
        return _userInput;
    }

    int Menu::operator~()
    {
        return run();
    }

    Menu& Menu::operator<<(const char* menuitemConent)
    {
        if (m_countPtr < MAX_MENU_ITEMS)
        {
            m_itemPtr[m_countPtr] = new MenuItem(menuitemConent);
            m_countPtr++;
        }
        return *this;
    }

    Menu::operator int()
    {
        return m_countPtr;
    }

    Menu::operator unsigned int()
    {
        return m_countPtr;
    }

    Menu::operator bool()
    {
        if (m_countPtr >= 1)
        {
            return true;
        }
        return false;
    }

    ostream& operator<<(ostream& cout, Menu& menu)
    {
        return menu.displayMenuTitle(cout);
    }

    const char* Menu::operator[](unsigned int index) const
    {
        if (index > m_countPtr)
        {
            return m_itemPtr[index %= m_countPtr]->m_item;
        }
        else
        {
            return m_itemPtr[index]->m_item;
        }
    }

} // namespace sdds
