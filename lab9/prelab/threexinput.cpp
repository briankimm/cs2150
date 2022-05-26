//Brian Kim, threexinput.cpp, byk6q, 11/16/21
#include <iostream>
#include <cstdlib>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int);

int main(){
  int x;
  int y;
  double average;
  timer t;
  cin >> x;
  cin >> y;
  t.start();
  for(int i = 0; i< y; i++){
    threexplusone(x);
  }
  t.stop();
  average = t.getTime() / y;
  cout<<  threexplusone(x) << endl;

  return 0;
}
