//
//  Publication.cpp
//  Streamable
//
//  Created by Apple on 2023-07-19.
//

#include "Publication.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Lib.h"

namespace  sdds {
Publication::Publication ()
{
    defaultValue();
    
}
Publication::~Publication() {
    delete[] m_title;
}

void Publication::defaultValue() {
    m_title = nullptr;
    m_shelfId[0] = '\0';
    m_membership = 0;
    m_libRef = -1;
    resetDate();
}
Publication& Publication::operator=(const Publication& publication) {
    set(publication.m_membership);
    setRef(publication.m_libRef);
    strcpy(m_shelfId, publication.m_shelfId);
    m_date = publication.m_date;
    
    if (m_title!=nullptr)
    {
        delete[] m_title;
        m_title = nullptr;
    }
    if (publication.m_title != nullptr) {
        m_title = new char[strlen(publication.m_title) + 1];
        strcpy(m_title, publication.m_title);
    }
    else {
        m_title = nullptr;
    }
    
    return *this;
}


Publication::Publication(const Publication& publication) {
    *this = publication;
}
void Publication::set(int member_id) {
    m_membership = member_id;
}
int Publication::getRef() const {
    return m_libRef;
}
void Publication::setRef(int value) {
    m_libRef = value;
}
void Publication::resetDate() {
    m_date = Date();
}
char Publication::type() const {
    return 'P';
}
bool Publication::onLoan() const {
    return (m_membership!=0);
}

Date Publication::checkoutDate() const {
    return m_date;
}

bool Publication::operator==(const char* title) const {
    return strstr(m_title, title) != nullptr;
}
Publication::operator const char* () const
{
    return m_title;
}
bool Publication::conIO(std::ios& io) const
{
    return &io == &std::cin || &io == &std::cout; //mobin

}
std::ostream& Publication::write(std::ostream& os) const {
    if (conIO(os)) {
        os << "| " << m_shelfId << " | " << std::setw(30) << std::left << std::setfill('.') << m_title << " | " ;
        (m_membership != 0) ? os << m_membership : os << " N/A ";
        os << " | " << m_date << " |";
    }
    else {
        os << type() << "\t";
        os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
        (m_membership != 0) ? os << m_membership : os << " N/A ";
        os << "\t" << m_date;
    }

    return os;
}
std::istream& Publication::read(std::istream& is) {
    
    char _title[SDDS_TITLE_WIDTH + 1]{};
    char _shelfId[SDDS_SHELF_ID_LEN + 1]{};
    int _libRef = -1, t_membership = 0;
    Date _date;

    if (m_title) {
        delete[] m_title;
        m_title = nullptr;
    }
    defaultValue();

    if (conIO(is)) {
        std::cout << "Shelf No: ";
        is.getline(_shelfId, SDDS_SHELF_ID_LEN + 1);

        if (strlen(_shelfId) != SDDS_SHELF_ID_LEN) {
            is.setstate(std::ios::failbit);
        }

        std::cout << "Title: ";
        is.getline(_title, SDDS_TITLE_WIDTH + 1);

        std::cout << "Date: ";
        is >> _date;
    }

    else {
        is >> _libRef;
        is.ignore();
        is.getline(_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
        is.getline(_title, SDDS_TITLE_WIDTH + 1, '\t');
        is >> t_membership;
        is.ignore();
        is >> _date;
    }

    if (!_date) {
        is.setstate(std::ios::failbit);
    }

    if (is) {
        m_title = new char[strlen(_title) + 1];
        strcpy(m_title, _title);
        strcpy(m_shelfId, _shelfId);
        m_membership = t_membership;
        m_date = _date;
        m_libRef = _libRef;
    }

    return is;
}
Publication::operator bool() const {
    bool result = false;
    if (m_title != nullptr && m_shelfId[0] != '\0') {
        result = true;
    }

    return result;
}

}
