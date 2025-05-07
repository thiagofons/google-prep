#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int mi = m - 1;
		int r = m + n - 1;
		int ni = n - 1;

		while (ni >= 0) {
			if (mi >= 0 && nums1[mi] > nums2[ni]) {
				nums1[r] = nums1[mi];
				mi--;
			}
			else {
				nums1[r] = nums2[ni];
				ni--;
			}
			r--;
		}
    }
};


int main() {
	Solution solution;
	vector<int> nums1 = {0};
	int m = 0;
	vector<int> nums2 = {1};
	int n = 1;

	solution.merge(nums1, m, nums2, n);

	cout << "Merged array: ";
	for (int num : nums1) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}