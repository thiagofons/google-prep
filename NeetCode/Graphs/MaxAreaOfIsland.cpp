#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
private:
  int directions[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
  };
  int currentArea = 0;
public:
  void dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
      return;

    grid[r][c] = 0;
    currentArea++;
    
    for (int i = 0; i < 4; i++) {
      dfs(grid, r + directions[i][0], c + directions[i][1]);
    }
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size(), columns = grid[0].size();
    int maxArea = 0;

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < columns; c++) {
        if (grid[r][c] == 1) {
          dfs(grid, r, c);
          
          maxArea = max(maxArea, currentArea);
          currentArea = 0;
        }
      }
    }
    return maxArea;
  }
};

int main () {
  Solution s;

  vector<vector<int>> grid = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 0, 1}
  };

  int area = s.maxAreaOfIsland(grid);
  cout << area << endl;

  return 0;
}