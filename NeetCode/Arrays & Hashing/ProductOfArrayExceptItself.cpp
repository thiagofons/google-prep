#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> res(n);
    vector<int> pref(n);
    vector<int> suff(n);

    pref[0] = 1;
    suff[n - 1] = 1;

    for (int i = 1; i < n; i++) {
      pref[i] = nums[i - 1] * pref[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      suff[i] = nums[i + 1] * suff[i + 1];
    }
    for (int i = 0; i < n; i++) {
      res[i] = pref[i] * suff[i];
    }
    
    return res;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {1, 2, 4, 6};

  vector<int> res = solution.productExceptSelf(nums);

  for (int num : res) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}