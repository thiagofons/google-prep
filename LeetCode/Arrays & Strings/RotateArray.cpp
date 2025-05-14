#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  /*
  - Usign additional linear memory

  void rotate(vector<int>& nums, int k) {
    int len = nums.size();

    vector<int> new_nums(len);

    for (int i = 0; i < len; i++) {
      new_nums[(i + k) % len] = nums[i];
    }

    nums = new_nums;
  }
  */

  /*
  - Using additional constant memory 
  
  */
  void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
      int aux = nums[left];
      nums[left] = nums[right];
      nums[right] = aux;

      left++;
      right--;
    }
  }

  void rotate(vector<int>& nums, int k) {
    int size = nums.size();

    k = k % size;

    reverse(nums, 0, size - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, size - 1);
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  cout << "Original array: ";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  solution.rotate(nums, k);

  cout << "Rotated array: ";
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

