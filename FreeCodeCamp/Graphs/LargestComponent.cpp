#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

int explore (Graph graph, int current, unordered_set<int> visited) {
  if (visited.count(current) > 0) return 0;

  visited.insert(current);

  int size = 1;

  for (auto neighbor : graph[current]) {
    size += explore(graph, neighbor, visited);
  }

  return size;
}

int largestComponent (Graph graph) {
  unordered_set<int> visited;
  int largest = 0;

  for (auto node : graph) {
    int current = node.first;

    int size = explore(graph, current, visited);

    if (size > largest) largest = size;
  }

  return largest;
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

  int largestSize = largestComponent(graph);

  cout << "Largest size: " << largestSize << endl;

  return 0;
}

