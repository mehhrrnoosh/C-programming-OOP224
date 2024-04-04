//
//  Book.hpp
//  MS4
//
//  Created by Apple on 2023-07-31.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include "Publication.h"

namespace sdds {

class Book : public Publication
{
private:
    char* m_authorName;
public:
    Book();
    //The rule of three
    ~Book();
    Book (const Book& obj);
    Book& operator=(const Book& obj);
    char type() const;
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& is);
    virtual void set(int member_id);
    operator bool() const;


};

}

#endif /* Book_hpp */
