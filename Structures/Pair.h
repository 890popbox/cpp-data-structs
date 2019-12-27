//BASIC PAIR CLASS, CAN BE USED FOR KEY/VALUE IDEAS
//WANT MORE VALUES? ADD THEM, SET DEFAULT VALUES, ETC..

#ifndef PAIR1
#define PAIR1

#include <iostream>
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

//They have to be friends with template (could also just use a different type when in the class)  <U> or something.
template <typename T> class Pair;
template <typename T> istream& operator >> (istream& input, Pair<T>& p);

template <typename T> class Pair;
template <typename T> ostream& operator << (ostream& output, Pair<T>& p);


//THIS PAIR WILL USE TEMPLATES/GENERICS
template<typename T>
class Pair
{

////PRIVATE DATA////
private:
	T a_;
	T b_;
  
////PUBLIC METHODS////
public:

//DEFAULT AND WORKING CONSTRUCTOR TO CREATE THE CLASS AND PASS IN VALUES
	Pair(){};
	Pair(T f, T s){this->setFirst(f); this->setSecond(s);};
  
  
//MUTATORS TO SET THE VALUES OF THE PRIVATE DATA
	void setFirst(T f){this->a_ = f;};
	void setSecond(T s){this->b_ = s;};
  
//RETURN THE PRIVATE DATA YOU WANT
	T getFirst() const{return this->a_;};
	T getSecond() const{return this->b_;};
  
  
//Operator overriding
//THIS WILL ALLOW US TO COMPARE THIS VALUE WITH OTHER SIMILIAR OBJECTS AS IF IT WERE A PRIMITIVE
// a=5; b=3; if(a==b) etc.. You can do this with a pair object if you create these bool methods below
	bool operator==(const Pair<T> &data) const{return (first == data.first && second == data.second);};
	bool operator!=(const Pair<T> &data) const{return !(*this == data);};
  
  
//Operator Overloading
//THIS ALLOWS YOU TO USE THE EXTRACTION OPERATOR THE SAME WAY YOU WOULD WITH AN INT OR STRING
	friend istream &operator >> <T>(istream& input, Pair& p){
     cout << "Please enter the first item for your Pair" << endl;
    input >> p.first;
    cout << "Please enter the second item for your Pair" << endl;
    input >> p.second;
    return input;
  };

//THIS ALLOWS YOU TO USE THE INSERTION OPERATOR THE SAME WAY YOU WOULD WITH AN INT OR STRING
	friend ostream &operator << <T>(ostream& output, Pair& p){
      output << p.getFirst() << "," << p.getSecond() << " ";
    return output;
  }; 
};
#endif
