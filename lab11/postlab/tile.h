//Brian Kim, byk6q, 12.3.21, tile.h
#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>

using namespace std;
class tile{
 public:
  tile();
  tile(string s, int i);

  int getSteps();
  string permutation;
  int steps;
};
#endif
