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
    bool isSameTree(TreeNode* p, TreeNode* q) {     
      if (!p && !q) return true;

      if (!p || !q) return false;
  
      bool left = isSameTree(p->left, q->left);
      bool right = isSameTree(p->right, q->right);

      return p->val == q->val && left && right;
    }
};

int main() {
  Solution solution;

  // Create test trees
  TreeNode* tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* tree3 = new TreeNode(1, new TreeNode(2), nullptr);

  // Test cases
  cout << "Tree1 and Tree2 are the same: " << (solution.isSameTree(tree1, tree2) ? "True" : "False") << endl;
  cout << "Tree1 and Tree3 are the same: " << (solution.isSameTree(tree1, tree3) ? "True" : "False") << endl;

  // Clean up memory
  delete tree1->left;
  delete tree1->right;
  delete tree1;

  delete tree2->left;
  delete tree2->right;
  delete tree2;

  delete tree3->left;
  delete tree3;

  return 0;
}