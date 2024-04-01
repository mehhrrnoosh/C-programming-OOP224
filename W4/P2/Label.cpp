#include <iostream>
#include "Label.h"
#include <cstring>

using namespace std;

namespace sdds {
  Label::Label()
  {
    
    strcpy(m_symbol, defaultSymbol);

   
    m_oneLineText = nullptr;
  }

  Label::Label(const char *frameArg)
  {
   
    strcpy(m_symbol, frameArg);
    m_oneLineText = nullptr;
  }

  Label::Label(const char *frameArg, const char *content)
  {
    
    strcpy(m_symbol, frameArg);

    if (strlen(content) < 71) {
      m_oneLineText = new char[strlen(content) + 1];
      strcpy(m_oneLineText, content);
    }
  }

  Label::~Label()
  {
   
    if (m_oneLineText) {
      delete[] m_oneLineText;
      m_oneLineText = nullptr;
    }
  }

  void Label::readLabel()
  {
    char content[71];

    if (m_oneLineText != nullptr) {
      delete[] m_oneLineText;
      m_oneLineText = nullptr;
    }

    cout << "> ";
    cin.get(content, 71);

    cin.ignore(32767, '\n');

    m_oneLineText = new char[strlen(content) + 1];
    strcpy(m_oneLineText, content);
  }

  std::ostream& Label::printLabel() const
  {
    if (m_oneLineText != nullptr) {
        int middleSpace = static_cast<int>(strlen(m_oneLineText));

      cout << m_symbol[0];
      cout.fill(m_symbol[1]);
      cout.width(middleSpace + 3);
      cout << m_symbol[2] << endl;

      cout << m_symbol[7];
      cout.fill(' ');
      cout.width(middleSpace + 3);
      cout << m_symbol[3] << endl;

      cout << m_symbol[7];
      cout.width(middleSpace + 1);
      cout << m_oneLineText;
      cout << " " << m_symbol[3] << endl;

      cout << m_symbol[7];
      cout.fill(' ');
      cout.width(middleSpace + 3);
      cout << m_symbol[3] << endl;

      cout << m_symbol[6];
      cout.fill(m_symbol[5]);
      cout.width(middleSpace + 3);
      cout << m_symbol[4];
    }

    return cout;
  }
}
