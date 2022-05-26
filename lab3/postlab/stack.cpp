//Brian Kim, byk6q, stack.cpp, 9/15/21
#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(){
  
}
stack::~stack(){
  l.makeEmpty();
}
void stack::push(int e){
  l.insertAtTail(e);
}
void stack::pop(){
  l.remove();
}
int stack::top(){
  ListItr last = l.last();
  return last.retrieve();
}
bool stack::empty(){
  return l.isEmpty();
}
