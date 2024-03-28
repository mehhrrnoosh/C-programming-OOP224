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

#include "cstring.h"

void sdds::strCpy(char* des, const char* src) {
    // Check if the destination has enough space
    if (des != nullptr) {
        while (*src != '\0') {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';
    }
}
void sdds::strnCpy(char* des, const char* src, int len) {
    int i;
    for (i = 0; i < len && src[i] != '\0'; i++) {
        des[i] = src[i];
    }
    for (; i < len; i++) {
        des[i] = '\0';
    }
}

int sdds::strCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    if (*s1 == *s2) {
        return 0;  // Strings are the same
    } else if (*s1 > *s2) {
        return 1;  // s1 is lexicographically greater than s2
    } else {
        return -1; // s1 is lexicographically less than s2
    }
}

int sdds::strnCmp(const char* s1, const char* s2, int len) {
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        if (s1[i] == '\0' || s2[i] == '\0') {
            return 0;
        }
    }
    return 0;
}
int sdds::strLen(const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
const char* sdds::strStr(const char* str1, const char* str2) {
    if (*str2 == '\0') {
        return str1;  // Edge case: empty str2, return str1 as match
    }

    while (*str1 != '\0') {
        const char* p1 = str1;
        const char* p2 = str2;

        while (*p1 == *p2 && *p1 != '\0') {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return str1;
        }

        str1++;  // Increment str1 to search for the next potential match
    }

    return nullptr;  // No match found
}
void sdds::strCat(char* des, const char* src) {

    while (*des != '\0') {
        des++;
    }
    while (*src != '\0') {
        *des = *src;
        des++;
        src++;
    }
    *des = '\0';
}


