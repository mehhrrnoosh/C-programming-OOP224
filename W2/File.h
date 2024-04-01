#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

#include "Employee.h"

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();


   // TODO: Declare read prototypes
   bool read(char names[]);
    bool read(int &number);
   bool read(double& salary) ;
}
#endif // !SDDS_FILE_H_
