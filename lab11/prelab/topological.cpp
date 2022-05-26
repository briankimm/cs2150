//Brian Kim, byk6q, 11.30.21, fileio2.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
/**
 *@brief Topologically sorts through CS classes at UVA
 * Creates a topological sort that creates a map of different CS classes * and links them in order
 * @return A list of CS classes sorted in order of when a student needs to take them
 * @param The first value is the a.out
 * @param The second value is the file name
 */
// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    /**
     *@brief creates two different maps to store classes and indegrees
     *@param first value is pre req
     *@param second value is "post" req
     */
    // read in two strings
    unordered_map<string, vector<string> > adjacencyList;
    unordered_map<string, int> indegreeCounter;
    string s1, s2;
    bool checker = true;
    while(checker){
      file >> s1;
      file >> s2;
      if(s1 == "0"){
        checker = false;
	break;
      }
      if(adjacencyList.find(s1) == adjacencyList.end()){
        adjacencyList[s1] = vector<string>();
      }
      if(adjacencyList.find(s2) == adjacencyList.end()){
	adjacencyList[s2] = vector<string>();
	//adjacencyList.insert(make_pair(s2, vector<string>()));
       }
      indegreeCounter[s1] = 0;
      //indegreeCounter.insert(make_pair(s1, 0));
      adjacencyList[s1].push_back(s2);
	indegreeCounter[s2]++;
    }
    /**
     *@brief adds classes with 0 indegrees onto queue
     *@if checks to see if the amount of indegrees is 0, if so, pushes onto queue
     */
    queue <string> q;
    for(auto i = indegreeCounter.begin(); i!=indegreeCounter.end();i++){
      if(i->second==0){
        q.push(i->first);
      }
    }
    /**
     *@brief sorts the classes
     *@if checks to see if indegreeCounter at that index is, if so, push onto the queue
     *@else nothing happens
     *@result returns the sorted list
     */
    while(!q.empty()){
      for(auto a = adjacencyList[q.front()].begin();a!=adjacencyList[q.front()].end();++a){
	indegreeCounter[*a]--;
	if(indegreeCounter[*a] == 0){
	  q.push(*a);
	}
      }
      cout<<q.front()<< " ";
      q.pop();
    }
    cout<<endl;
    // output those strings

    // close the file before exiting
    file.close();
}
