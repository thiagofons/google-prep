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
  TreeNode* buildTree(const vector<int>& values) {
    if (values.empty()) 
      return nullptr;

    vector<TreeNode*> nodes(values.size(), nullptr);
    for (size_t i = 0; i < values.size(); ++i) {
      if (values[i] != -1) { // Assuming -1 represents null
        nodes[i] = new TreeNode(values[i]);
      }
    }

    for (size_t i = 0; i < values.size(); ++i) {
      if (nodes[i] != nullptr) {
        if (2 * i + 1 < values.size()) 
          nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < values.size()) 
          nodes[i]->right = nodes[2 * i + 2];
      }
    }

    return nodes[0];
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> res;

    res.push_back({root->val});

    queue<TreeNode*> nodeQueue; // Attention: Create a queue that stores the node, not the vals
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
      // Get the number of nodes on each level
      int levelSize = nodeQueue.size();
      vector<int> level;

      for (int i = 0; i < levelSize; ++i) {
        // Add the current node into the level
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        level.push_back(node->val);

        // Push the child nodes into the queue
        if (node->left) nodeQueue.push(node->left);
        if (node->right) nodeQueue.push(node->right);
      }

      // Add the level to the res vector
      res.push_back(level);
    }

    // Remove the first push_back from above, as it duplicates the root level
    res.erase(res.begin());

    return res;
  }
};

int main () {
  Solution solution;

  vector<int> root = {1, 2, 3, 4, 5, 6, 7};

  TreeNode *tree = solution.buildTree(root);

  vector<vector<int>> res = solution.levelOrder(tree);

  for (const auto& level : res) {
    for (int value : level) {
      cout << value << " ";
    }
    cout << endl;
  }

  return 0;
}

