#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map>
using std::unordered_map;
using std::vector;
using std::string;
using std::cout; 
using std::endl;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	//prime numbers important
	long primeNumber[26]{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };
		//hold answers to be returned later, reverse the size
		std::vector<std::vector<std::string>> container;
		container.reserve(strs.size());
		//map number to string of vectors
		std::unordered_map<unsigned long, std::vector<string>*> dict;
		//this will keep track of what word we are on
		unsigned long hashValue = 1;
		//loop through every string
		for (int i = 0; i < strs.size(); ++i)
		{   //reset to one each loop
			hashValue = 1;
			//go through how big that string is, create a value..
			for (int j = 0; j < strs[i].size(); ++j)
			{
				hashValue = hashValue * primeNumber[(strs[i][j] - 'a')];
			}
			//if that value exists, add it there (easy push)
			if (dict.find(hashValue) != dict.end())
			{
				dict[hashValue]->push_back(strs[i]);
			}
			else
			{ //because that value does not exist, add it to another map
				container.push_back({ strs[i] }); //first push that that string as a dict
				dict[hashValue] = &container[(container.size() - 1)]; //ref it to dict, as its a ptr
			}
		}
		return container;
}

int main()
{//test strings
	vector<string> strings = { "eat","tea","tan","ate","nat","bat" };
	vector<vector<string>> ddStrings = groupAnagrams(strings);
	//test print
	for (vector<string> abc : ddStrings) {
		for (string aaa : abc) {
			cout << aaa << " ";
		} cout << endl;
	}
	return 0;
}
