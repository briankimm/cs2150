//Brian Kim, byk6q, 11.30.21, traveling.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);
/**
 *@author Brian Kim
 *@brief main method, tracks the shortest distance
 *@return prints out the distance, and prints the route of the shortest distance
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    string s = dests[0];
    dests.erase(dests.begin());
    //printRoute(s, dests);
    //cout<<computeDistance(me, s, dests)<<endl;;
    sort(dests.begin(), dests.end());
    //float f = computeDistance(me, s, dests);
    vector<string> v = dests;
        float f = computeDistance(me, s, v);
	do{
      if(f>computeDistance(me, s, dests)){
	f = computeDistance(me, s, dests);
	v = dests;
      }
      }while(next_permutation(dests.begin(), dests.end()));

    cout<<"Minimum path has distance "<< f << ": ";
    printRoute(s, v);
    
    return 0;
}/**
  *@author Brian Kim
  *@brief computes the full distance of the vector
  *@return the total of the distance of the trip
  */

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float distance = me.getDistance(start, dests[0]);
  for(int a = 1;a<dests.size();a++){
    distance+=me.getDistance(dests[a-1],dests[a]);
  }
  distance+=me.getDistance(dests[dests.size()-1],start);
return distance;
}
/**
 *@author Brian Kim
 *@brief print out the entire route, starting and ending at the 'start' parameter
 *@return city + "->" 
 */
// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  cout<< start<< " -> ";
  for(int a = 0; a<dests.size();a++){
    cout<< dests[a]<< " -> ";
  }
  cout<<start<<endl;
}
