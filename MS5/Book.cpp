//
//  Book.cpp
//  MS4
//
//  Created by Apple on 2023-07-31.
//

#include "Book.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds
{
Book::Book() : Publication ()
{
    m_authorName =nullptr;
}

Book::Book (const Book& other) : Publication(other)
{
    if(m_authorName!=nullptr)
    {
        delete [] m_authorName;
        m_authorName=nullptr;
    }
    m_authorName = new char [strlen(other.m_authorName)+1];
    strcpy(m_authorName, other.m_authorName);
}
Book& Book::operator=(const Book& other)
{
    Publication::operator=(other);
    
    if(m_authorName!=nullptr)
    {
        delete [] m_authorName;
        m_authorName = nullptr;
    }
    if(other.m_authorName!=nullptr)
    {
        m_authorName = new char[strlen(other.m_authorName)+1];
        strcpy(m_authorName, other.m_authorName);
    }
    return *this;
}
Book::~Book() {
    delete[] m_authorName;
}
char Book::type() const
{
    return 'B';
}

ostream& Book::write(ostream& os) const
{
    Publication::write(os);
    if (conIO(os)) {
        char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
        std::strncpy(author, m_authorName, SDDS_AUTHOR_WIDTH);
        os << " ";
        os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ')<<  author << " |";
    }
    else {
        os << "\t" << m_authorName;
    }

    return os;
}
istream& Book::read(istream& is)
{
    
char temp[256] = { 0 };

Publication::read(is);

if (m_authorName) {
    delete[] m_authorName;
    m_authorName = nullptr;
}

if (conIO(is)) {
    is.ignore(); //ignore '\n'
    std::cout << "Author: ";
}
else {
    is.ignore(1000, '\t');
}

is.getline(temp, 256);

if (is) {
    m_authorName = new char[strlen(temp) + 1];
    strcpy(m_authorName, temp);
}

return is;
}

void Book::set(int member_id)
{
    Publication::set(member_id);
    Publication::resetDate();
}

Book::operator bool() const
{
    return m_authorName && m_authorName[0] != '\0' && Publication::operator bool();
}


}
