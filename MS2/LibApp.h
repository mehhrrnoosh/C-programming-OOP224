#ifndef LibApp_h
#define LibApp_h

#include <iostream>
#include "Menu.h"

namespace sdds {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        
        bool confirm(const char* message);
        void load();
        void save();
        void search();
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
        
    public:
        LibApp();
        void run();

    };
}

#endif /* LibApp_h */
