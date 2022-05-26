//Brian Kim, byk6q, 9/19/21, prelab4.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include <climits>
using namespace std;

void sizeOfTest(){
  cout << "Size of int: "<< sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}
void overflow(){
  unsigned int a = UINT_MAX;
  cout << a << "+ 1 = " << a + 1 << endl;
}
void outputBinary(unsigned int x){
  string str = "";
  int count = 0;
  while(str.length() < 39){
    if(x % 2 == 0){
      str+= "0";
    }
    else{
      str+="1";
    }
    x/=2;
    count++;
    if(count % 4 == 0 && count !=32){
	str+= " ";
      }
      
  }
  string newstr = "";
  for(int i = str.length() - 1; i>=0;i--){
    newstr+=str[i];
  }
    cout << newstr << endl;
}

int main(){//main method
  int x;
  cin>> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}
