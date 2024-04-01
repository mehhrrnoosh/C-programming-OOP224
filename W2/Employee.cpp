#include "Employee.h"
#include <cstdio>
#include <iostream>
#include <cstring>  // implemented in workshop 1 part 2 (DIY)

#include "File.h"
using namespace std;
namespace sdds {

int noOfEmployees;
Employee *employees;


void sort() {
    int i, j;
    Employee temp;
    for (i = noOfEmployees - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

// TODO: Finish the implementation of the 1 arg load function which
// reads one employee record from the file and loads it into the employee reference
// argument
bool load(Employee& emp) {
    bool ok = false;
    char name[128];
    
    if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {
//        int len = strlen(name);
        emp.m_name = new char[strlen(name) + 1];
        strcpy(emp.m_name, name);
        ok = true;
    }
    
    return ok;
}


bool load() {
    bool ok = false;
    int i = 0;
    if (openFile(DATAFILE)) {
        noOfEmployees = noOfRecords();

        employees = new Employee[noOfEmployees];

        for (i = 0; i < noOfEmployees; i++) {
            if (!load(employees[i])) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;

                // Clean up resources and return false
                delete[] employees;
                employees = nullptr;
                noOfEmployees = 0;
                closeFile();
                return ok;
            }
        }

        // Data loading successful
        ok = true;

        // Close the file
        closeFile();
    }
    else {
        cout << "Could not open data file: " << DATAFILE << endl;
    }

    return ok;
}




// TODO: Implementation for the display functions go here

void display(const Employee &emp) {
    cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
}

void display() {
    cout << "Employee Salary report, sorted by employee number" << endl;
    cout << "no- Empno, Name, Salary" << endl;
    cout << "------------------------------------------------" << endl;
  
    if (employees != nullptr) {
        // Sort the array by employee number
        sort();

        // Iterate over the sorted array and print each employee
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- "  ;

            display(employees[i]);
        }
    } else {
        cout << "No employees to display." << endl;
    }
}
// TODO: Implementation for the deallocateMemory function goes here
void deallocateMemory() {
    if (employees != nullptr) {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
    }
}
}
