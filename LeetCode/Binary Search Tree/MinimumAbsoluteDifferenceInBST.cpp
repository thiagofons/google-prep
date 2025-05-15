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
public:
    int getMinimumDifference(TreeNode* root) {
      printf("%d\n", root->val);
      if (!root) return 0;

      if (!root->left && !root->right) return root->val;

      int leftDiff = abs(root->val - getMinimumDifference(root->left));
      int rightDiff = abs(root->val - getMinimumDifference(root->right));

      return min(leftDiff, rightDiff);
    }
};

int main() {
  // Create a sample BST
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  // Create a Solution object and test the method
  Solution solution;
  int result = solution.getMinimumDifference(root);

  // Output the result
  cout << "Minimum Absolute Difference in BST: " << result << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}