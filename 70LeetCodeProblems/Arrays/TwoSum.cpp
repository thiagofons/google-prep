#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
  vector<int> twoSum (vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      if (map.find(nums[i]) != map.end())
        return {i, map[nums[i]]};

      map[target - nums[i]] = i;
    }

    return {};
  }
};

int main () {
  Solution solution;

  vector<int> nums = {3, 3};
  int target = 6;

  vector<int> res = solution.twoSum(nums, target);

  for (int elem : res) {
    cout << elem << " ";
  }
  cout << endl;

  return 0;
}