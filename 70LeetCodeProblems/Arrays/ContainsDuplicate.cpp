#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int size = nums.size();
    
    unordered_set<int> set;

    for (int i = 0; i < size; i++) {
      int value = nums[i];

      if (set.count(value) > 0)
        return true;

      set.insert(value);
    }
    return false;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {1, 2, 3, 4};

  bool res = solution.containsDuplicate(nums);

  cout << (res ? "true" : "false") << endl;

  return 0;
}