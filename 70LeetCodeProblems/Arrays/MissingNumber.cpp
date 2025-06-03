#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
  int missingNumber (vector<int>& nums) {
    // Sort the array
    sort(nums.begin(), nums.end());
    
    // Check if the index equal the value
    int i = 0;
    for (; i < nums.size(); i++) {
      if (nums[i] != i)
        return i;
    }

    return i;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {0, 1};

  cout << solution.missingNumber(nums) << endl;

  return 0;
}