#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

Graph buildGraph (vector<vector<int>> edges) {
  Graph graph;

  for (vector<int> edge : edges) {
    char a = edge[0];
    char b = edge[1];

    if (graph.find(a) == graph.end()) graph[a] = {};
    if (graph.find(b) == graph.end()) graph[b] = {};

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  return graph;
}

bool explore (Graph graph, int current, unordered_set<int> visited) {
  if (visited.count(current) > 0) return false;

  visited.insert(current);

  for (auto neighbor : graph[current]) {
    explore(graph, neighbor, visited);
  }

  return true;
}

int connectedComponentsCount (Graph graph) {
  unordered_set<int> visited;
  int count = 0;

  for (auto item : graph) {
    char node = item.first;

    if (explore(graph, node, visited)) {
      count++;
    }
  }

  return count;
}

int main () {
  Graph graph = {
    {0, {8, 1, 5}},
    {1, {0}},
    {5, {0, 8}},
    {8, {0, 5}},
    {2, {3, 4}},
    {3, {2, 4}},
    {4, {3, 2}}
  };

  int count = connectedComponentsCount(graph);

  cout << "Count: " << count << endl;

  return 0;
}