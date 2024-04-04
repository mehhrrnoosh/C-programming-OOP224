


#include <fstream>
#include <cstring>
#include <iomanip>
#include "LibApp.h"
#include "Menu.h"
#include "PublicationSelector.h"
using namespace std;
namespace sdds {
//    LibApp::LibApp(): m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
//        m_changed = false;
//
//        // Populating main menu items using operator overload in Menu class
//        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
//
//        // Populating exit menu items using operator overload in Menu class
//        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
//
//        load();
//    }
LibApp::LibApp(const char* otherFile) : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), publicationType("Choose the type of publication:")
{
    if (m_filename)
    {
        strcpy(m_filename, otherFile);
    }
    
    m_changed = false;
    NOLP = 0;
    
    m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
    
    m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
    
    publicationType << "Book" << "Publication";
    
    load();
}


bool LibApp::confirm(const char* message) {
    bool result = false;
    Menu menu(message);
    menu << "Yes";
    
    int returnedValue = menu.run();
    if (returnedValue == 1) {
        result = true;
    }
    
    return result;
}
void LibApp::load()
{
    cout << "Loading Data" << endl;
    
    ifstream oFile(m_filename);
    
    char typeCharacter;
    int i;
    
    for (i = 0; oFile && i < SDDS_LIBRARY_CAPACITY; i++)
    {
        oFile >> typeCharacter;
        
        oFile.ignore();
        
        if (oFile)
        {
            if (typeCharacter == 'P')
            {
                PPA[i] = new Publication;
            }
            else if (typeCharacter == 'B')
            {
                PPA[i] = new Book;
            }
            
            if (PPA[i])
            {
                oFile >> *PPA[i];
                
                NOLP++;
                LLRN = PPA[i]->getRef();
            }
        }
    }
}


void LibApp::save()
{
    cout << "Saving Data" << endl;
    
    ofstream wFile(m_filename);
    int i;
    
    
    for (i = 0; i < NOLP; i++)
    {
        if (PPA[i]->getRef()!= 0)
        {
            wFile << *PPA[i] <<endl;
        }
    }
    
    wFile.close();
}

int LibApp::search(int numberOfTypes) {
    char publicationTitle[256];
    int selectedType = 0;
    int i = 0;
    int libraryRefNum = 0;
    char typeCharacter;
    
    
    PublicationSelector pubSelector("Select one of the following found matches:", 15);
    selectedType = publicationType.run();
    if(selectedType ==1)
    {
        typeCharacter ='B';
    }
    else if (selectedType == 2)
    {
        typeCharacter = 'P';
    }
    cin.ignore (1000, '\n');
    cout << "Publication Title: ";
    cin.getline(publicationTitle, 256);
    
    if (numberOfTypes == 1)
    {
        for (i = 0; i < NOLP; i++)
        {
            if (PPA[i]->operator==(publicationTitle) && typeCharacter == PPA[i]->type() && PPA[i]->getRef() != 0)
            {
                pubSelector << PPA[i];
            }
        }
    }
    else if (numberOfTypes == 2)
    {
        for (i = 0; i < NOLP; i++)
        {
            if (PPA[i]->operator==(publicationTitle) && PPA[i]->onLoan() && typeCharacter == PPA[i]->type() && PPA[i]->getRef() != 0)
            {
                pubSelector << PPA[i];
            }
        }
    }
    else if (numberOfTypes == 3)
    {
        for (i = 0; i < NOLP; i++)
        {
            if (PPA[i]->operator==(publicationTitle) && !PPA[i]->onLoan() && typeCharacter == PPA[i]->type() && PPA[i]->getRef() != 0)
            {
                pubSelector << PPA[i];
            }
        }
    }
    if (pubSelector)
    {
        pubSelector.sort();
        libraryRefNum= pubSelector.run();
        
        if (libraryRefNum > 0)
        {
            cout << *getPub(libraryRefNum) << endl;
        }
        else
        {
            cout << "Aborted!" << endl;
        }
    }
    else
    {
        cout << "No matches found!" << endl;
    }
    
    return libraryRefNum;
}


