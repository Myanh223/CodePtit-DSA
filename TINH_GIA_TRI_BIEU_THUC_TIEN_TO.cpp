#include <bits/stdc++.h>

using namespace std;

bool check(char op){
	if (op == '+' || op == '-' || op == '*' || op == '/') return true;
	else return false;
}

int tinh(int v1, int v2, char op){
	if (op == '+') return v1 + v2;
	if (op == '-') return v1 - v2;
	if (op == '*') return v1 * v2;
	if (op == '/') return v1 / v2;
	return 0;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		stack<int> st;
		for (int i = s.length() - 1; i >= 0; i--){
			if (!check(s[i])){
				st.push(s[i] - '0');
			}
			else{
				int t1 = st.top(); st.pop();
				int t2 = st.top(); st.pop();
				int res = tinh(t1, t2, s[i]);
				st.push(res);
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}