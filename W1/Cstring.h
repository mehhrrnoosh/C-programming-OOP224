/*
*****************************************************************************
                              cstring.cpp
Full Name  : Mehrnoosh Sarang
Student ID#: 128498227
Email      : msarang@myseneca.ca
Date of completion    : 19 May 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds
{
    void strCpy(char* des, const char* src);

    void strnCpy(char* des, const char* src, int len);

    int strCmp(const char* s1, const char* s2);

    int strnCmp(const char* s1, const char* s2, int len);

    int strLen(const char* s);

    const char* strStr(const char* str1, const char* str2);

    void strCat(char* des, const char* src);
}


#endif
