#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		if (s.size() <= 1) {
			return false;
		}

		unordered_map<char, char> map = {
			{')', '('},
			{'}', '{'},
			{']', '['}
		};

		stack<char> st;

		for (char c : s) {
			switch (c) {
				case '(':
				case '{':
				case '[':
					st.push(c);
					continue;
				case ')':
				case '}':
				case ']':				
					if (st.empty()) {
						return false;
					}	

					if (map[c] == st.top()) {
						st.pop();
						continue;
					}
					return false;
				default:
					continue;
			}
		}

		if (st.empty()) {
			return true;
		}
		return false;

    }
};

int main() {
	Solution solution;
	string test1 = ")(){}";
	string test2 = "(])";
	string test3 = "(]";
	string test4 = "([)]";
	string test5 = "{[]}";

	cout << boolalpha;
	cout << "Test 1: " << solution.isValid(test1) << endl; // false
	cout << "Test 2: " << solution.isValid(test2) << endl; // false
	cout << "Test 3: " << solution.isValid(test3) << endl; // false
	cout << "Test 4: " << solution.isValid(test4) << endl; // false
	cout << "Test 5: " << solution.isValid(test5) << endl; // true

	return 0;
}

