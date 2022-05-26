//Brian Kim, byk6q, 9/13/21, postfixCalculator.cpp
#include "postfixCalculator.h"
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

//constructor
postfixCalculator::postfixCalculator(){
  
}
//destructor
postfixCalculator::~postfixCalculator(){

}
void postfixCalculator::add(){//add function
  int a = s.top();
  s.pop();
  int b = s.top();
  s.pop();
  s.push(a+b);
  
}
void postfixCalculator::subtract(){//subtract function
  int a = s.top();
  s.pop();
  int b = s.top();
  s.pop();
  s.push(b-a);
}
void postfixCalculator:: multi(){
  int a = s.top();
  s.pop();
  int b = s.top();
  s.pop();
  s.push(a*b);
}
void postfixCalculator::div(){
  int a = s.top();
  s.pop();
  int b = s.top();
  s.pop();
  s.push(b/a);
}
void postfixCalculator::negation(){
  int a = s.top() * (-1);
  s.pop();
  s.push(a);
}
void postfixCalculator::calc(){//postfix calculator
  string token;
  int operatorCount = 0;
  int numbers = 0;
  while(cin >> token){
    if(token == "+"){
      add();
  }
    else if(token == "-"){
      subtract();
    }
    else if(token == "*"){
      multi();
    }
    else if(token == "/"){
      div();
    }
    else if(token == "~"){
      negation();
    }
    else{
      s.push(stoi(token));
    }
  }
  cout<< s.top()<< endl;
}
