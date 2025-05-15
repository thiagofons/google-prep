#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;

		map<char, char> s_to_t;
		map<char, char> t_to_s;

		for (size_t i = 0; i < s.size(); ++i) {
			char s_char = s[i];
			char t_char = t[i];

			if (s_to_t.count(s_char) && s_to_t[s_char] != t_char)
				return false;

			if (t_to_s.count(t_char) && t_to_s[t_char] != s_char)
				return false;

			s_to_t[s_char] = t_char;
			t_to_s[t_char] = s_char;
		}

		return true;		
    }
};

int main () {
	Solution solution;

	string s = "paper";
	string t = "title";

	bool res = solution.isIsomorphic(s, t);

	cout << res << endl;

	return 0;
}