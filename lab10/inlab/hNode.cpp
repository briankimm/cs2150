//Brian Kim, byk6q, hNode.cpp, 11/22/21
#include <iostream>
#include "hNode.h"

using namespace std;
//implementation of Huffman Node class
hNode::hNode(){
  left = NULL;
  right = NULL;
  value = '+';
  frequency = 0;
}
hNode::hNode(char c, int x){
  left = NULL;
  right = NULL;
  value = c;
  frequency = x;
}
