#include <bits/stdc++.h>

using namespace std;

bool check(string op){
	if (op == "+" || op == "-" || op == "*" || op == "/") return true;
	else return false;
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
		for (int i = 0; i < n; i++){
			string s; cin >> s;
			if (!check(s)){
				st.push(stoll(s));
			}
			else{
				long long t1 = st.top(); st.pop();
				long long t2 = st.top(); st.pop();
				long long res = tinh(t2, t1, s);
				st.push(res);
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}