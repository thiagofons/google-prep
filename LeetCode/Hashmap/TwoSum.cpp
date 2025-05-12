#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); i++) {
			int value = nums[i];

			int index = target - value;

			if (map.count(index)) {
				return {i, map[index]};
			}
			map[value] = i;
		}
		return {};
    }
};

int main() {
	Solution solution;

	vector<int> nums = {3, 2, 4};
	int target = 6;

	vector<int> result = solution.twoSum(nums, target);

	for (int r : result) {
		cout << r << " ";
	}
	cout << endl;

	return 0;
}