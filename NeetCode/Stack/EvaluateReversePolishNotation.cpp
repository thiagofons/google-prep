#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<string> st;

    for (string token : tokens) {
      int first, second, result;

      if (token == "+" || token == "-" || token == "*" || token == "/") {
        second = stoi(st.top());
        st.pop();
        first = stoi(st.top());
        st.pop();
      }

      if (token == "+") {
        result = first + second;
        st.push(to_string(result));
      } 
      else if (token == "-") {
        result = first - second;
        st.push(to_string(result));
      } 
      else if (token == "*") {
        result = first * second;
        st.push(to_string(result));
      }
      else if (token == "/") {
        result = first / second;
        st.push(to_string(result));
      }
        
      else 
        st.push(token);
    }

    return stoi(st.top());
  }
};

int main() {
  Solution solution;
  vector<string> tokens = {"1","2","+","3","*","4","-"};

  int result = solution.evalRPN(tokens);

  cout << result << endl;

  return 0;
}
