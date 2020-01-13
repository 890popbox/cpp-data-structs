//Hash Table header-Chris(Moon)
//Basic hashing stuff, must be called as HashTable<> in main

//UPDATED 1-13 FOR GENERIC KEY:VALUE RELATIONSHIP
//Default template uses string:string, you can use whatever here but it must be static throughout the hashTable
//This is just an example to see how hashing works, ideally use HashMaps. 


//In this example a Person's NAME is the KEY, their PHONE ## is the VALUE.


#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

#ifndef HASHTABLE1
#define HASHTABLE1

//Key:value relationship, index's use small amount of bits
//The n
template<typename K = string, typename V = string>
class hashNode {
public: //Public for now to make things easy
	K key;
	V value;
	int hashInd = 0;
	unsigned occ = 0;
	//We don't have to use it, but can, makes thing very simple
	hashNode(K k = NULL, V val = NULL, int ind = 0) { this->key = k; this->value = val; this->hashInd = ind; this->occ = 1; }
};

//HashTable
template<typename K = string, typename V = string>
class HashTable {
private:
	//2d vectors for hash table, A list of list of nodes, This way if we hash to the same index, it chains on.
	vector<vector<hashNode<K,V>>> hash_table;
	//How many buckets you have to store information in, each bucket can hold many nodes 
	int tabSize = 53;

	void createTable(int size) {
		vector<hashNode<K, V>> tmp;
		//Create the ability to hold hashNodes, but not hold any yet, we must push this into the actual table for use.
		for (int i = 0; i < size; i++) {
			this->hash_table.push_back(tmp); 
		} this->tabSize = size; 
	};

	//Make it a little bigger if we wish too
	void appendTable(int addLen) {
		vector<hashNode<K, V>> tmp;
		//All this does it help it add on
		for (int i = 0; i < addLen; i++) {
			this->hash_table.push_back(tmp);
		}this->tabSize += addLen; 
	}

	//We will use a string or double for the keys, if anything else we might get an array, any other number and char will go to getHash

	int getHash(string str) { 
		int hashVal = 5381; //magic prime number..
		for (unsigned int i = 0; i < str.size(); i++)
			hashVal = 37 * hashVal + static_cast<int>(str[i]); //algorithm for strings
		int hashKey = hashVal % this->tabSize;
		if (hashKey < 0)  //just incase
			hashKey += this->tabSize;
		return hashKey;
	};

	int getHash(double val) { 
		int hashVal = 5381; //magic prime number..
		hashVal = 37 * hashVal + static_cast<int>(val); //algorithm..
		int hashKey = hashVal % this->tabSize;
		if (hashKey < 0) //just incase
			hashKey += this->tabSize;
		return hashKey;
	};

public:
	//Default and working constructors
	HashTable() { 
		this->createTable(this->tabSize);
	};
	HashTable(int tableSize) {
		this->createTable(tableSize);
	};

	//Hash a single value, this will generate it's key.
	void hash(V value) {
		int hashKey = this->getHash(value);
		hashNode<K, V> tmp(value, value, hashKey);
		//Add it to that spot first if it's empty, otherwise, go until end or match
		if (this->hash_table.at(hashKey).empty()) {
			this->hash_table.at(hashKey).push_back(tmp);
		} //Checking where it is
		else {
			short ptr = 0;
			//Loop until it's too much, or until match
			for (unsigned i = 0; i < hash_table.at(hashKey).size(); i++) {
				if (hash_table.at(hashKey).at(i).key == value) {
					ptr = i;
				}
			}
			//If there is a match, increase occ and exit
			if (this->hash_table.at(hashKey).at(ptr).key == value) {
				this->hash_table.at(hashKey).at(ptr).occ++;
			} //Add if no match
			else {
				this->hash_table.at(hashKey).push_back(tmp);
			}
		}
	};


	////hash a string.. using one string as key, one as value.
	////both will be displayed together, basically assign value to a key
	void hash(K key, V value) {
		int hashKey = this->getHash(key);
		hashNode<K,V> tmp(key, value, hashKey);
		//Add it to that spot first if it's empty, otherwise, go until end or match
		if (this->hash_table.at(hashKey).empty()) {
			this->hash_table.at(hashKey).push_back(tmp);
		} //otherwise check if it's in there
		else {
			short ptr = 0;
			//Loop until it's too much, or until match
			for (unsigned i = 0; i < hash_table.at(hashKey).size(); i++) {
				if (hash_table.at(hashKey).at(i).key == key && hash_table.at(hashKey).at(i).value == value) {
					ptr = i;
				}
			}
			//If there is a match, increase occ and exit
			if (this->hash_table.at(hashKey).at(ptr).value == value) {
				this->hash_table.at(hashKey).at(ptr).occ++;
			} //Add if no match
			else {
				this->hash_table.at(hashKey).push_back(tmp);
			}
		}
	};


	//Searchs for the key, displays key and value with it
	//Search for occurences
	int search(int value) { 
		int hashKey = this->getHash(value);
		//look if there is nothing
		if (this->hash_table.at(hashKey).empty()) {
			return 0; 
		} 
		else {
			short ptr = 0;
			//Loop until it's too much, or until match
			for (unsigned i = 0; i < hash_table.at(hashKey).size(); i++) {
				if (hash_table.at(hashKey).at(i).key == std::to_string(value)) {
					ptr = i;
				}
			}
			//If there is a match, increase occ and exit
			if (this->hash_table.at(hashKey).at(ptr).key == std::to_string(value)) {
				return this->hash_table.at(hashKey).at(ptr).occ;
			} //Add if no match
			else {
				return 0;
			}
		}
	};
	//Searchs for the key, displays key and value with it
	string search(string str) {
		int hashKey = this->getHash(str);
		//look if there is nothing
		if (this->hash_table.at(hashKey).empty()) {
			return "The person's name was not found.";
		}
		else {
			vector<int> ptr;
			//Loop until it's too much, or until match
			for (unsigned i = 0; i < hash_table.at(hashKey).size(); i++) {
				if (hash_table.at(hashKey).at(i).key == str) {
					ptr.push_back(i); //collect all the spots this key is saved at
				}
			}
			//If our vector contains anything use it
			if (!ptr.empty()) {
				string ret = "";
				for (unsigned i = 0; i < ptr.size(); i++) {
					//pos
					int pos = ptr.at(i);
					//organizing
					string key1 = hash_table.at(hashKey).at(pos).key;
					string val1 = hash_table.at(hashKey).at(pos).value;
					string ocr1 = std::to_string(hash_table.at(hashKey).at(pos).occ);
					string tmp = key1 + "(" + std::to_string(hashKey) + "-" + std::to_string(pos) + ") : " + val1 + " : occ value(" + ocr1 + ")";
					if (i < ptr.size() - 1) {
						tmp += "\n";
					}
					ret += tmp;
				}
				return ret;
			} //Add if no match
			else {
				return "The person's name was not found.";
			}
		}
	};

	////To test display
	void printTable() {
		//Loop hash table
		for (unsigned i = 0; i < hash_table.size(); i++) {
			for (unsigned j = 0; j < hash_table.at(i).size(); j++) {
				cout << hash_table.at(i).at(j).key << "(" << std::to_string(hash_table.at(i).at(j).hashInd) << "-" << j << ") : " << hash_table.at(i).at(j).value << endl;
			}
		}
	};
};

#endif
