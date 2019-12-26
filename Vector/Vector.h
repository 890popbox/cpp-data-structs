//THIS FILE IS NOT MEANT TO REPLACE <vector> BUT TO STUDY ITS STRUCTURE AND CREATE A SIMPLE VERISON OF IT

//Recreating the vector, can define with whatever name..
//Print functions might not work accurately, can change it up
#ifndef MOONVEC1
#define MOONVEC1

//INCLUDING THESE JUST TO BE ABLE TO PRINT SOME STATS
#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

//USING TEMPLATES/GENERIC DATA (SAME AS ORIGINAL VECTOR)
//BECAUSE THIS IS A HEADER WITH TEMPLATES WE ONLY NEED THIS FILE

template<typename T>
class moonVec {

//A pointer to template/generic data in order to create an array
//vec_capacity - The amount of items the vector is currently able to hold
//vec_size  - The amount of items currently in the vector
//Both of these will change but capacity is the space this class will be taking up

private:
	T *ptr;
	int vec_capacity = 5;
	int vec_size = 0;

////PRIVATE METHODS////

//This void function takes input given in order to create your vector with the size given, defaults at 5

	void createVec(int siz) {
		this->ptr = new T[siz];
		this->vec_capacity = siz;
	};

//This function fills the vector with the same data.. 
//vector<int> myList(3,5); Will create 3 spots in vector with the int=5 (Just like <vector>)

	void fillVec(T val) {
		for (int i = vec_size; i < this->vec_capacity; i++) {
			this->ptr[vec_size++] = val;
		}
	};


//PRIVATE METHOD IN ORDER TO CREATE A DEEP CLONE
//VERY IMPORTANT TO AVOID SHALLOW CLONING
//BECAUSE THE PRIVATE DATA IS A POINTER IF YOU JUST COPY IT OVER YOU WILL COPY THE POINTER
//THIS FUNCTION IS CREATED IN ORDER TO AVOID THIS
	void deepClone(moonVec const &copy) {
		vec_capacity = copy.vec_capacity;
		vec_size = 0;
		ptr = new T[vec_capacity];
		try {
			for (int i = 0; i < copy.vec_capacity; i++) {
				push_back(copy.ptr[i]);
			}
		} //if we catch any errors, delete the whole vector and throw the exception
		catch (...) {
			this->~moonVec();
			throw;
		}
	};

////PUBLIC METHODS////

public:

//PUBLIC DESTRUCTOR TO MAKE SURE WE DELETE THE VECTOR WHEN NEEDED
	~moonVec() {
		for (int i = vec_capacity-1; i >= 0; i--) {
			ptr[i].~T();
		}
	};
  
//PUBLIC COPY CONSTRUCTOR FOR DEEP CLONING, CALLS THE PRIVATE METHOD
	moonVec(moonVec const &copy) {
		this->deepClone(copy);
	}

//ANOTHER PUBLIC COPY CONSTRUCTOR FOR DEEP CLONING, CALLS THE PRIVATE METHOD, override equals operator
//O(N) For these actions
	moonVec & operator=(moonVec &rhs) {
		this->deepClone(rhs);
		return *this;
	};

	
//SIMPLE DEFAULT CONSTRUCTORS AND WORKING CONSTRUCTORS THAT CALL THE PRIVATE METHODS
	moonVec() { this->createVec(this->vec_capacity); };
	moonVec(int siz) { this->createVec(siz); };
	moonVec(int siz, T val) { this->createVec(siz); this->fillVec(val); };
  
  
//PUSHING AN ITEM TO THE VECTOR, INCREASING SIZE IF NEEDED
//AMORTIZED O(1), WORSE CASE O(N) DUE TO REMAKING VECTOR IF CAPACITY IF PASSED

	void push_back(T val) { 
		//if we go to high to must make the array bigger
		if (vec_size >= vec_capacity) {
			T* tmp = new T[this->vec_capacity * 2];
		for (int i = 0; i < this->vec_capacity; i++) {
			tmp[i] = ptr[i];
		} //set the pointer now equal to the tmp array
		this->ptr = tmp;
		this->vec_capacity *= 2; //set size or it will reach this condition again
		} 
		//run this regardless, set the data and increase where to put it
		ptr[vec_size++] = val;
	};

//KIND OF PSEUDO REMOVAL, CAN ALSO JUST NOT REPLACE IT..
//LEAVE IT THERE AND NOT BE ABLE TO ACCESS IT UNTIL MEMORY IS CHANGED (MANY WAYS TO HANDLE THIS, YOU DECIDE)
//O(1) pseudo removal.. write/read

	T pop_back() { 
		T tmp = ptr[--vec_size];
		ptr[vec_size]=T();
		return tmp;
	};

//SWAP TWO ELEMENTS IN THE VECTOR GIVING THEIR INDEXES O(1)

	void swap(int ind1, int ind2) {
		T tmp = ptr[ind1];
		ptr[ind1] = ptr[ind2];
		ptr[ind2] = tmp;
	}
 
//REFERENCE TO INDEX WE ARE USING O(1)
//myVector.at(0), myVector[0]; SHOULD WORK THE SAME WAY.

	T& at(int pos) {
		//return blank check
		if (pos >= this->vec_capacity || pos < 0) {
			T* empty = new T[1];
			return empty[0]; //this should throw error instead, don't hit it anyway pls
		}
		else { return ptr[pos]; }
	};
	T& operator[] (int pos) { return this->at(pos); };


//vec_capacity - The amount of items the vector is currently able to hold
//vec_size  - The amount of items currently in the vector
//TWO FUNCTIONS TO RETURN THESE DIFFERENCES

	int capacity() { return this->vec_capacity; };
	int size() { return this->vec_size; };

//PRINTING OUT ALL OF THE VECTOR (TEST FUNCTION/NOT USUALLY USED)
//Trying to format this similiar to pyth simple print, can remake this.. O(N)

	void print() {
		int last_ind = this->vec_size-1;
		if (last_ind < 0) { cout << "[]" << endl; return; }
		cout << "[";
		for (int i = 0; i < last_ind; i++) {
			cout << ptr[i] << ", ";
		}  cout << ptr[last_ind];
		cout << "]" << endl;
	};

//PRINTING OUT ALL OF THE VECTOR BUT FOR LISTS (IF ITS 2D ARRAY/VECTOR) (TEST METHOD/NOT USUALLY USED)

	void printList() {
		for (int i = 0; i < this->vec_size; i++) {
			cout << ptr[i] << "\n";
		} 
	};

//ANOTHER DEBUG METHOD, TO SEE HOW THE STATS AND MEMORY STORAGE IS WORKING

	void stats() {
		std::cout << "Moon vector capacity : " << vec_capacity << endl;
		std::cout << "Moon vector capacity : " << (sizeof(ptr[0])*vec_capacity) << " bytes, " << ((sizeof(ptr[0])*vec_capacity) * 8) << " bits" << endl;
		std::cout << "Moon vector size contains : " << vec_size << " items." << endl;
		std::cout << "Moon vector size contains : " << (sizeof(ptr[0])*vec_size) << " bytes, " << ((sizeof(ptr[0])*vec_size) * 8) << " bits" << endl;

	}

//OVERLOADING THE INSERTION OPERATOR, Just incase we want to print this way

	friend ostream& operator << (ostream& output, moonVec& ar) { 
		//get what is in that object, just some formatting code
		int last_ind = ar.size() - 1;
		output << "[";
		for (int i = 0; i < last_ind; i++) {
			output << ar[i] << " , ";
		} output << ar[last_ind] << "]";
		return output;
	};
};
#endif
