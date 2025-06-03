#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  private:
  vector<vector<int>> directions = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
  };

  void dfs (vector<vector<string>>& grid, int row, int column) {
    if (row < 0 || row >= grid.size() || column < 0 || column >= grid.size() || grid[row][column] == "0") return;

    grid[row][column] = "0";

    for (int i = 0; i < directions.size(); i++) {
      dfs(grid, row + directions[i][0], column + directions[i][1]);
    }
  }

  public:
  int numIslands(vector<vector<string>>& grid) {
    int rows = grid.size(), columns = grid[0].size();

    int islands = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (grid[i][j] == "1") {
          dfs(grid, i, j);

          islands++;
        }
      }
    }

    return islands;
  }
};

int main () {
  Solution solution;

  vector<vector<string>> grid = {
    {"1", "1", "0", "1", "0"},
    {"1", "1", "0", "1", "0"},
    {"1", "1", "0", "0", "0"},
    {"0", "0", "0", "0", "0"}
  };

  cout << solution.numIslands(grid) << endl;

  return 0;
}