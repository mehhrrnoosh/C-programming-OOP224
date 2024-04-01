#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>

namespace sdds
{
  class Mark
  {
    int m_mark;

  public:
    Mark();
    Mark(const int input);
    ~Mark(){};

    
    operator int() const;
    operator double() const;
    operator char() const;


    Mark &operator+=(const int input);
    Mark &operator=(const int input);

  };
 
  int operator+=(int &_value, const Mark &_add); //  helper function 
}
#endif
