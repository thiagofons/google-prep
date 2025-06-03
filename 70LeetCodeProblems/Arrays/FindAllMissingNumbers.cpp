#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
  public:
  vector<int> findDisappearedNumbers (vector<int>& nums) {
    // Convert the array to a set
    set<int> s(nums.begin(), nums.end());

    // Iterate trough the sorted array checking if i + 1 == nums[i]
    vector<int> missing;

    for (int i = 1; i < nums.size() + 1; i++) {
      if (s.find(i) == s.end()) {
        missing.push_back(i);
      }      
    }
    
    return missing;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {1, 1};

  vector<int> res = solution.findDisappearedNumbers(nums);

  for (int value : res) {
    cout << value << " ";
  }
  cout << endl;

  return 0;
}