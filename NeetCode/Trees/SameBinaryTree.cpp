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
    if (!p && !q) 
      return true;

    if (p && q && p->val == q->val) 
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else  
      return false;
  }
};

int main () {
  Solution solution;

  TreeNode* tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

  if (solution.isSameTree(tree1, tree2)) {
    cout << "The trees are the same." << endl;
  } else {
    cout << "The trees are different." << endl;
  }

  // Clean up memory
  delete tree1->left;
  delete tree1->right;
  delete tree1;
  delete tree2->left;
  delete tree2->right;
  delete tree2;

  return 0;
}