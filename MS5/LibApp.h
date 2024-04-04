
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include "Lib.h"
#include "Menu.h"
#include "Menu.h"
#include "Book.h"
#include "Publication.h"


namespace sdds {
    class LibApp {
    private:
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        int NOLP;
        int LLRN;
        char m_filename[256];
        Publication* PPA[SDDS_LIBRARY_CAPACITY];


        // Instantiates a menu and initializes it with the message argument
        bool confirm(const char* message);
        Menu publicationType;


        // Simple private functions
        void load();
        void save();
        void search();
        void returnPub();
        int search(int numberOfTypes);


        // Methods with confirmation
        void newPublication();
        void removePublication();
        void checkOutPub();
        

    public:
        LibApp();
        ~LibApp();
        LibApp(const char* fileName2);

        // Displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
        void run();
        Publication* getPub(int Ref);

    };
}

#endif
