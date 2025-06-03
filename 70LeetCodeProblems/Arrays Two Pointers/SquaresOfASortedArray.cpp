#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public: 
  vector<int> sortedSquares(vector<int>& nums) {
    int j = 0, size = nums.size();

    if (size == 0) return;

    // j = position of first non-negative
    while (nums[j] < 0) {
      j++;
    }

    // i = position of first negative
    int i = j - 1;
    
    vector<int> res;
    while (i >= 0 || j < size) {
      if (i >= 0 && abs(nums[i]) < abs(nums[j])) {
        res.push_back(nums[i] * nums[i]);
        i--;
      } else if (j < size) {
        res.push_back(nums[j] * nums[j]);
        j++;
      }
    }

    return res;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {-7, -3, 0, 2, 3, 11};

  vector<int> res = solution.sortedSquares(nums);

  for (int elem : res) {
    cout << elem << " ";
  }
  cout << endl;

  return 0;
}