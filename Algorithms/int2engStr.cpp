//CONVERTS A GIVEN INT INTO A STRING OF ENGLISH WORDS (RECURSIVE FUNCTION)
//325 -> Three Hundred Twenty Five
//NEGATIVE AND ZERO SUPPORTED WITH THE USE OF A PRIVATE/PUBLIC FUNCTION

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

//PRIVATE FUNCTION TO CONVERT INT TO ENGLISH STRING

string int2eng(long num) {
	//Hold one to twenty as they are all different than when above 20
	vector<string> _under20 = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve",
				"Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
	//Everything 20 to 100, and above is easy to do recursively
	vector<string> _over20 = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

	//if else recurs ladder
	if (num < 10) {
		return _under20[num];
	}
	else if (num < 20) {
		return _under20[num];
	}
	else if (num < 100) {
		return _over20[num / 10] + ((num % 10 != 0) ? " " + int2eng(num % 10) : "");
	}
	else if (num < 1000) {
		return int2eng(num / 100) + " Hundred" + ((num % 100 != 0) ? " " + int2eng(num % 100) : "");
	}
	else if (num < 1000000) {
		return int2eng(num / 1000) + " Thousand" + ((num % 1000 != 0) ? " " + int2eng(num % 1000) : "");
	}
	else if (num < 1000000000) {
		return int2eng(num / 1000000) + " Million" + ((num % 1000000 != 0) ? " " + int2eng(num % 1000000) : "");
	}
	else if (num < 1000000000000) {
		return int2eng(num / 1000000000) + " Billion" + ((num % 1000000000 != 0) ? " " + int2eng(num % 1000000000) : "");
	} //Must work with different data types to get really high numbers working
	else if (num < 1000000000000000) {
		return int2eng(num / 1000000000000000) + " Trillion" + ((num % 1000000000000000 != 0) ? " " + int2eng(num % 1000000000000000) : "");
	}
	return "error, maybe invalid number";
}

//PUBLIC FUNCTION MEANT TO CALL THE PRIVATE FUNCTION
//Getting the zero and negative numbers
string int2EngPublic(long num) {
	//checking 3 cases
	if (num == 0) {
		return "Zero ";
	}
	else if (num < 0) {
		return "Negative " + int2eng(num*-1);
	}
	else {
		return int2eng(num);
	}
}

int main()
{ 
	string str = int2EngPublic(-1337); 
	std::cout << str << std::endl;
	//Negative One Thousand Three Hundred Thirty Seven
	return 0;
 }
