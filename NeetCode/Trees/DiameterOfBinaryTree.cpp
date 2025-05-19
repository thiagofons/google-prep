#include <iostream>
#include <queue>

using namespace std;



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  int max_height = 0;

  int dfs(TreeNode *root) {
    if (!root) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    max_height = max(max_height, left + right);

    return 1 + max(left, right);
  }

public:
  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);

    return max_height;
  }
};


int main() {
  // Construct the tree [1,2,3]
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  

  Solution solution;
  solution.diameterOfBinaryTree(root);
  cout << solution.diameterOfBinaryTree(root) << endl;

  
  return 0;
}