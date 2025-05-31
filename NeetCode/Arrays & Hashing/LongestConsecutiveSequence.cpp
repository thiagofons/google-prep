#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int size = nums.size();

    unordered_set<int> set;

    // Iterate over the array, putting nums[i] in set
    for (int i = 0; i < size; i++) 
      set.insert(nums[i]);
    

    int longest = 0;
    for (int i = 0; i < size; i++) {
      int num = nums[i];

      if (set.count(num - 1) == 0) {
        // Num is a start of a sequence
        int length = 0;

        while (set.count(num + length) > 0) 
          length++;

        longest = max(length, longest);
      }
    }
    return longest;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {2, 20, 4, 10, 3, 4, 5};

  cout << solution.longestConsecutive(nums) << endl;

  return 0;
}