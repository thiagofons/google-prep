#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ranges = {};

		if (nums.size() == 0) {
			return ranges;
		}

		if (nums.size() == 1) {
			ranges = {to_string(nums[0])};
			return ranges;
		}

		// Iterate over the array
		int i = 0, j = 1;
		string interval = to_string(nums[i]);
		
		while (j < nums.size()) {
			if (static_cast<long long>(nums[j]) - static_cast<long long>(nums[j - 1]) == 1) {
				j++;
				continue;
			}
			
			if (i != j - 1) {
				interval += "->" + to_string(nums[j - 1]);
			}
			
			ranges.push_back(interval);

			i = j++;
			interval = to_string(nums[i]);
		}

		if(i != j - 1) {
			interval += "->" + to_string(nums[j - 1]);	
		}
		
		ranges.push_back(interval);

		return ranges;
    }
};

int main () {
	Solution solution;
	vector<int> nums = {-2147483648,-2147483647,2147483647};

	vector<string> ranges = solution.summaryRanges(nums);

	for (const string& range : ranges) {
		cout << range << endl;
	}

	return 0;
}
