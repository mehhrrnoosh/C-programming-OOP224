//
//  LibApp.cpp
//  MS2
//
//  Created by Apple on 2023-07-07.
//

#include "LibApp.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu ("Changes have been made to the data, what would you like to do?")

{
    m_changed=false;
    m_mainMenu << "Add New Publication"
    << "Remove Publication"
    << "Checkout publication from library"
    << "Return publication to library";
    
    m_exitMenu << "Save changes and exit"
    << "Cancel and go back to the main menu";
    load();
}

bool LibApp::confirm(const char* message)
{
    Menu confirmMenu(message);
    confirmMenu << "Yes";
    int userInput = confirmMenu.run();
    return (userInput == 1);
}
void LibApp::load()
{
    cout <<"Loading Data" <<endl;
}

void LibApp::save()
{
    cout <<"Saving Data"<<endl;
}
void LibApp::search()
{
    cout <<"Searching for publication"<< endl;
}

void LibApp::returnPub()
{
    search();
    cout << "Returning publication"<< endl;
    cout << "Publication returned" << endl;
//    cout << endl;
    m_changed = true;
}

void LibApp::newPublication()
{
    cout << "Adding new publication to library" <<endl;
 
    
    if (confirm("Add this publication to library?"))
    {
        cout<<endl;
        m_changed=true;
        cout << "Publication added" <<endl;
    }
//    cout<< endl;
    
}
void LibApp::removePublication()
{
    cout<< "Removing publication from library" <<endl;
    
    search();
    
    if (confirm("Remove this publication from the library?"))
    {
        m_changed=true;
        cout << "Publication removed" << endl;
        
    }
//    cout<< endl;
    
}
void LibApp::checkOutPub()
{
    search();
    if(confirm("Check out publication?"))
    {
        m_changed = true;
        cout << "Publication checked out" << endl;
    }
//    cout << endl;
    
}
void LibApp::run() {
    int menuChoice;

    do {
        menuChoice = m_mainMenu.run();

        switch (menuChoice) {
            case 0:
                if (m_changed) {
                    int exitChoice = m_exitMenu.run();

                    switch (exitChoice) {
                        case 0:
                            if (confirm("This will discard all the changes are you sure?")) {
                                m_changed = false;
                            }
                            break;
                        case 1:
                            save();
                            break;
                        case 2:
                            menuChoice = 1;
                            break;
                    }
                }
//                cout<<endl;
                break;
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
        cout<<endl;
    } while (menuChoice != 0);

    cout << "-------------------------------------------" << endl;
    cout << "Thanks for using Seneca Library Application" << endl;
}

}
