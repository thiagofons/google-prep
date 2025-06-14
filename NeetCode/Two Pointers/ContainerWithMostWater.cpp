#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxArea(vector<int>& heights) {
    // Get the size of the vector
    int size = heights.size();

    // Keep the maximum area
    int maximum = 0;

    // Two pointers to calculate the area
    int start = 0, end = size - 1;

    while (start < end) {
      int area = (end - start) * min(heights[start], heights[end]);

      if (heights[end] < heights[start])
        end--;
      else
        start++;

      maximum = max(maximum, area);
    }

    return maximum;
  }
};

int main () {
  Solution s;

  vector<int> heights = {2, 2, 2};

  cout << s.maxArea(heights) << endl;

  return 0;
}
