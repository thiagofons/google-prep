#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

void bradthFirstPrint(unordered_map<char, vector<char>> graph, char source) {
  queue<char> q;

  // Start the queue with the source
  q.push(source);

  while (q.size() > 0) {
    char current = q.front();
    cout << current << endl;

    q.pop();

    for (char neighbor : graph[current]) {
      q.push(neighbor);
    }
  }
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

  bradthFirstPrint(graph, 'a');

  return 0;
}