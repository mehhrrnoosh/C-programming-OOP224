#include <iostream>
#include "LabelMaker.h"
#include <cstring>
using namespace std;

namespace sdds {
  LabelMaker::LabelMaker(int noOfLabels)
  {
    if (noOfLabels > 0) {
      m_totalLabels = noOfLabels;

      m_Labels = new Label[noOfLabels];
    }
    else {
      cout << "You can only input greater than zero" << endl;
      noOfLabels = 0;
    }
  }

  LabelMaker::~LabelMaker()
  {
    delete[] m_Labels;
    m_Labels = nullptr;
  }

  void LabelMaker::readLabels()
  {
    if (m_totalLabels > 0) {
      cout << "Enter " << m_totalLabels << " labels:" << endl;

      for (int i = 0; i < m_totalLabels; i++) {
        cout << "Enter label number " << i + 1 << endl;
        m_Labels[i].readLabel();
      }
    }
  }

  void LabelMaker::printLabels()
  {
    for (int i = 0; i < m_totalLabels; i++) {
      m_Labels[i].printLabel();
      cout << endl;
    }
  }
}
