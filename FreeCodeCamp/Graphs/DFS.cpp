#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

/*

- Iterative algorithm

void depthFirstPrint (unordered_map<char, vector<char>> graph, char source) {
  stack<char> st;

  // Start the stack with the source
  st.push(source);

  while (!st.empty()) {
    char current = st.top();
    cout << current << endl;

    st.pop();

    // Push the neighbors to the stack
    for (char neighbor : graph[current]) {
      st.push(neighbor);
    }
  }
}
*/

/*

- Recursive algorithm

*/
void depthFirstPrint (unordered_map<char, vector<char>> graph, char source) {
  cout << source << endl;

  for (char neighbor : graph[source]) {
    depthFirstPrint(graph, neighbor);
  }
}

int main () {
  unordered_map<char, vector<char>> graph = {
    {'a', {'b', 'c'}},
    {'b', {'d'}},
    {'c', {'e'}},
    {'d', {'f'}},
    {'e', {}},
    {'f', {}},
  };

  depthFirstPrint(graph, 'a');

  return 0;
}