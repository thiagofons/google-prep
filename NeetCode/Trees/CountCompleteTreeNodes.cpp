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
  int nodes = 0;
public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;

    nodes++;

    countNodes(root->left);
    countNodes(root->right);

    return nodes;
  }
};

int main () {
  Solution s;

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->left->left = new TreeNode(5);

  cout << s.countNodes(root);

  return 0;
}