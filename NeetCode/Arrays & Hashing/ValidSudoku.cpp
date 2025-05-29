#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int rows = board.size(), cols = board[0].size();

    unordered_map<int, unordered_set<char>> column_map;
    unordered_map<int, unordered_set<char>> box_map;

    for (int i = 0; i < rows; i++) {
      unordered_set<char> row_set;

      for (int j = 0; j < cols; j++) {
        char element = board[i][j];

        if (element != '.') {
          // Check if it's in the row
          if (row_set.count(element) > 0) 
            return false;
          
          row_set.insert(element);
          
          // Check if it's in the column
          if(column_map[j].count(element) > 0) 
            return false;
          
          column_map[j].insert(element);

          // Check if it's in the box
            int box_index = (i / 3) * 3 + (j / 3);
            if (box_map[box_index].count(element) > 0)
            return false;

            box_map[box_index].insert(element);
        }
      }
    }
    return true;
  }
};

int main () {
  Solution solution;

  vector<vector<char>> board = {
    {'1','2','.','.','3','.','.','.','.'},
    {'4','.','.','5','.','.','.','.','.'},
    {'.','9','8','.','.','.','.','.','3'},
    {'5','.','.','.','6','.','.','.','4'},
    {'.','.','.','8','.','3','.','.','5'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','.','.','.','.','.','2','.','.'},
    {'.','.','.','4','1','9','.','.','8'},
    {'.','.','.','.','8','.','.','7','9'}
  };

  bool res = solution.isValidSudoku(board);

  cout << (res ? "true" : "false") << endl;

  return 0;
}