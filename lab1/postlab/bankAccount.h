//Brian Kim, byk6q, bankAccount.h, 9/2/21
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;
class bankAccount{
 public:
  bankAccount();//default constructor
  bankAccount(double amount);// constructor with amount parameter
  ~bankAccount();// destructor

  double withdraw(double amount);//method that withdraws the specified amount
  double deposit(double amount);//method that deposits the specified amount
  double getBalance();//method that will return the balance
 private:
  double balance;//private variable that will hold the amount of money
};

#endif
