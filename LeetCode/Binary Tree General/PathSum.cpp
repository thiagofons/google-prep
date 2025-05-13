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

  bool hasPathSumAux(TreeNode *root, int targetSum, int current) {
    if (!root) return false;

    // If the current value is equal to the target and it is a leaf
    if (current + root->val == targetSum && !root->left && !root->right) return true;

    bool left = hasPathSumAux(root->left, targetSum, current + root->val);
    bool right = hasPathSumAux(root->right, targetSum, current + root->val);

    return left || right;
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    return hasPathSumAux(root, targetSum, 0);
  }
};

int main() {
  Solution solution;

  // Create the test tree: [5,4,8,11,null,13,4,7,2,null,null,null,1]
  TreeNode* tree = new TreeNode(5, 
                    new TreeNode(4, 
                      new TreeNode(11, 
                        new TreeNode(7), 
                        new TreeNode(2)
                      ), 
                      nullptr
                    ), 
                    new TreeNode(8, 
                      new TreeNode(13), 
                      new TreeNode(4, 
                        nullptr, 
                        new TreeNode(1)
                      )
                    )
                  );

  int targetSum = 22;

  // Test case
  cout << "Tree has path sum " << targetSum << ": " 
       << (solution.hasPathSum(tree, targetSum) ? "True" : "False") << endl;

  // Clean up memory
  delete tree->left->left->left;  // 7
  delete tree->left->left->right; // 2
  delete tree->left->left;        // 11
  delete tree->left;              // 4

  delete tree->right->left;       // 13
  delete tree->right->right->right; // 1
  delete tree->right->right;      // 4
  delete tree->right;             // 8

  delete tree;                    // 5

  return 0;
}