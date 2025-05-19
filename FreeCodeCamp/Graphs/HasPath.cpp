#include <unordered_map>
#include <stack>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/**
 * 
 * @brief Depth-First solution
 * 
 * @param graph 
 * @param source 
 * @param destination 
 * @return true 
 * @return false 
 */
bool hasPathDepth (unordered_map<char, vector<char>> graph, char source, char destination) {
  if (source == destination)
    return true;

  vector<char> neighbors = graph[source];

  // Check all my neighbours
  for (char neighbor : neighbors) {
    if (hasPathDepth(graph, neighbor, destination)) {
      return true;
    }
  }

  return false;
}

/**
 * @brief Breadth-First solution
 * 
 * @param graph 
 * @param source 
 * @param destination 
 * @return true 
 * @return false 
 */
bool hasPathBeadth (unordered_map<char, vector<char>> graph, char source, char destination) {
  queue<char> q;

  q.push(source);

  while (!q.empty()) {
    char current = q.front();
    q.pop();

    if (current == destination) 
      return true;

    for (char neighbor : graph[current]) {
      q.push(neighbor);
    }    
  }

  return false;
}


int main () {
  unordered_map<char, vector<char>> graph = {
    {'a', {'b', 'c'}},
    {'b', {'d'}},
    {'c', {'e'}},
    {'d', {'f'}},
    {'e', {}},
    {'f', {}},
  };

  bool result = hasPathBeadth(graph, 'b', 'e');

  if (result) {
    cout << "Has path!" << endl;
  } else {
    cout << "Does not have path!" << endl;
  }

  return 0;
}