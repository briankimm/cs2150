//Brian Kim, byk6q, 10/19/21, hashTable.cpp
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "hashTable.h"

hashTable::hashTable(){//initializes a new vector of lists with a random high number 
  for(int i = 0; i<10000;i++){
    v.push_back(list<string>());
  }
}
hashTable::hashTable(int i){//takes in i as a parameter
  v = vector<list<string> >(i);
}
hashTable:: ~hashTable(){

}
bool hashTable::contains(string s){//checks to find if s is in the hashTable
  list<string>l = v[hash(s)];
  return std::find(l.begin(), l.end(), s) != l.end();//stackoverflow
}
void hashTable::insert(string s){//puts s at the end of the vector
  int x = hash(s);
  v[x].push_back(s);
}
int hashTable::hash(string s){//used from the lecture slide
  int count = 0;
  for(int i = 0;i<s.length();i++){
    count = int(s[i]) + count*37;
  }
  return count% v.size();
}

