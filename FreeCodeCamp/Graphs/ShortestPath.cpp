#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

typedef unordered_map<char, vector<char>> Graph;

typedef vector<vector<char>, int> Edge;

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


vector<int> shortestPath(Graph graph, char nodeA, char nodeB) {
  queue<Edge> q;



}

int main () {
  vector<vector<char>> edges = {
    {'w', 'x'},
    {'x', 'y'},
    {'z', 'y'},
    {'z', 'v'},
    {'w', 'v'}
  };

  Graph graph = buildGraph(edges);

  vector<int> path = shortestPath(graph);
  
  cout << "Shortest path: " << endl;
  for (int node : path) 
    cout << node << " ";
  cout << endl;

  return 0;
}