//Brian Kim, byk6q, bankAccount.cpp, 9/2/21
#include <iostream>
#include "bankAccount.h"
using namespace std;

//constructors and deconstructor
bankAccount::bankAccount(){
  balance = 0.00;
}
bankAccount::bankAccount(double amount){
  balance = amount;
}
bankAccount::~bankAccount(){
}

//methods
double bankAccount::withdraw(double amount){
 balance = balance - amount;
  return balance;
}
double bankAccount::deposit(double amount){
 balance = balance + amount;
 return balance;
}
double bankAccount::getBalance(){
  return balance;
}
