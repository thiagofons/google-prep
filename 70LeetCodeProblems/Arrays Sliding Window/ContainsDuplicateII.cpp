#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];

      if(seen.count(num) > 0) 
        return true;

      seen.insert(num);

      if (seen.size() > k)
        seen.erase(nums[i - k]);
    }
    return false;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {1, 2, 3, 1};
  int k = 3;

  bool res = solution.containsNearbyDuplicate(nums, k);

  cout << (res ? "true" : "false") << endl;

  return 0;
}