//Brian Kim, byk6q, 11.22.21, heap.h
//taken from lecture slides on binary_heap.h
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "hNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<hNode*> vec);//changed from int to Huffman Node pointers
    ~heap();

    void insert(hNode* x);
    hNode* findMin();
    hNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<hNode*> h;//vector of Huffman Nodes
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);

    friend class huffmanenc;//huffmanenc can see methods from this class

    
};

#endif
