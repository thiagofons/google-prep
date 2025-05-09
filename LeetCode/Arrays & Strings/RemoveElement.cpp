#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int i = 0, k = 0;

		while (i < nums.size()) {
			if (nums[i] != val) {
				nums[k] = nums[i];
				k++;
			} 
			i++;
		}
		return k;
    }
};

int main() {
	Solution solution;

	vector<int> nums = {3,2,2,3};
	int val = 3;
	
	int number = solution.removeElement(nums, val);
	cout << number << endl;

	return 0;
}