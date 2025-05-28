#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, middle = start + end / 2;

    while (start != middle || end != middle) {    
      if (nums[middle] == target)
        return middle;

      if (nums[middle] < target)
        start = middle;
      else
        end = middle;

      if (start == middle)
        return start + 1;
      if (end == middle)
        return end + 1;

      middle = start + end / 2;
    }

    return middle;
  }
};

int main () {
  Solution s;

  vector<int> nums = {1, 3, 5, 6};
  int target = 7;

  cout << s.searchInsert(nums, target) << endl;

  return 0;
}
