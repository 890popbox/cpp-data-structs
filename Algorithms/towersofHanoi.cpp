//The minimum number of moves for the towers of hanoi problem.
//This will display the moves to take as well
//Technically A can end up at B or C, but we want it to move from A to C..
//2^n − 1

#include <iostream> 
#include <string>
using std::string;
using std::cout;
using std::endl;

//hanoi recurs.. DEFAULT VALUES INCASE YOU DON'T WANT TO INPUT THAT IN MAIN
void hanoi(int n, char f='A', char h='B', char t='C') {
	//base case
	if (n == 0) {
		return;
	} else {
		hanoi(n - 1, f, t, h);
		cout << f << " to " << t << endl;
		hanoi(n - 1, h, f, t);
	}
}


int main()
{ 
	cout << "hanoi test1-recurs" << endl;
	hanoi(3);
  return 0;
}
