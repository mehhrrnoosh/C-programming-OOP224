
#include <iomanip>
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "Menu.h"
namespace sdds
{

    MenuItem::MenuItem()
    {
        m_item = nullptr;
    }

    MenuItem::MenuItem(const char* content)
    {
        if (content != nullptr)
        {
            m_item = new char[strlen(content) + 1];
            strcpy(m_item, content);
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

    MenuItem::operator const char* () const
    {
        return m_item;
    }

    ostream& MenuItem::displayItem(ostream& os)
    {
        if (m_item != nullptr)
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

        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete m_itemPtr[i];
        }
    }

    std::ostream& Menu::displayMenuTitle(std::ostream& os)
    {
        if (m_title != nullptr)
        {
            m_title.displayItem();
        }

        return os;
    }

    std::ostream& Menu::display(std::ostream& os)
    {
        if (m_title != nullptr)
        {
            m_title.displayItem();
            cout << endl;
            // os << ":" << std::endl;
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

int getInput(int min, int max, const char* prompt){
        int userInput;
        bool success = false;
        while (success == false)
        {
            cin >> userInput;
            if (!cin || userInput < min || userInput > max)
            {
                std::cout << prompt;
                cin.clear();
                cin.ignore(1000, '\n');
                success = false;
            }
            else
            {
                success = true;
            }

        }
        return userInput;
    }



    int Menu::run()
    {
        int input;

        display();

        input = getInput(0, m_countPtr, "");

        return input;
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

    std::ostream& operator<<(std::ostream& cout, Menu& menu)
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
}
