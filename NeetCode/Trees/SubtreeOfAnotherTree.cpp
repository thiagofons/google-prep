#include <iostream>

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
  bool checkSubtrees(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot) return true;

    if (!root || !subRoot || root->val != subRoot->val) return false;

    return checkSubtrees(root->left, subRoot->left) && checkSubtrees(root->right, subRoot->right);
  }
  
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;

    if (checkSubtrees(root, subRoot)) return true;
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};

int main () {
  Solution solution;

  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(2);

  TreeNode* subRoot = new TreeNode(4);
  subRoot->left = new TreeNode(1);
  subRoot->right = new TreeNode(3);

  
  bool result = solution.isSubtree(root, subRoot);

  cout << (result ? "subRoot is a subtree of root" : "subRoot is NOT a subtree of root") << endl;

  return 0;
}
