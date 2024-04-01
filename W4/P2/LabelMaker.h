#ifndef SDDS_LABELMARKER_H_
#define SDDS_LABELMARKER_H_

#include "Label.h"

using namespace std;

namespace sdds {
  class LabelMaker
  {
    Label *m_Labels;
    int m_totalLabels;

  public:
    LabelMaker(int noOfLabels);
    ~LabelMaker();

    void readLabels();
    void printLabels();
  };
}
#endif // !SDDS_LABELMARKER_H_
