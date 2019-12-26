//BASIC LIST (has next/prev)

#ifndef LINKLIST2
#define LINKLIST2

//INCLUDING THESE AS WE MIGHT NEED TO COUT SOME INFORMATION FOR PRIMITIVE DATA TYPES
#include<iostream>
using std::cout;
using std::endl;

//Struct of the node, ANYTHING MADE BY LINKLIST CAN USE THIS
//Creates a node to be stored using a template, working constructor for easy creation of nodes.
template<typename T>
struct node {
	T data;
	node<T>* next = NULL;
	node<T>* prev = NULL;
	node() {};
	node(T data)
	{
		this->data = data;
		next = NULL;
		prev = NULL;
	}; 
  
  //Accurate Visual of how linklist should be with 5 items..
  // 5<- 1 2 3 4 5 ->1
};

//A basic LinkList
template<typename T>
class LinkedList {

////PROTECTED DATA////
protected:
	//Hold the size of the linklist privately to capsulate data, can return this later
	int size;
	//The front and the end, to make circular..
	node<T>* head = NULL;
	node<T>* tail = NULL;
  
////PUBLIC METHODS AND DATA////
public:
  
  //DEFAULT CONSTRUCTOR, CREATES LIST, EVERYTHING IS NULL, NO SIZE
  LinkedList(){ 
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
  };
  
  //WORKING CONSTRUCTOR, CREATES LINKLIST WITH ONE ITEM
  LinkedList(T data){	node<T> *tmp = new node<T>(data);
    this->head = tmp;
    this->tail = this->head;
    this->size = 1;
  };
  
  //Returning the top and the end data&&||node (Incase we need it)
	T getTop() { return this->head->data; };
	T getEnd() { return this->tail->data; };
	node<T>* returnTop(){ return this->head;};
	node<T>* returnEnd(){	return this->tail;};
  
  //Push node to Linklist (ADDS TO FRONT)
  void pushNode(T data){
  //Check if null
    if (this->head == NULL) { //Only one item
      this->head = new node<T>(data);
      this->tail = this->head; //Points to itself..
      this->tail->next = this->head;
      this->head->prev = this->tail;
    }
    else { 
      //Create a node
      node<T>* tmp = new node<T>(data);
      //Say the next points to head, and the previous points to tail
      tmp->next = this->head; // 1 <- -> 2
      tmp->prev = this->tail;
      //Make sure it's circular
      this->tail->next = tmp;
      this->head->prev = tmp;
      this->head = tmp;
      //We are worrying about front, tail doesn't matter
    }
    this->size++; //Inc size of linklist
  };
  
  
  //Add to the linklist (ADDS TO END)
  void addNode(T data){
    //Check if null
    if (this->head == NULL) {
      this->head = new node<T>(data);
      this->tail = this->head; //Points to itself..
      this->tail->next = this->head;
      this->head->prev = this->tail;
    }
    else {
      //no need to traverse until we get to the end, when we have a tail
      node<T>* ptr = this->tail;
      //Create the node (can't just add to next like in singly)
      node<T>* n = new node<T>(data);
      n->next = this->head; //This will be the tail so let's point to head with next
      n->prev = this->tail; //It's prev points to the tail
      ptr->next = n; //Ptr has new next
      this->tail = n; //Change the tail to what we made
      //Make sure it's circular
      this->tail->next = this->head;
      this->head->prev = this->tail;
      //Head doesn't matter we are worrying about tail here
    }
    this->size++; //Inc size of linklist
  };
  
  
  //Insert data to the index given
  void insertNode(T data, int index){
     //No need to rewrite code
    int siz = this->size;
    //Do nothing if too far
    if (index > siz || index < 0) { }
    //If it's the end we add it on..
    else if (index == siz) { this->addNode(data);  }
    //If it's the beginning, just push it on..
    else if (index == 0) { this->pushNode(data); }
    else { //We already know at this point we are inserting at 1 or end-1..
      //Ptr to the head
      node<T>* ptr = this->head;
      //Loop the length
      for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
        //Do not go too far (USELESS WITH DOUBLE/CIRCULAR, HERE FOR LINKLIST)
        if (ptr == NULL || ptr->next == NULL) {
          return; //Don't need this here, consider this if statement ghost code..
        }
      } //Create the node (can't just add to next like in singly)
      node<T> *n = new node<T>(data);
      n->next = ptr->next; //We want our new node to point at the next item
      n->prev = ptr; //We want our new nodes prev to point at where we are at
      ptr->next = n; //Where we are points to New node now
      n->next->prev = n; //The nexts prev pointer will now point to the new node
      this->size++; //Inc size of linklist
	}};
  

  //Delete node at an index, End or front..
  //3 CASES, FRONT, MIDDLE, BACK.. 4 IF YOU COUNT TOO HIGH/LOW..
  void deleteNodeAt(int index){
    //No need to rewrite code
    int siz = this->size;
    //Do nothing if too far
    if (index >= siz || index < 0) { return; }
    //If it's the end we add it on.. pop_back basically
    else if (index == siz - 1) {
      //Reference to delete the head and move up one
      node<T>* deltmp = this->tail;
      //Move back one
      this->tail = this->tail->prev;
      //Fix pointers
      this->head->prev = this->tail;
      this->tail->next = this->head;
      delete deltmp; //Free up memory
      //We haven't subtracted the size yet, if it's 1 and we just deleted we now have 0.
      if (this->size == 1) { //Set the ptrs to NULL
        this->head = NULL;
        this->tail = NULL;
      }
    }
    //If it's the beginning do this.. pop basically
    else if (index == 0) {
      //Reference to delete the head and move up one
      node<T>* deltmp = this->head;
      //Move up one
      this->head = this->head->next;
      //Fix pointers
      this->head->prev = this->tail;
      this->tail->next = this->head;
      delete deltmp; //Free up memory
    }  //Ladder instead of early return; also this deletes inside the linklist..
    else {
      //Ptr to the head
      node<T>* ptr = this->head;
      for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
      } //Reference where to delete
      node<T>* deltmp = ptr->next;
      //Set this points next to dels next..
      ptr->next = deltmp->next;
      deltmp->next->prev = ptr;
      delete deltmp;
    } 
    //We exited early if greater, this is okay here..
    this->size--;
  };
  
  //Find the position it is at, then calls above function passing in it's index.
  void deleteNode(T data){
    //Create a pointer..
    node<T>* ptr = this->head;
    if (ptr->data == data) { this->deleteNodeAt(0);}
    else { //Loop through stuff
    int ind = 1;
    while (ptr->next->data != data) {
      ptr = ptr->next;
      ind++;
      //If we can't find it..
      if (ptr == tail && ptr->data != data) {
        return;
      } //This is prob slow, just copy and paste other method here to not loop again..
    } this->deleteNodeAt(ind);
    } 
    }; //Search for T and delete that


  //Instead of inserting let's replace..
	  void replaceNode(T data, int index){
	  //I'm just going to call what I made already..
	  //Best to make this it's function to run in O(n) and not have to run two O(n) solutions..
	    this->insertNode(data, index);
	    this->deleteNode(index + 1);
  };
  
