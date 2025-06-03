#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
private:
  unordered_map<int, vector<int>> newGraph;

  Node *cloneGraphAux(Node* node, vector<int> visited) {
    if (node->neighbors.empty()) return nullptr;

    if (!visited[node->val]) {
      visited[node->val] = true;

      for (auto neighbor : node->neighbors) {
        return cloneGraphAux(neighbor, visited);
      }
    }
  }

public:
  
  Node* cloneGraph(Node* node) {
    vector<int> visited;

    return cloneGraphAux(node, visited);    
  }
};

int main () {
  Solution solution;


}