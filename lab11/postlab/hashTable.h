//Brian Kim, byk6q, 10/19/21,hashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class hashTable{
 public:
  hashTable();//constructor
  hashTable(int i);//constructor with parameter size
  ~hashTable();//destructor

  bool contains(string s);//find method
  void insert(string s);//insert method
  int hash(string s);//hash method

 private:
  vector<list<string> > v;
  
};
#endif
