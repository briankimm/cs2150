//Brian Kim, byk6q, bitCounter.cpp, 9/22/21
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int bitCounter(int x){
  if(x == 0){
    return 0;
  }
  if(x == 1){
    return 1;
  }
  if(x % 2 == 0){
    return bitCounter(x/2);
  }
  return 1 + bitCounter(x/2);
}
string baseConverter(string str, int startBase, int endBase){
  int converted = 0;
  int inBaseTen = 0;
  int counter = str.length() - 1;
  //converts from startBase to base 10
  for(int i = 0;i<str.length();i++){
    char s = str[i];
    converted = s - '0';
    if(converted < 10){
      inBaseTen += converted * pow(startBase, counter);
    }
    else{
      converted = converted - 7;
      inBaseTen += converted * pow(startBase, counter);
    }
      counter--;
  }
  //converts from base 10 to base endBase
  string end = "";
  while(inBaseTen>0){
    if(inBaseTen % endBase == 0){
      end += '0';
    }
    else{
      if(inBaseTen % endBase >= 10){
	char something = inBaseTen % endBase + 55;
	end += something;
      }
      else{
	end += inBaseTen % endBase + '0';
      }
    }
    inBaseTen = inBaseTen / endBase;
  }
  string newend = "";
  for(int i = end.length() -1; i>=0; i--){
    newend+=end[i];
  }
  return newend;
}
int main(int argc, char **argv){
  int arg1 = atoi(argv[1]);
  string arg2 = argv[2];
  int arg3 = atoi(argv[3]);
  int arg4 = atoi(argv[4]);
  string baseConverted = baseConverter(arg2, arg3, arg4);

  cout << to_string(arg1) + " has " + to_string(bitCounter(arg1)) + " bit(s)" << endl;

  cout << arg2 + " (base " + to_string(arg3) + ") = " + baseConverted + " (base " + to_string(arg4) + ")"<< endl;

  return 0;
}
