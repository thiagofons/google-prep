#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
  int minSubarrayLength(int target, vector<int>& nums) {
    int length = INT_MAX, left = 0, total = 0;
    
    for (int right = 0; right < nums.size(); right++) {
      total += nums[right];

      while (total >= target) {
        length = min(length, right - left + 1);

        total -= nums[left];
        left++;
      }
    }

    if (length == INT_MAX) 
      return 0;

    return length;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;

  cout << solution.minSubarrayLength(target, nums) << endl;

  return 0;
}