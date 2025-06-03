#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public: 
  int maxProfit (vector<int>& prices) {
    int maxProfit = 0;

    int left = 0, right = 1;
    while (right < prices.size()) {
      if (prices[left] < prices[right]) {
        int profit = prices[right] - prices[left];

        maxProfit = max(maxProfit, profit);
      }
      else {
        left = right;
      }
      right++;
    }

    return maxProfit;
  }
};

int main () {
  Solution solution;

  vector<int> prices = {7, 1, 5, 3, 6, 4};

  cout << solution.maxProfit(prices) << endl;

  return 0;
}