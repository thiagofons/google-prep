#include <vector>
#include <iostream>

using namespace std;

class MinStack {
private:
  vector<long int> items;

public:
    MinStack() {
      items = {};
    }
    
    void push(int val) {
      items.push_back(val);
    }
    
    void pop() {
      items.pop_back();
    }
    
    int top() {
      return items[items.size() - 1];
    }
    
    int getMin() {
      int min = items[0];

      for (int item: items) {
        if (item < min) min = item;
      }

      return min;
    }
};

int main () {
  MinStack minStack = MinStack();

  minStack.push(1);
  minStack.push(2);
  minStack.push(0);
  minStack.getMin(); // return 0
  minStack.pop();
  int top = minStack.top();    // return 2
  cout << top << endl;

  int min = minStack.getMin(); // return 1
  cout << min << endl;




  return 0;
}