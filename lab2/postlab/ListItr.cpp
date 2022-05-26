//Brian Kim, byk6q, ListItr.cpp, 9/10/21
#include <iostream>
#include "ListItr.h"
using namespace std;

ListItr::ListItr(){//constructor
  current = NULL;
}
ListItr::ListItr(ListNode* theNode){//constructor that sets ListNode pointer to current iterator
  current = theNode;
}
bool ListItr::isPastEnd()const{//boolean to check if iterator is pointing past the end of the list
  if(current -> next == NULL){
    return true;
  }
  return false;
}
bool ListItr::isPastBeginning()const{//boolean to check if the iterator is pointing before the first position
  if(current -> previous == NULL){
    return true;
  }
  return false;
}
void ListItr::moveForward(){//moves the current iterator to the next element in the list
  if(!isPastEnd()){
    current = current->next;
  }
}
void ListItr::moveBackward(){//moves the current iterator to the previosu element in the list
  if(!isPastBeginning()){
    current = current->previous;
  }
}
int ListItr::retrieve()const{//returns the value of the item of the current position of the list
  return current->value;
}
