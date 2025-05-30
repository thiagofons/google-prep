#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int start = 0, end = nums.size() - 1, middle = (start + end) / 2;

    // Find the cut
    while (middle != end) {
      if (nums[middle] < nums[middle - 1]) 
        break;   
        
      start = middle;
      middle = (start + end) / 2;
    }

    return nums[middle];
  }
};

int main () {
  Solution solution;

  vector<int> nums = {4,5,6,7};

  cout << solution.findMin(nums) << endl;

  return 0;
}