//Brian Kim, byk6q, 10/5/21, BinarySearchTree.cpp
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}


void BinarySearchTree::insert(BinaryNode* node, const string& x) {
  if(root==NULL){
    root = new BinaryNode();
    root -> value = x;
  }
  else{
    if(x<node->value){
      if(node->left==NULL){
	node->left = new BinaryNode();
	node->left->value = x;
      }
      else{
	insert(node->left,x);
      }
    }
    else if(x > node -> value){
      if(node->right == NULL){
	node->right = new BinaryNode();
	node->right->value = x;
      }
      else{
	insert(node->right,x);
      }
    }
  }
}


// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  insert(root,x);
}


// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
  root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}
string BinarySearchTree::pathTo(BinaryNode* node, const string& x) const{
  string s = "";
  if(find(x)){
    if(node !=NULL){
      if(node->value == x){
	s+=node->value;
      }
      else if(x < node->value){
	s+=node->value + " " + pathTo(node->left, x);
      }
      else if(x>node->value){
	s+=node->value + " " + pathTo(node->right, x);
      }
    }
  }
  return s;
}
// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return pathTo(root, x);
  
}

bool BinarySearchTree::find(BinaryNode* node, const string& x) const{
    if(node == NULL){
      return false;
}
    if(x == node -> value){
      return true;
    }
    else if(x<  node->value){
      return find (node->left, x);
    }
    else if(x > node->value){
      return find(node->right,x);
    }
    return false;
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
  
}
 
int BinarySearchTree::numNodes(BinaryNode* node)const{
  if(node == NULL){
    return 0;
  }
  else{
    if(node->left !=NULL && node->right != NULL){
      return 1 + numNodes(node->left) + numNodes(node->right);
    }
    else if(node->left == NULL && node->right != NULL){
      return 1 + numNodes(node->right);
    }
    else if(node->right == NULL && node->left !=NULL){
      return 1 + numNodes(node->left);
    }
    else{
      return 1;
    }
  }
}
// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
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

