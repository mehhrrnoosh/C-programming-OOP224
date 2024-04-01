#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999 && balance >= 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0) {
            return true;
        }
        return false;
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }

    bool Account::operator~() const {
        return m_number == 0;
    }

    Account& Account::operator=(int accountNumber) {
        if (m_number == 0) {
            m_number = accountNumber;
        }
        else if (accountNumber < 0) {
            setEmpty();
        }
        return *this;
    }

Account& Account::operator=( Account& otherAcc){
        if (this->m_number == 0 && otherAcc.m_number > 0) {
            this->m_number = otherAcc.m_number;
            this->m_balance = otherAcc.m_balance;

            otherAcc.m_number = 0;
            otherAcc.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator+=(const double value) {
        if (m_number > 0 && m_balance >= 0.0 && value > 0.0) {
            m_balance += value;
        }
        return *this;
    }

    Account& Account::operator-=(const double value) {
        if (m_number > 0 && m_balance >= value && value >= 0.0) {
            m_balance -= value;
        }
        return *this;
    }

    Account& Account::operator<<(Account& Acc) {
        if (this->m_number > 0 && Acc.m_number > 0 && this->m_number != Acc.m_number) {
            m_balance += Acc.m_balance;
            Acc.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& Acc) {
        if (this->m_number > 0 && Acc.m_number > 0 && this->m_number != Acc.m_number) {
            Acc.m_balance += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    }

    double operator+(const Account& left, const Account& right) {
        double sum = 0.0;
        if (left.m_number > 0 && right.m_number > 0) {
            sum = left.m_balance + right.m_balance;
        }
        return sum;
    }

    double operator+=(double& left, const Account& right) {
        if (right.m_number > 0) {
            left += right.m_balance;
        }
        return left;
    }
}
