#include <queue>
#include <iostream>
#include <limits.h>

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
  int minDepth(TreeNode *tree) {
    if (!tree) return 0;

    // Use breadth-first search
    queue<pair<TreeNode*, int>> q;

    q.push({tree, 1});

    while (!q.empty()) {
      auto [node, depth] = q.front();
      q.pop();

      if (!node->left && !node->right) {
        return depth;
      }

      if (node->left)
        q.push({node->left, depth + 1});
      if (node->right)
        q.push({node->right, depth + 1});
    }

    return 0;
  }

};

int main () {
  // Construct the following binary tree:
  //      1
  //     / \
  //    2   3
  //   /
  //  4
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2, new TreeNode(4), nullptr);
  root->right = new TreeNode(3);

  Solution sol;
  int result = sol.minDepth(root);
  cout << "Minimum depth: " << result << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}