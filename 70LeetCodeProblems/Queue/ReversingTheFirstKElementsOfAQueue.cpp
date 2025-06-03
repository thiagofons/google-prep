#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
  public:
  queue<int> reverseFirstKElements(queue<int> q, int k) {
    stack<int> s;

    // Put first k elements in stack
    for (int i = 0; i < k; i++) {
      int element = q.front();
      q.pop();

      s.push(element);
    }

    // Put the elements on the end of the queue
    while (!s.empty()) {
      int element = s.top();
      s.pop();

      q.push(element);
    }

    // Put the first elements of the queue on its end
    for (int i = 0; i < q.size() - k; i++) {
      int element = q.front();
      q.pop();

      q.push(element);
    }
    
    return q;
  }
};

int main() {
  queue<int> q;
  for (int i = 1; i <= 5; ++i) {
    q.push(i);
  }
  int k = 3;

  Solution sol;
  
  cout << "Original queue: ";
  queue<int> temp = q;
  while (!temp.empty()) {
    cout << temp.front() << " ";
    temp.pop();
  }
  cout << endl;

  // After implementing reverseFirstKElements, you can call it here
  queue<int> res = sol.reverseFirstKElements(q, k);

  cout << "Queue after reversing first " << k << " elements: ";
  temp = res;
  while (!temp.empty()) {
    cout << temp.front() << " ";
    temp.pop();
  }
  cout << endl;

  return 0;
}