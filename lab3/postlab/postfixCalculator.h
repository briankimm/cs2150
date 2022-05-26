//Brian Kim, byk6q, 9/13/21, postfixCalculator.h
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include "stack.h"

using namespace std;
class postfixCalculator {
 public:
  postfixCalculator(); //default constructor
  ~postfixCalculator(); //destructor
  void add();//add method
  void subtract();//subtract method
  void multi();// multiplication method
  void div();//division method
  void negation();//unary negation
  void calc();
 private:
  stack <int> s; // stack to hold the elements
};
#endif
