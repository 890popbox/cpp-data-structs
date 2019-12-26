//Binary Tree Structure (ROOT->LEFT/RIGHT)
//LITTLE DOCUMENTATION ON THIS FILE, There are many comments though

#ifndef BINARYTREE1
#define BINARYTREE1

//Some dependencies
#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <queue>
using std::queue;
using std::cout;
using std::endl;

//Struct of the node, ANYTHING MADE BY BINARYTREE CAN USE THIS
//Creates a node to be stored using a template, working constructor for easy creation of nodes.
template<typename T>
struct node {
	T data;
	node<T>* left = NULL;
	node<T>* right = NULL;
	node() { };
	node(T val) { this->data = val; };
};

//A Basic BST
template<typename T>
class BinaryTree {
protected:
	unsigned size = 0;
	node<T>* root = NULL;
private:
	//recursive methods for stuff.. on first case of null we will add it..
	void addNode(T data, node<T>*& ptr) {
		//if null (base case)
		if (ptr == NULL) {
			node<T>* tmp = new node<T>(data);
			ptr = tmp;
			size++;
		}
		//figure out which way to go..
		else if (ptr->data >= data) {
			addNode(data, ptr->left);
		}
		else if (ptr->data <= data) {
			addNode(data, ptr->right);
		}
		//let's continue if not null but same value also.. for this one
	}
	//remove stuff
	void removeNode(T data, node<T>*& ptr) {
		//base case
		if (ptr == NULL) {
			return;
		}
		//figure out which way to go..
		else if (ptr->data > data) {
			removeNode(data, ptr->left);
		}
		else if (ptr->data < data) {
			removeNode(data, ptr->right);
		}
		//if both sides are not null, we have to fix that
		else if (ptr->left != NULL && ptr->right != NULL) {
			ptr->data = this->findMin(ptr->right);
			removeNode(ptr->data, ptr->right);
		}
		else {
			node<T>* oldNode = ptr;
			//check left first than right, null is fine we just want what exists
			ptr = (ptr->left != NULL) ? ptr->left : ptr->right;
			delete oldNode; this->size--;
		}
	}
	//Find the min and return it
	T findMin(node<T>* root)
	{
		if (root->left == NULL)
			return root->data;
		else
			return findMin(root->left);
	}
	//Find the max and return it
	T findMax(node<T>* root)
	{
		if (root->right == NULL)
			return root->data;
		else
			return findMax(root->right);
	}
	//check if data exists (not sure why we would want both of these for this project?)
	bool contains(T data, node<T>*& ptr) {
		if (ptr == NULL)
			return false;
		else if (data < ptr->data)
			return contains(data, ptr->left);
		else if (data > ptr->data)
			return contains(data, ptr->right);
		else
			return true; // we have a match
	}
	//find the node and return it
	node<T>* findNode(T data, node<T>*& ptr) {
		//base case 
		if (ptr == NULL) {
			node<T>* tmp = new node<T>;
			return tmp;
		}//comparing left and right
		else if (ptr->data > data) {
			findNode(data, ptr->left);
		}
		else if (ptr->data < data) {
			findNode(data, ptr->right);
		}
		else { //found match..
			return ptr;
		}
	}
	//print for testing
	void printTree(node<T>*& ptr) {
		//base case
		if (this->root == NULL) {
			std::cout << "Empty Tree" << std::endl;
		}
		else if (ptr != NULL) {
			//print if exists
			std::cout << ptr->data << endl;
			//now go left and right
			printTree(ptr->left);
			printTree(ptr->right);
		}
	}
  
public:
	//Default constructor and working
	//Working will take in a vector of template data, and look from start to end, adding the data each time to the tree.
	BinaryTree() { this->root = NULL; };
	BinaryTree(vector<T> data) { for (T i : data) { this->addNode(i); } };
  
	//Insert the node recursively in order to position it correctly
	void addNode(T data) { this->addNode(data, this->root); };
  
	//Remove the first instance of that node (If multiple same values only first one would be deleted.
	void removeNode(T data) { this->removeNode(data, this->root); };
  
	//Check if data exists, return bool value based off that 
	bool contains(T data) { return this->contains(data, this->root); }
  
	//Searchs for the data given, and returns the node that this data is contained inside 
	node<T>* retrieveNode(T data) { this->findNode(data, this->root); };
  
	//Recursive method to get the lowest and highest value
	T findMin() { return this->findMin(this->root); };
	T findMax() { return this->findMax(this->root); };
  
	//Easier way to return the size and root of tree, incase other classes need this.
	unsigned returnSize() { return this->size; }
	node<T>* returnRoot() { return this->root; }
  
	//Printing out the tree for testing purposes
	void printTree() { this->printTree(this->root); };
};
#endif
