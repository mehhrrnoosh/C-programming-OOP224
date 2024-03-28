#pragma once

/*
*****************************************************************************
                              File.h
Full Name  : Mehrnoosh Sarang
Student ID#: 128498227
Email      : msraang@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef UTILS_H
#define UTILS_H
namespace sdds
{

    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}

// header file content goes here

#endif
