#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "File.h"

namespace sdds {
FILE* fptr; // Global variable

bool openFile(const char filename[]) {
    fptr = fopen(filename, "r");
    return fptr != nullptr;
}

int noOfRecords() {
    int noOfRecs = 0;
    char ch;
    while (fscanf(fptr, "%c", &ch) == 1) {
        noOfRecs += (ch == '\n');
    }
    rewind(fptr);
    return noOfRecs;
}

void closeFile() {
    if (fptr) {
        fclose(fptr);
    }
}

bool read(int &number) {
    if (fptr == nullptr) {
        // File is not open
        return false;
    }
    
    if (fscanf(fptr, "%d,", &number) == 1) {
        return true;
    }
    return false;
}

bool read(double& salary) {
    if (fptr == nullptr) {
        // File is not open
        return false;
    }
    
    if (fscanf(fptr, "%lf,", &salary) == 1) {
        return true;
    } else {
        return false;
    }
}


bool read(char names[]) {
    if (fptr == nullptr) {
        // File is not open
        return false;
    }
    
    if (fscanf(fptr, "%[^\n]\n", names) == 1) {
        return true;
    }
    return false;
}
}
