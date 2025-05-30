#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    
  }
};

int main () {
  Solution solution;

  string s1 = "abc";
  string s2 = "lecabee";

  bool res = solution.checkInclusion(s1, s2);

  cout << (res ? "true" : "false") << endl;

  return 0;
}
