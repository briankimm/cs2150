//Brian Kim, byk6q, 11/2/21, mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product(long, long);
extern "C" long power(long, long);

int main(){
  long x, y, a, b;//declare variables
  cout<<"Enter integer 1: ";
  cin >> x;//takes in first integer
  cout<<"Enter integer 2: ";
  cin >> y;//takes in second integer

  a = product(x, y);//product
  b = power(x, y);//power

  cout<<"Product: " << a << endl;//returns product
  cout<<"Power: " << b << endl;//returns power
  return 0;
}
