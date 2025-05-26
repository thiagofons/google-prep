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
public:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
      return;

    grid[r][c] = '0';
    
    for (int i = 0; i < 4; i++) {
      dfs(grid, r + directions[i][0], c + directions[i][1]);
    }
  }

  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size(), columns = grid[0].size();
    int islands = 0;

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < columns; c++) {
        if (grid[r][c] == '1') {
          dfs(grid, r, c);
          islands++;
        }
      }
    }
    return islands;
  }
};

int main () {
  Solution s;

  vector<vector<char>> grid = {
    {'0','1','1','1','0'},
    {'0','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };

  int num = s.numIslands(grid);
  cout << num << endl;

  return 0;
}