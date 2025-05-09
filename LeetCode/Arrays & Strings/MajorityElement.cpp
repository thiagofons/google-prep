#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		unordered_map<int, int> map;
		// num: times

		for (int i : nums) {
			map[i] += 1;
		}

		int max_times = 0, max_element = 0;
		for (auto it : map) {
			if (it.second > max_times) {
				max_element = it.first;
				max_times = it.second;
			} 				
		}

		return max_element;
    }
};

int main() {
	Solution solution;
	vector<int> nums = {3,2,3};

	int majorityElement = solution.majorityElement(nums);

	cout << majorityElement << endl;
	
	return 0;
}