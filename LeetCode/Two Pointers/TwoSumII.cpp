#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;

		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum == target)
				return {i + 1, j + 1};
			
			if (sum < target) {
				i++;
				continue;
			}
			j--;
		}
		return {};
    }
};

int main () {
	Solution s;

	vector<int> numbers = {-1, 0};
	int target = -1;

	vector<int> res = s.twoSum(numbers, target);

	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}