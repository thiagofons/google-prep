#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		vector<set<char>> rows(9), cols(9), boxes(9);

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				char num = board[i][j];

				if (num == '.')
					continue;

				int box_index = (i / 3) * 3 + (j / 3);
				
				if (rows[i].count(num) > 0 || cols[j].count(num) > 0 || boxes[box_index].count(num) > 0) {
					return false;
				}

				rows[i].insert(num);
				cols[j].insert(num);
				boxes[box_index].insert(num);
			}
		}
		return true;
    }
};

int main() {
  vector<vector<char>> board = {
    {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };

	Solution solution;
	int isValid = solution.isValidSudoku(board);

	// Output the result
	cout << isValid << endl;

	return 0;
}