//Simple way to find if a word exists in a given String.

#include <iostream> 
#include <string>
using std::string;
using std::cout;
using std::endl;

bool findWord(string word, string str) {
	//loop the whole string
	for (unsigned int i = 0; i < str.size(); i++) {
		//use first letter in word
		if (word[0] == str[i]) {
			//loop just that word cause we know there might be a match
			for (unsigned int j = 1, g = i+1; j < word.size(); j++, g++) {
				if (g >= str.size()) {
					break;
				} else if (word[j] != str[g]) {
					break;
				} else if (j>=word.size()-1) { return true; }
			} 
		}
	} //return if it was found or not
	return false;
}

int main()
{ 
	string str = "Hello world, chris was here";
	cout << (findWord("was",str) ? "Yes" : "No") << endl;
	cout << (findWord("Hey",str) ? "Yes" : "No") << endl;
  return 0;
}

//This returns a bool value but you can easily change it to return the index as an int.