//    void LibApp::returnPub() {
//        search();
//        std::cout << "Returning publication" << std::endl;
//        std::cout << "Publication returned" << std::endl;
//        std::cout << std::endl;
//        m_changed = true;
//    }
void LibApp::returnPub()
{
    bool exitFlag = false;
    cout << "Return publication to the library" << endl;
    
    int libRef = search(2);
    if (!(libRef > 0))
    {
        exitFlag = true;
    }
    
    if (!exitFlag)
    {
        bool success = confirm("Return Publication?");
        
        if (success) {
            int loanDuration = Date() - getPub(libRef)->checkoutDate();
            
            if (loanDuration > SDDS_MAX_LOAN_DAYS)
            {
                double lateFee = (loanDuration - SDDS_MAX_LOAN_DAYS) * 0.5;
                cout << fixed << setprecision(2);
                cout << "Please pay $" << lateFee << " penalty for being " << (loanDuration - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
            }
            getPub(libRef)->set(0);
            m_changed = true;
        }
        
        cout << "Publication returned" << endl;
    }
    
    cout << endl;
}
void LibApp::newPublication()
{
    bool exitFlag = false;
    if (NOLP == SDDS_LIBRARY_CAPACITY)
    {
        cout << "Library is at its maximum capacity!" << endl;
        exitFlag = true;
    }
    
    if (!exitFlag) {
        cout << "Adding new publication to the library" << endl;
        
        int pubType = publicationType.run();
        cin.ignore(1000, '\n');
        Publication* ptr = nullptr;
        
        if (pubType == 0)
        {
            cout << "Aborted!" << endl;
            exitFlag = true;
        }
        
        else if (pubType == 1)
        {
            ptr = new Book;
            cin >> *ptr;
        }
        
        else if (pubType == 2)
        {
            ptr = new Publication;
            cin >> *ptr;
        }
        
        if (cin.fail())
        {
            cin.ignore(1000, '\n');
            cin.clear();
            cout << "Aborted!" << endl;
            exit(0);
        }
        else {
            if (!exitFlag && confirm("Add this publication to the library?"))
            {
                if (!*ptr)
                {
                    cout << "Failed to add publication!" << endl;
                    delete ptr;
                }
                else
                {
                    LLRN++;
                    ptr->setRef(LLRN);
                    PPA[NOLP] = ptr;
                    
                    NOLP++;
                    m_changed = true;
                    
                    cout << "Publication added" << endl;
                }
            }
        }
    }
    
    cout << endl;
}
//    // Methods with confirmation
//    void LibApp::newPublication() {
//        std::cout << "Adding new publication to library" << std::endl;
//        bool confirmed = confirm("Add this publication to library?");
//        if (confirmed) {
//            m_changed = true;
//            std::cout << "Publication added" << std::endl;
//        }
//        std::cout << std::endl;
//    }

//    void LibApp::removePublication() {
//        std::cout << "Removing publication from library" << std::endl;
//        search();
//        bool confirmed = confirm("Remove this publication from the library?");
//        if (confirmed) {
//            m_changed = true;
//            std::cout << "Publication removed" << std::endl;
//        }
//        std::cout << std::endl;
//    }
void LibApp::removePublication()
{
    cout << "Removing publication from the library" << endl;
    
    int libRef = search(1);
    if (libRef!=0)
    {
        if (confirm("Remove this publication from the library?"))
        {
            getPub(libRef)->setRef(0);
            
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }
    
    cout << endl;
}

//    void LibApp::checkOutPub() {
//        search();
//        bool confirmed = confirm("Check out publication?");
//        if (confirmed) {
//            m_changed = true;
//            std::cout << "Publication checked out"<< std::endl;
//        }
//        std::cout << std::endl;
//    }
void LibApp::checkOutPub()
{
    cout << "Checkout publication from the library" << endl;
    
    int libRef = search(3);
    
    if (libRef > 0)
    {
        bool success = confirm("Check out publication?");
        if (success)
        {
            cout << "Enter Membership number: ";
            int userMembershipNumber = getInput(10000, 99999, "Invalid membership number, try again: ");
            
            getPub(libRef)->set(userMembershipNumber);
            
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }
    cout << endl;
}


// Displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
void LibApp::run() {
    int userInputMenu, userInputExit;
    
    do {
        userInputMenu = m_mainMenu.run();
        
        switch (userInputMenu) {
            case 0:
                if (m_changed == true) {
                    userInputExit = m_exitMenu.run();
                    
                    switch (userInputExit) {
                        case 0:
                            if (confirm("This will discard all the changes are you sure?")) {
                                m_changed = false;
                            }
                            break;
                        case 1:
                            save();
                            break;
                        case 2:
                            userInputMenu = 1;
                            break;
                    }
                }
                std::cout << std::endl;
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
        }
    }
    while (userInputMenu != 0); // If the user doesn't opt exit, ask for inputs again and again
    
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Thanks for using Seneca Library Application" << std::endl;
}

Publication* LibApp::getPub(int libRef)
{
    Publication* foundPublication = nullptr;
    
    for (int i = 0; i < NOLP; i++)
    {
        if (PPA[i]->getRef() == libRef)
        {
            foundPublication = PPA[i];
        }
    }
    
    return foundPublication;
}


LibApp::~LibApp()
{
    for (int i = 0; i < NOLP; i++)
    {
        delete PPA[i];
    }
}
}
