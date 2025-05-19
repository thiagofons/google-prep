#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<char, vector<char>> Graph;

Graph buildGraph (vector<vector<char>> edges) {
  Graph graph;

  for (vector<char> edge : edges) {
    char a = edge[0];
    char b = edge[1];

    if (graph.find(a) == graph.end()) graph[a] = {};
    if (graph.find(b) == graph.end()) graph[b] = {};

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  return graph;
}

bool hasPath (Graph graph, char src, char dst, unordered_set<char> visited) {
  cout << src << endl;

  if (src == dst) return true;

  if (visited.find(src) != visited.end()) return false;

  visited.insert(src);

  for (char neighbor : graph[src]) {
    if (hasPath(graph, neighbor, dst, visited)) {
      return true;
    }
  }
  return false;
}

bool undirectedPath (vector<vector<char>> edges, char nodeA, char nodeB) { 
  Graph graph = buildGraph(edges);
  unordered_set<char> visited;

  return hasPath(graph, nodeA, nodeB, visited);
}

int main () {
  vector<vector<char>> edges = {
    {'i', 'j'},
    {'k', 'i'},
    {'m', 'k'},
    {'k', 'l'},
    {'o', 'n'}
  };

  bool result = undirectedPath(edges, 'i', 'k');

  if (result)
    cout << "Has path!" << endl;
  else
    cout << "Does not have path!" << endl;

  return 0;
}