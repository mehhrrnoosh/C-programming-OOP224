
/*
*****************************************************************************
Full Name  : Mehrnoosh Sarang
Student ID#: 128498227
Email      : msraang@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#pragma once
#ifndef FILE_H
#define FILE_H

#include "ShoppingRec.h"

namespace sdds {
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppingRec(const ShoppingRec* rec);
}

#endif
