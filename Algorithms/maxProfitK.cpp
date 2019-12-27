//Popular problem, one of the most annoying one's for me to visualize

#include <iostream> 
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

int maxProfit(int price[], int n, int k)
{
	//Creating a table instantly with vector properties, cpp doesn't like non const arrays (Moon)
	vector<vector<int>> profit(k+1, vector<int>(n, 0));

	//Fill the table in bottom up fashion, credit to (geeks4geeks)
	for (int t = 1; t < k+1; t++) {
		int prevDiff = INT_MIN;
		for (int d = 1; d < n; d++) {
			prevDiff = std::max(prevDiff,
				profit[t - 1][d - 1] - price[d - 1]);
			profit[t][d] = std::max(profit[t][d - 1],
				price[d] + prevDiff);
		}
	}
	return profit[k][n - 1];
}

int main()
{ 
	int k = 3;
	int price[] = { 12, 14, 17, 10, 14, 13, 12, 15 };
  
	int n = sizeof(price) / sizeof(price[0]);
  
	cout << "Maximum profit is: " << maxProfit(price, n, k) << endl;
  return 0;
}

//The table is very important, first row is all 0 because there are no transactions
//The transactions afterwards have to deal with the one's before
//All of [0][c] should be 0 and all of [r][0] should be 0 as well.
