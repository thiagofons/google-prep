#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int a = 0, b = numbers.size() - 1;

    while (a < b) {
      int sum = numbers[a] + numbers[b];

      if (sum == target)
        return {a + 1, b + 1};

      if (sum < target)
        a++;
      else
        b--;
      
    }
  }
};

int main () {
  Solution solution;

  vector<int> numbers = {1,2,3,4};
  int target = 3;

  vector<int> res = solution.twoSum(numbers, target);

  for (int item : res)
    cout << item << " ";
  
  cout << endl;

  return 0;
}