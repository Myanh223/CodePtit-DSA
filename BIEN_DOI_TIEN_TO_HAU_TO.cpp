#include <bits/stdc++.h>

using namespace std;

bool check(char op){
	if (op == '+' || op == '-' || op == '*' || op == '/') return true;
	else return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		stack<string> st;
		for (int i = s.length() - 1; i >= 0; i--){
			if (!check(s[i])){
				st.push(string(1, s[i]));
			}
			else{
				string t1 = st.top(); st.pop();
				string t2 = st.top(); st.pop();
				string tmp = t1 + t2 + s[i];
				st.push(tmp);
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}