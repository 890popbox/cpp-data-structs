//Basic Queue Class (FIFO)
//FIRST IN FIRSTT OUT

#ifndef QUEUE1
#define QUEUE1

//I WILL USE MY LINKLIST HEADER
//You are able to use your linklist, vector.. or the library <vector> might be the easiest way to do this
//I want to be able to print also so using cout for testing
#include "linklist2.h"
#include<iostream>
using std::cout;
using std::endl;

//I will not be using inheritance as it is gross
template<typename T>
class Queue {
//Using the linklist to store all the data we will give it
////PRIVATE DATA////
private:
	LinkedList<T> container;
  
////PUBLIC METHODS////
public:

  //WILL HAVE TO CREATE THIS CLASS, CONTAINER SHOULD ALREADY BE CREATED.
  Queue(){ };
	
  //THIS METHOD WILL PUSH YOUR DATA TO THE FRONT OF THE QUEUE
	void enqueue(T data){ this->container->addNode(data); };
  
  //DELETES DATA FROM THE FRONT OF THE QUEUE
	void dequeue(){
        if (this->container->isEmpty()) {
        cout << "Can't dequeue an empty queue" << endl;
      }
      else { //Delete front always
        this->container->deleteNodeAt(0);
      }
  };
  
  //RETURNS THE DATA FROM THE FRONT OF THE QUEUE
	T peek(){
      if (this->container->isEmpty()) {
      cout << "Can't peek an empty queue" << endl;
      return T();
    } else { 
      return this->container->returnTop()->data;
    }
  };
};

#endif
