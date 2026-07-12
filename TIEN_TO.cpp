#include <bits/stdc++.h>

using namespace std;

bool check(string s){
	return (s == "+" || s == "-" || s == "*" || s == "/");
}

long long tinh(long long v1, long long v2, string op){
	if (op == "+") return v1 + v2;
	if (op == "-") return v1 - v2;
	if (op == "*") return v1 * v2;
	if (op == "/") return v1 / v2;
	return 0;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		stack<long long> st;
		string s[n];
		for (int i = 0; i < n; i++){
			cin >> s[i];
		}
		for (int i = n - 1; i >= 0; i--){
			if (!check(s[i])){
				st.push(stoll(s[i]));
			}
			else{
				long long v1 = st.top();
				st.pop();
				long long v2 = st.top();
				st.pop();
				long long res = tinh(v1, v2, s[i]);
				st.push(res);
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}