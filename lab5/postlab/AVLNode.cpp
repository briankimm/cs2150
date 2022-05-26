//Brian Kim, byk6q, AVLNode.cpp, 10/9/21
#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
