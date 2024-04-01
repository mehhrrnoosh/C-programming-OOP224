#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {
  Mark::Mark()
  {
    m_mark = 0;
  }

  Mark::Mark(const int value)
  {

    if (value >= 0 && value <= 100) {
      m_mark = value;
    }
    else m_mark = -1;
  }

 
  Mark::operator int() const
  {
    int value = 0;

    if (m_mark >= 0 && m_mark <= 100)
      value = m_mark;

    return value;
  }

Mark::operator double() const {
    double GPA = 0.0;

    if (m_mark >= 50 && m_mark < 60) {
        GPA = 1.0;
    }
    else if (m_mark >= 60 && m_mark < 70) {
        GPA = 2.0;
    }
    else if (m_mark >= 70 && m_mark < 80) {
        GPA = 3.0;
    }
    else if (m_mark >= 80 && m_mark <= 100) {
        GPA = 4.0;
    }

    return GPA;
}

Mark::operator char() const {
    char grade = 'X';

    if (m_mark >= 0 && m_mark < 50) {
        grade = 'F';
    }
    else if (m_mark >= 50 && m_mark < 60) {
        grade = 'D';
    }
    else if (m_mark >= 60 && m_mark < 70) {
        grade = 'C';
    }
    else if (m_mark >= 70 && m_mark < 80) {
        grade = 'B';
    }
    else if (m_mark >= 80 && m_mark <= 100) {
        grade = 'A';
    }

    return grade;
}

  Mark &Mark::operator+=(const int value)
  {
   
    if (m_mark >= 0 && m_mark <= 100)
      m_mark += value;

    return *this;
  }

  Mark &Mark::operator=(const int value)
  {
    // Mark can be set to an integer
    m_mark = value;

    return *this;
  }

  int operator+=(int &value, const Mark &rhs)
  {
    
    int temp = int(rhs); //  I get a help from Mobin for this part

    if (temp >= 0 && temp <= 100)
      value += temp;

    return value;
  }

}
