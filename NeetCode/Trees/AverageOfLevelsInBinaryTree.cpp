#include <iostream>
#include <vector>
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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> averages;

    if (!root) return averages;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int levelSize = q.size(); // Can be zero, one or two on a binary tree
      double sum = 0;

      for (int i = 0; i < levelSize; ++i) {
        TreeNode* node = q.front();

        q.pop();
        sum += node->val;

        if (node->left) 
          q.push(node->left);
        if (node->right) 
          q.push(node->right);
      }

      averages.push_back(sum / levelSize);
    }
    return averages;
  }
};

int main() {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  // Example usage:
  Solution sol;
  vector<double> result = sol.averageOfLevels(root);
  for (double avg : result) {
    cout << avg << " ";
  }
  cout << endl;

  // Clean up memory
  delete root->right->right;
  delete root->right->left;
  delete root->right;
  delete root->left;
  delete root;

  return 0;
}