//Does this node exist?
  bool findNode(T data){
    //Create ptr to the head
    node<T>* ptr= this->head;
    while (ptr != tail) {
      //If it matches
      if (ptr->data == data) {
        return true; //Return that data
      } ptr = ptr->next;
    } 
    return ptr->data == data;
  }; 
  
  
  //Count the linklist nodes and return the int (NOT NEEDED IF WE KEEP TRACK OF SIZE, JUST SHOWING HOW THIS WORKS)
  int countNodes(){
        if (this->head == NULL) { return 0; }
        else { //We know one thing exists
        int count = 1;
        node<T>* tmp = this->head;
        //Loop until at tail
        while (tmp != tail) {
          tmp = tmp->next;
          count++;
        }
        return count;
      }
  };
  int returnSize(){return (int)this->size; };
  

  //Reverse the linklist (FOR DOUBLYLINKLIST, BASED OFF SINGLY ALGO)
  void reverse(){
      //We must store pointers
      node<T>* current = this->head;
      node<T>* tmp = NULL;
      //Loop until current is NULL
      while (current != tail) { //1 2 3 1 2 3
        //Store the tmp pointers
        tmp = current->prev;
        //Redirect them
        current->prev = current->next;
        current->next = tmp;
        //Move up one
        current = current->prev;
      } //Once we hit the tail one more rotation
      if (current == tail) {
        //Store the tmp pointers
        tmp = current->prev;
        //Redirect them
        current->prev = current->next;
        current->next = tmp;
        //Move back one..
        current = current->prev;
      }
      this->head = current->next;
      this->tail = current;
  };
  
  //Check if list is empty
  bool isEmpty(){ return this->size == 0; };
  
  //Print the linklist contents
  void print() {
        node<T>* tmp = head;
        while (tmp != tail) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
      } std::cout << tmp->data << std::endl;
  };
};
#endif
