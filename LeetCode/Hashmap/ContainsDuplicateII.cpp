#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); i++) {
			int value = nums[i];

			if (map.count(value) > 0 && abs(map[value] - i) <= k) {
				return true;
			}

			map[value] = i;
		}
		return false;
    }
};

int main() {
	Solution solution;

	vector<int> nums = {1, 2, 3, 1, 2, 3};
	int k = 2;

	bool containsDuplicate = solution.containsNearbyDuplicate(nums, k);

	cout << containsDuplicate << endl;

	return 0;
}