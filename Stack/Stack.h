//Basic Stack Class (LIFO)
//LAST IN FIRST OUT

#ifndef STACKY1
#define STACKY1

//I WILL USE MY LINKLIST HEADER
//You are able to use your linklist, vector.. or the library <vector> might be the easiest way to do this
//I want to be able to print also so using cout for testing
#include "linklist2.h"
#include<iostream>
using std::cout;
using std::endl;

//I will not be using inheritance as it is gross
template<typename T>
class Stack {
//Using the linklist to store all the data we will give it
////PRIVATE DATA////
private:
	LinkedList<T> container;
  
////PUBLIC METHODS////
public:

  //THIS METHOD WILL PUSH YOUR DATA TO THE TOP OF THE STACK
	void push(T data){ this->container->addNode(data); };
  
  //DELETES AND RETURNS THE DATA FROM THE TOP OF THE STACK
	T pop(){	
    //Save a tmp and delete it, return that
    if (this->container->isEmpty()) {
      cout << "Can't pop an empty Stack" << endl;
      return T();
    }
    else {
      T tmp = this->container->returnEnd()->data;
      this->container->deleteNodeAt(this->size - 1);
      return tmp;
	}};
  
  //RETURNS THE DATA FROM THE TOP OF THE STACK
	T peek(){
        if (this->container->isEmpty()) {
        cout << "Can't peek an empty Stack" << endl;
        return T();
      }
      else {
        return this->container->returnEnd()->data;
      }
  };
};

#endif
