#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {	
			set<int> s;

			for (int i = 0; i < nums.size(); i++) {
				s.insert(nums[i]);
			}

			int idx = 0;
			for (int num : s) {
				nums[idx++] = num;
			}

			return s.size();
    }
};

int main() {
	Solution solution;
	vector<int> nums = {1, 1, 2};
	
	int duplicates = solution.removeDuplicates(nums);
	cout << "Number of duplicates removed: " << duplicates << endl;

	return 0;
}


