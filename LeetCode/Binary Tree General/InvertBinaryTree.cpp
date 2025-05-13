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
    TreeNode* invertTree(TreeNode* root) {
      if (!root) 
        return nullptr;
      
      // Swap left with right
      TreeNode *aux = root->left;
      root->left = root->right;
      root->right = aux;
      
      // Call for left and right nodes recursively
      invertTree(root->left);
      invertTree(root->right);

      // Return the root, in the end
      return root;
    }
};

int main() {
  // Helper function to print the tree in level order
  auto printTree = [](TreeNode* root) {
    if (!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node) {
        std::cout << node->val << " ";
        q.push(node->left);
        q.push(node->right);
      } else {
        std::cout << "null ";
      }
    }
    std::cout << std::endl;
  };

  // Construct the tree [4,2,7,1,3,6,9]
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

  // Print original tree
  std::cout << "Original tree: ";
  printTree(root);

  // Invert the tree
  Solution solution;
  TreeNode* invertedRoot = solution.invertTree(root);

  // Print inverted tree
  std::cout << "Inverted tree: ";
  printTree(invertedRoot);

  return 0;
}