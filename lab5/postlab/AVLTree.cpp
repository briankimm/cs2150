//Brian Kim, byk6q, 10/9/21, AVLTree.cpp
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
  root = NULL;
}

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}


void AVLTree::calcHeight(AVLNode*& avl){ //void method to help calculate the height 
  if(avl == NULL){
  }
  else {
    calcHeight(avl->left);
    calcHeight(avl->right);
    avl->height = 1 + max(height(avl->left), height(avl->right));
  }
}


// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL){
    root = new AVLNode();
    root->value =x;
  }
  else{
    insert(root, x);
  }
}
void AVLTree::insert(AVLNode*& avl, const string& x){
  if(avl==NULL){
    avl = new AVLNode();
    avl->value = x;
  
  }
  if(x<avl->value){
    insert(avl->left,x);
  }
  if (x>avl->value){
    insert(avl->right, x);
  }
  calcHeight(avl);
  balance(avl);
     
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
  root = remove(root, x);
}

string AVLTree::pathTo(AVLNode* avl, const string& x)const{
  //prints out the path to the AVLnode that is passed through
  string s="";
  if(find(x)){
    if(avl != NULL){
      if(avl->value == x){
	s+=avl->value;
      }
      else if(avl->value > x){
	s+= avl->value + " " + pathTo(avl->left, x);
      }
      else if(avl->value<x){
	s+= avl->value + " " + pathTo(avl->right, x);
      }
    }
  }
  return s;
}
// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return pathTo(root, x);
}
bool AVLTree::find(AVLNode* avl, const string& x)const{
  //checks to see if the node is already in the tree
  if(avl == NULL){
    return false;
  }
  if(x == avl -> value){
    return true;
  }
  else if(x< avl->value){
    return find (avl->left, x);
  }
  else if(x > avl->value){
    return find(avl->right,x);
  }
  return false;

}
// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

int AVLTree::numNodes(AVLNode* avl) const{
  //keeps tracks of the number of Nodes
  if(avl == NULL){
    return 0;
  }
  else{
    if(avl->left !=NULL && avl->right != NULL){
      return 1 + numNodes(avl->left) + numNodes(avl->right);
    }
    else if(avl->left == NULL && avl->right != NULL){
      return 1 + numNodes(avl->right);
    }
    else if(avl->right == NULL && avl->left !=NULL){
      return 1 + numNodes(avl->left);
    }
    else{
      return 1;
    }
  }
}
// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  int x = height(n->right) - height(n->left);
  if(x == 2){
    if((height(n->right->right) - height(n->right->left)) <0){
      AVLNode* n1;
      n1 = rotateRight(n->right);
      n->right = n1;
    }
    n = rotateLeft(n);
  }
  else if(x == -2){
    if((height(n->left->right)- height(n->left->left)) > 0){
      AVLNode* n2;
      n2 = rotateLeft(n->left);
      n->left = n2;
    }
    n = rotateRight(n);
  }
  calcHeight(root);
}
// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode* tempRight = n->right;
  AVLNode* tempRightLeft = n->right->left;
  n->right->left = n ;
  n ->right = tempRightLeft;
  return tempRight;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode* tempLeft = n->left;
  AVLNode* tempLeftRight =n->left -> right;
  n->left->right = n;
  n->left = tempLeftRight;
  return tempLeft;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }

  // first look for x
  if (x == n->value) {
    // found
    if (n->left == NULL && n->right == NULL) {
      // no children
      delete n;
      n = NULL;
      return NULL;
    } else if (n->left == NULL) {
      // Single child (left)
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    } else if (n->right == NULL) {
      // Single child (right)
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    } else {
      // two children -- tree may become unbalanced after deleting n
      string sr = min(n->right);
      n->value = sr;
      n->right = remove(n->right, sr);
    }
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }

  // Recalculate heights and balance this subtree
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);

  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);

  delete trunk;
}

void AVLTree::printTree() {
  printTree(root, NULL, false);
}
