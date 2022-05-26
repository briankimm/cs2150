//Brian Kim, byk6q, 9/15/21, stack.h
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "List.h"
using namespace std;
class stack{
public:
  stack();//default constructor
  ~stack();//destructor
  void push(int e);//adds passed element to the top of the stack
  void pop();//removes the element on the top of the stack, but it doesn't return it
  int top();//returns the element on the top of the stack
  bool empty();//checks to see if the stack is empty
 private:
  List l;
};
#endif
