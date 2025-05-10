#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
		int profit = 0;

		for (int i = 1; i < prices.size(); i++) {
			// Get the lowest price
			int price = prices[i];
			
			if (price < buy_price) {
				buy_price = price;
			}
			
			// Check if the profit gets higher
			profit = max(profit, price - buy_price);
		}

		return profit;
    }
};

int main() {
	Solution solution;
	vector<int> prices = {7,1,5,3,6,4};

	int maxProfit = solution.maxProfit(prices);

	cout << maxProfit << endl;
	
	return 0;
}