#include <vector>
#include <iostream>

using namespace std;

/*
class Solution {
public:
  void check (vector<int>& nums, vector<bool>& jumped, int index) {
    if (index >= nums.size() || jumped[index]) return;

    jumped[index] = true;

    check(nums, jumped, index + nums[index]);
  }

  bool canJump(vector<int>& nums) {
    int size = nums.size();

    vector<bool> jumped(size, false);

    for (int i = 0; i < size; i++) {
      if (!jumped[i]) {
        check(nums, jumped, i);
      }
    }

    for (int i = 0; i < size; i++) {
      cout << (jumped[i] ? "true" : "false") << " ";
      if (!jumped[i]) {
        return false;
      }
    }

    cout << endl << endl;



    return true;
  }
};
*/

/**

- Recursive solution (exponential time)

class Solution {
public:
  void check(vector<int>& nums, vector<bool>& jumped, int index) {
    if (index >= nums.size() || jumped[index]) return;

    jumped[index] = true;

    for (int jump = 1; jump <= nums[index]; ++jump) {
      check(nums, jumped, index + jump);
    }
  }

  bool canJump(vector<int>& nums) {
    int size = nums.size();
    vector<bool> jumped(size, false);

    check(nums, jumped, 0); // Começa do índice 0

    return jumped[size - 1];
  }
};
*/

class Solution {
  public:
  bool canJump (vector<int>& nums) {
    int maxReach = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      if (i > maxReach) return false;

      maxReach = max(maxReach, i + nums[i]);
    }

    return true;
  }
};

int main () {
  Solution s;

  vector<int> nums = {2, 3, 1, 1, 4};

  bool res = s.canJump(nums);

  cout << (res ? "true" : "false") << endl;

  return 0;
}