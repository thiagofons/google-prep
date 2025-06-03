#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Interval {
  public:
    int start, end;

    Interval(int start, int end) {
      this->start = start;
      this->end = end;
    }
};

class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) { 
      return x.start < y.start; 
    });

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start < intervals[i - 1].end) {
        return false;
      }
    }
    return true;
  }
};

int main () {
  Solution solution;

  vector<Interval> intervals = { Interval(0, 30), Interval(5, 10), Interval(15, 20) };

  bool result = solution.canAttendMeetings(intervals);

  cout << (result ? "true" : "false") << endl;

  return 0;
}