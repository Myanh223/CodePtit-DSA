#include <bits/stdc++.h>

using namespace std;

int priority(char op){
	if (op == '^') return 3;
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}

bool check(char op){
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') return true;
	else return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		string res = "";
		stack<char> st;
		for (int i = 0; i < s.length(); i++){
			if (isalnum(s[i])){
				res += s[i];
			}
			else if (s[i] == '('){
				st.push(s[i]);
			}
			else if (s[i] == ')'){
				while (!st.empty() && st.top() != '('){
					res += st.top();
					st.pop();
				}
				if (!st.empty()) st.pop();
			}
			else if (check(s[i])){
				while (!st.empty() && priority(st.top()) >= priority(s[i])){
					res += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
		while (!st.empty()){
			if (check(st.top())){
				res += st.top();
			}
			st.pop();
		}
		cout << res << endl;
	}
	return 0;
}