#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

using namespace std;

namespace sdds {
  const char defaultSymbol[9] = "+-+|+-+|";

  class Label
  {
    char m_symbol[9];
    char* m_oneLineText;

  public:
   
    Label();
    Label(const char *frameArg);

    Label(const char *frmaeArg, const char *content);
    ~Label();

    void readLabel();
    std::ostream &printLabel() const;
  };
}
#endif // !SDDS_LABEL_H_
