#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void dfs (const vector<vector<int>>& adj, vector<bool>& visit, int node) {
    visit[node] = true;

    for (int neighbour : adj[node]) {
      if (!visit[neighbour]) {
        dfs(adj, visit, neighbour);
      }
    }
  }

public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> visit(n, false);

    // Create the graph as an adjacency list
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    // Count the components, running a bfs in each node of the graph
    int components = 0;

    for (int node = 0; node < n; node++) {
      if (!visit[node]) {
        dfs(adj, visit, node);
        components++;
      }
    }

    return components;
  }
};

int main () {
  Solution solution;

  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};

  cout << solution.countComponents(n, edges) << endl;

  return 0;
}
