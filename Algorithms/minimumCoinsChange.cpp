//The minimum number of coins we would need if returning change in cents

#include <iostream> 
#include <string>
using std::string;
using std::cout;
using std::endl;

int min_coins(int cents) {
	if (cents < 1) { return 0; }
	//The coins we will be using
	int coins[4] = { 25, 10, 5, 1 };
	//We will get less than our number anyway
	int minCoins = cents;
	int tmpCents = cents;
	int num_of_coins = 0;
	//How many diff coins we will be using
	int coinTypes = sizeof(coins) / sizeof(coins[0]);
	//Loop through it all until we use 0
	for (int i = 0, j = 0; i < coinTypes; i++) {
		num_of_coins += tmpCents / coins[i];
		tmpCents = tmpCents % coins[i];
		//End early if 0
		if (tmpCents == 0) {
			//Always replace with the lowest
			if (num_of_coins < minCoins) {
				minCoins = num_of_coins;
			}
			//J is where we are at
			j++;
			i = j;
			//Reset coin count, and look up again.
			num_of_coins = 0;
			tmpCents = cents;
		}
	}  //Return the lowest value we get
	return minCoins;
}

int main()
{ 
	//Testing coin algorithm
	cout << min_coins(22) << endl;
	cout << min_coins(11) << endl;
	cout << min_coins(57) << endl;
  return 0;
}
