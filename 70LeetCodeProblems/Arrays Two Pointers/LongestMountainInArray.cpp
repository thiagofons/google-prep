#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  int longestMountain(vector<int>& arr) {
    int height = 0;


    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {

        int left = i, right = i;

        while (left >= 0 && arr[left] > arr[left - 1])
          left--;

        while (right < arr.size() && arr[right] > arr[right + 1])
          right++;
        
        height = max(height, right - left + 1);
      }
    }
    return height;
  }
};

int main () {
  Solution solution;

  vector<int> arr = {2, 1, 4, 7, 3, 2, 5};

  cout << solution.longestMountain(arr) << endl;

  return 0;
}