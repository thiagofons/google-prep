#include <algorithm>
#include <vector>
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
    int maxDepth(TreeNode *root) {
		if (root == nullptr) 
			return 0;

		return 1 + max(maxDepth(root->left), maxDepth(root->right));
  	}
};

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

int main() {
	vector<int> values = {1, -1, 2}; // Example tree: [3, 9, 20, null, null, 15, 7]
	TreeNode* root = buildTree(values);

	Solution solution;
	int depth = solution.maxDepth(root);

	// Output the result
	cout << "Maximum depth of the binary tree: " << depth << endl;

	return 0;
}