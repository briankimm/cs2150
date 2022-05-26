//Brian Kim, byk6q, List.cpp, 9/10/21
#include <iostream>
#include "List.h"
using namespace std;

//constructor
List::List(){
  head = new ListNode();
  tail = new ListNode();
  count = 0;
  head -> next = tail;
  tail -> previous = head;
}
// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
List::~List(){//destructor
  makeEmpty();
  delete head;
  delete tail;
}

bool List::isEmpty()const{//return statement set to true for compile purposes
  if(head -> next == tail && tail -> previous == head){
    return true;
  }
  return false;
}
void List::makeEmpty(){//removes(deletes) all items except the dummy head/tail
  ListItr itr = first();
  while(!itr.isPastEnd()){
    itr.moveForward();
    delete itr.current -> previous;
  }
  head -> next = tail;
  tail -> previous = head;
  count = 0;

}
ListItr List::first(){//returns iterator that points to first ListNode
  ListItr itr;
  itr.current = head -> next;
  return itr;
}
ListItr List::last(){//returns iterator that points to last ListNode
  ListItr itr;
  itr.current = tail -> previous;
  return itr;
}
void List::insertAfter(int x, ListItr position){
  ListNode* node = new ListNode();
  position.current -> next -> previous = node;
  node -> next = position.current -> next;
  node -> previous  = position.current;
  position.current -> next = node;
  count++;
  
}
void List::insertBefore(int x, ListItr position){
    ListNode* node = new ListNode();
    position.current -> previous -> next = node;
    node -> previous = position.current -> previous;
    node -> next = position.current;
    position.current -> previous = node;
    count++;
}
void List::insertAtTail(int x){//inserts x at the end(tail) of the list
  ListNode* node = new ListNode();
  node -> value = x;
  node -> next = tail;
  node -> previous = tail -> previous;
  tail -> previous -> next = node;
  tail -> previous = node;
  count++;
}
ListItr List::find(int x){//Returns an iterator that points to the first occurence of x
  ListItr itr = ListItr(head -> next);
  while(itr.isPastEnd() == false && itr.retrieve() != x){
    itr.moveForward();
  }
  return itr;
  }

void List::remove(int x){//removes the first occurence of x
  ListItr itr = find(x);
  if(itr.current != tail){
    itr.current -> next -> previous  = itr.current -> previous;
    itr.current -> previous -> next  = itr.current ->  next;
    delete itr.current;
    count--;
  }
}
int List::size()const{//returns the amount of elements in the list
  return count;
}
void printList(List& source, bool direction){//prints the elements of the list
  ListItr itr;
  if(direction){
    itr = source.first();
    while(!itr.isPastEnd()){
      cout << itr.retrieve() << " ";
      itr.moveForward();
    }
  }
  else{
  itr = source.last();
  while(!itr.isPastBeginning()){
    cout << itr.retrieve() << " ";
    itr.moveBackward();
  }
  }
  cout<< endl;
}
