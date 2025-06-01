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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *curr = root;

    while (curr) {
      if (p->val > curr->val && q->val > curr->val) {
        curr = curr->right;
      }
      else if (p->val < curr->val && q->val < curr->val) {
        curr = curr->left;
      }
      else {
        return curr;
      }
    }
    
    return curr;
  }
};

int main () {
  Solution solution;

  TreeNode *tree = new TreeNode(5, new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4)), new TreeNode(8, new TreeNode(7), new TreeNode(9)));

  TreeNode *ancestor = solution.lowestCommonAncestor(tree, new TreeNode(3), new TreeNode(4));

  cout << ancestor->val << endl;

  return 0;
}