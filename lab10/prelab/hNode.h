//Brian Kim, byk6q, hNode.cpp, 11/22/21
#ifndef HNODE_H
#define HNODE_H
#include <iostream>
//class for Huffman Nodes 
using namespace std;
class hNode{
public:
  hNode();
  hNode(char c, int x);
  hNode* left;
  hNode* right;
  char value;
  int frequency;

  friend class heap;
};

#endif
