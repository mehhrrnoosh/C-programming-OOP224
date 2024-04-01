#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance;
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // type conversion operator
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;

      // unary operator overloading
      Account& operator=(int accountNumber);
      Account& operator=( Account& otherAcc);

      Account& operator+=(const double value);
      Account& operator-=(const double value);
      Account& operator<<(Account& Acc);
      Account& operator>>(Account& Acc);

      friend double operator+(const Account& left, const Account& right);
      friend double operator+=(double& _value, const Account& _add);
   };
}

#endif // SDDS_ACCOUNT_H_
