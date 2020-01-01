//Short way to check if a string is a Palindrome

#include <iostream> 
#include <string>
using std::string;
using std::cout;
using std::endl;

bool checkPalindrome(string str){
	for (unsigned i = 0, j = unsigned(str.size() - 1); i < unsigned(str.size() / 2); i++, j--) {
		//check if space from both i and j, we don't want spacing.
		while (str.at(i) == ' ') { i++; }
		while (str.at(j) == ' ') { j--; }
		//check if it's equal or not, cap/low diff doesn't matter
		if (tolower(str.at(i)) != tolower(str.at(j))) { return false; }
    return true;
}

int main()
{ 
  cout << checkPalindrome("Hello") << endl; //0
  cout << checkPalindrome("rac  eca  r") << endl; //1
  return 0;
}
