//Brian Kim, byk6q, 11/22/21, huffmanenc.cpp
// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.
//taken from fileio.cpp

// included so we can use cout
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include<unordered_map>
#include<vector>
#include<map>
#include "heap.h"
#include "hNode.h"//implements both helper class

using namespace std;


//global method and variable
void prefix(hNode* h, string s);
unordered_map<char, string> u;

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    unordered_map<char, int> frequencyMap;
    char g;
    heap h;
    int count = 0;


    //step 1 (Read the source file and determine the frequencies of the characters in the file)
    while (file.get(g)) {
      unsigned char g1 = g;
      if (g1 >= 32 && g1 <=126) {//checks for valid characters
	if(frequencyMap.find(g1) == frequencyMap.end()){
	  frequencyMap.insert(make_pair(g1, 1));
	}
      
      else{
	frequencyMap[g1]++;
      }
      count++;//counter for the end
      }
    }

    unordered_map<char, int>:: iterator a;
    for(a = frequencyMap.begin();a!=frequencyMap.end();a++){
      cout<< a->first<< " " << a->second<< endl;
    }




    //step 2 (Store the character frequencies in a heap (priority queue))
    unordered_map <char, int>:: iterator itr;
    for(itr = frequencyMap.begin(); itr!= frequencyMap.end(); itr++){
      hNode* node = new hNode();
      node->value = itr -> first;
      node -> frequency = itr -> second;
      h.insert(node);
    }



    //step 3 (Build a tree of prefix codes (a Huffman code) that determines the unique bit codes for each character)
    while(h.size() > 1){
      hNode* h1 = h.deleteMin();
      hNode* h2 = h.deleteMin();
      hNode* dummy = new hNode();
      dummy -> frequency = h1->frequency + h2->frequency;
      dummy -> value = '+';
      dummy ->left = h1;
      dummy ->right = h2;
      h.insert(dummy);
    }

    prefix(h.findMin(), "");

    unordered_map <char, string>:: iterator itr1;
    for(itr1 = u.begin(); itr1!= u.end(); itr1++){
      cout<<itr1->first<< " " <<  itr1->second<<endl;
    }
    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);



    //step 4 (Re-read the source file and for each character read, write its prefix code to the output, following the file format described below)
    string compressFile = "";
    int newBit = 0;
    while(file.get(g)){
      unsigned char g1 = g;
      if (g1 >= 32 && g1 <=126) {//checks for valid characters
	cout<<u[g1] + " ";
	newBit += u[g1].length();
      }
    }
    cout<<endl;
    // close the file
    file.close();

    cout << "----------------------------------------" << endl;
    cout << "There are a total of " << count<< " symbols that are encoded."<< endl;
    cout<< "There are " << u.size() << " distinct symbols used." << endl;
    cout<< "There were " << count*8 << " bits in the original file." << endl;
    cout<< "There were " << newBit<< " bits in the compressed file." << endl;
    cout<< "This gives a compression ratio of " << (float)(count*8)/newBit<< "." <<endl;
    cout<< "The cost of the Huffman tree is " << (float)(newBit)/count<< " bits per character."<< endl;
    return 0;
}

//step 3 (Build a tree of prefix codes (a Huffman code) that determines the unique bit codes for each character)
//recursively goes through the tree to determine unique bit codes for each character
void prefix(hNode* h, string s){
  if(h->left == NULL && h->right == NULL){
    u.insert(make_pair(h->value, s));
  }
  else {
  prefix(h->left, s + "0");
  prefix(h->right, s + "1");
  }
}

