#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> num_set;

		for (int i = 0; i < nums.size(); i++) {
			num_set.insert(nums[i]);
		}

		return num_set.size();
    }
};

int main() {
	Solution solution;
	vector<int> nums = {1, 1, 2};
	
	int duplicates = solution.removeDuplicates(nums);
	cout << "Number of duplicates removed: " << duplicates << endl;

	return 0;
}


