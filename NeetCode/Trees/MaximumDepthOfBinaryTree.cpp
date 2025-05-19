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
  int maxDepth(TreeNode* root) {
    if (!root) return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

int main() {
  // Construct the tree [1,2,3,null,null,4]
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3, new TreeNode(4), nullptr);  

  Solution solution;
  int depth = solution.maxDepth(root);

  cout << depth << endl;
  
  return 0;
}