#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  int timeRequiredToBuyTickets(vector<int> tickets, int k) {
    int res = 0;

    for (int i = 0; i < tickets.size(); i++) {
      if (i <= k)
        res += min(tickets[i], tickets[k]);
      else
        res += min(tickets[i], tickets[k] - 1);
    }

    return res;
  }
};

int main () {
  Solution solution;

  vector<int> tickets = {2, 3, 2};
  int k = 2;

  cout << solution.timeRequiredToBuyTickets(tickets, k) << endl;

  return 0;
}