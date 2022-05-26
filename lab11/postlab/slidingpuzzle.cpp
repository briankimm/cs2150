//Brian Kim, byk6q, slidingpuzzle.cpp, 12.3.21
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include "hashTable.h"


using namespace std;


//helper methods
vector<string> generateNeighbors(string s);
vector<int> swapIndexes(string s, int i);



//helper class
class tile{
 public:
  tile();
  tile(string s, int i);
  int getSteps();
  string getPermutation();
  string permutation;
  int steps;
};

tile::tile(){
  
}
tile::tile(string s, int i){
  permutation = s;
  steps = i;
}
int tile::getSteps(){
  return steps;
}
string tile::getPermutation(){
  return permutation;
}



//main method
/**
 *@brief this program calculates the least number of steps it takes to solve a sliding 8-puzzle
 *@note this program uses hashTable data structure made from lab 6
 *@result returns the least amount of steps it takes to solve a sliding 8-puzzle
 *@author Brian Kim
 *@copyright 12.3.21
 *@pre unsolved puzzle
 *@post solved puzzle
 */
int main(){
  string a, b, c;
  string puzzle;
  cout<< "Enter Puzzle"<<endl;
  getline(cin, a);
  getline(cin, b);
  getline(cin, c);
  puzzle = a + b + c;
  puzzle.erase(remove(puzzle.begin(), puzzle.end(), ' '), puzzle.end());//stack overflow
  int numOfInversions = 0;
   for(int i = 0;i<8;i++){
    for(int j = i+1;j<9;j++){
      if(puzzle[i] > puzzle[j] && puzzle[i] !='0' && puzzle[j] != '0'){
	numOfInversions++;
      }
    }
   }
  
  cout<<"Solving puzzle"<<endl;
  if(numOfInversions % 2  == 1){
    cout<< "IMPOSSIBLE"<<endl;
    return 0;
  }

  
  hashTable h = hashTable();
  bool check = false;
  queue<tile>q;

  tile t;
  t = tile(puzzle, 0);
  

  h.insert(puzzle);
  q.push(t);
  //cout<<puzzle<<endl;
  while(!(check)){
    tile t2 = q.front();
    q.pop();
    vector<string>v = generateNeighbors(t2.getPermutation());
    /*for(auto a = v.begin(); a!= v.end();a++){
      cout<<*a<<endl;
      }*/
    if(t2.getPermutation() == "123456780"){
      check = true;
      cout<<t2.getSteps()<<endl;
      return 0;
    }
    for(int i = 0;i<v.size();i++){
      tile t1;
      string str = v[i];
      if(!(h.contains(str))){
	t1 = tile(str, t2.getSteps() + 1);
	h.insert(str);
	q.push(t1);
	
      }
      else{
	continue;
      }
    }
  }
  for(int i = 0;i<q.size();i++){
    q.pop();
  }
  return 0;
}


/**
 *@brief stores the different combinations of where the 0 can go 
 *Based on where the 0 or the space is in the 3x3 grid, there are different places the 0 or space can go after a step.  This method stores which ones are which and returns the possibilities.  
 *@param string of the pattern
 *@param int to indicate where the 0 or space is on the 3x3 grid
 *@return returns a vector of ints of where the 0 or space can go.  
 */
vector<int> swapIndexes(string s, int i){
  vector<int> v;
  if(i == 0){
    v.push_back(1);
    v.push_back(3);
  }
  else if(i == 1){
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
  }
  else if(i == 2){
    v.push_back(1);
    v.push_back(5);
  }
  else if(i == 3){
    v.push_back(0);
    v.push_back(4);
  }
  else if(i == 4){
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
  }
  else if(i == 5){
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);
  }
  else if(i == 6){
    v.push_back(4);
    v.push_back(7);
  }
  else if(i == 7){
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
  }
  else if(i == 8){
    v.push_back(5);
    v.push_back(7);
  }
  return v;
}
/**
 *@brief generates the modified vector of strings based on swapIndexes
 *This method takes the different places the 0 or space could go, and returns the different strings after they have been modified
 *@param string of original pattern
 *@return vector of modified strings based on where the 0 can go
 */
vector<string> generateNeighbors(string s){
  vector<string>v;
  vector<int> index;
  int zro = s.find("0");
  index = swapIndexes(s, zro);
  for(int i = 0;i<index.size();i++){
    string old = s;
    int tempIndex= index.at(i);
    int tempVal = old[zro];
    old[zro] = old[tempIndex];
    old[tempIndex] = tempVal;
    v.push_back(old);
  }
  return v;
}
