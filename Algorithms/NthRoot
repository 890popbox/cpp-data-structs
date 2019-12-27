//A solution to find the NthRoot..
//NthRoot(144,2) -> 12;

#include <iostream> 
#include <string>
using std::string;
using std::cout;
using std::endl;

//LONG DOUBLE
typedef long double ld;

ld NthRootPrivate(ld n, int nth_) {
	//create some kind of range for binary search
	ld start = 0, end = n;
	//check if negative, originally assume positive
	bool negativeCheck = false;
	if (nth_ < 0) { negativeCheck = true; }
	//set precision, 6 decimals more than fine for most cases, this is long double too.
	ld e = (ld)0.000001;
	//loop until answer is found
	while (true) {
		ld middle = (start + end) / 2;
		//see where we are at times itself n times, save to tmp
		ld tmp = 1;
		if (nth_ > 2) {
			for (int i = 0; i < nth_; i++) {
				tmp *= middle;
			}
		}
		else { tmp = middle * middle; }
		//error checking, we want this 0 or equal to precision
		ld error = std::abs(tmp - n);
		//we found the answer
		if (error <= e) {
			return middle;
		}
		//if our result is greater than our number, set the end (has to be lower)
		if (tmp > n) {
			end = middle;
		} //otherwise make it less.
		else {
			start = middle;
		}
	}
}

//3 CASES, OVER 0, UNDER 0, EQUAL TO 0..
ld NthRoot(ld n, int nth_) {
	if (nth_ > 0) { return NthRootPrivate(n, nth_); }
	else if (nth_ < 0) { return 1/NthRootPrivate(n, std::abs(nth_)); }
	else { return 1; }
}

int main()
{ 
	cout << std::sqrt(146166451536112562) << endl;
	cout << NthRoot((ld)146166451536112562, 2) << endl;
  //12, 1, 0.083
	cout << NthRoot((ld)144, 2) << endl;
	cout << NthRoot((ld)144, 0) << endl;
	cout << NthRoot((ld)144, -2) << endl;
  return 0;
}
