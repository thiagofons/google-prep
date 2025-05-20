#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    stack<int> s;

    s.push(source);

    for (vector<int> edge : edges) {
      if (edge[1] == destination)
        return true;

      if (edge[0] == s.top()) 
        s.push(edge[1]);
      else
        s.pop();
    }

    // Print the elements of the stack
    stack<int> temp = s;
    while (!temp.empty()) {
      cout << temp.top() << endl;
      temp.pop();
    }

    return false;

  }
};

int main () {
  Solution solution;

  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
  int source = 0;
  int destination = 5;

  bool result = solution.validPath(n, edges, source, destination);

  if (result) 
    cout << "True" << endl;
  else
    cout << "False" << endl;

  return 0;
}