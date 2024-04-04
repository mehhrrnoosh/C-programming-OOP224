

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include <iomanip>

#define MAX_MENU_ITEMS 20
#define MIN_MENU_ITEMS 0

namespace sdds {

class Menu;
class MenuItem {
    char* m_item;

    void setEmpty();
    MenuItem(const char* value);
    
    MenuItem(const MenuItem& src) = delete;
    void operator=(const MenuItem& src) = delete;

    ~MenuItem();
    MenuItem();

    operator bool() const;
    operator const char* () const;

    std::ostream& displayItem(std::ostream& os = std::cout);


    friend class Menu;
};

class Menu {
    MenuItem m_title {};
    MenuItem* m_itemPtr[MAX_MENU_ITEMS] {};
    unsigned int m_countPtr = 0;

public:
    Menu();
    Menu(const char* title);

    ~Menu();

    Menu(const Menu& src) = delete;
    void operator=(const Menu& src) = delete;

    std::ostream& display(std::ostream& os = std::cout);
    std::ostream& displayMenuTitle(std::ostream& os = std::cout);
    

    int run();
    int operator~();

    Menu& operator<<(const char* menuItemContent);

    operator int();
    operator unsigned int();
    operator bool();

    const char* operator[](unsigned int index) const;
};
std::ostream& operator<<(std::ostream& cout, Menu& menu);

int getInput(int min, int max, const char* prompt);

} // namespace sdds

#endif /* Menu_hpp */
