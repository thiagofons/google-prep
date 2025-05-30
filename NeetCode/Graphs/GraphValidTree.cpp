#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
private:
  bool bfs(vector<vector<int>>& graph, vector<bool>& visited, int source) {
    queue<pair<int, int>> q; // pair: (node, parent)

    q.push({source, -1});

    while (!q.empty()) {
      auto [current, parent] = q.front();
      q.pop();

      if (visited[current])
        return true;

      visited[current] = true;

      for (int neighbour : graph[current]) {
        if (neighbour == parent) continue; // skip the parent
        if (visited[neighbour]) return true; // found a cycle
        q.push({neighbour, current});
      }
    }
    return false;
  }

public:
  bool validTree(int n, vector<vector<int>>& edges) {
    // Create the graph
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    // Check if there's any cycles in the graph
    if (bfs(graph, visited, 0)) return false;

    // Check if the graph is fully connected
    for (bool v : visited) {
      if (!v) return false;
    }
    return true;
  }
};

int main () {
  Solution solution;

  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};

  bool res = solution.validTree(n, edges);

  cout << (res ? "true" : "false") << endl;

  return 0;
}
