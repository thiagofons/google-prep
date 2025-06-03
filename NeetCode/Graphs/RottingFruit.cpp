#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
private:
  int directions[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
  };

  void bfs (vector<vector<int>>& grid, int node) {
    queue<int> q;

    q.push(node);

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int neighbour : grid)
    }
  }

public:
  int orangesRotting(vector<vector<int>>& grid) {
    // Number of nodes
    int nodes = grid.size();

    // Find the first rotten fruit
    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        if (grid[i][j] == 2) {
          // Run the BFS in this node

        }
      }
    }
  }
};

int main () {
  Solution solution;

  vector<vector<int>> grid = {
    {1, 1, 0},
    {0, 1, 1},
    {0, 1, 2}
  };

  cout << solution.orangesRotting(grid) << endl;

  return 0;
}