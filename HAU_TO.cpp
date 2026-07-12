#include <bits/stdc++.h>

using namespace std;

bool check(string c){
	return (c == "+" || c == "-" || c == "*" || c == "/");
}

long long tinh(long long v2, long long v1, string op){
	if (op == "+") return v2 + v1;
	if (op == "-") return v2 - v1;
	if (op == "*") return v2 * v1;
	if (op == "/") return v2 / v1;
	return 0;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		stack<long long> st;
		for (int i = 0; i < n; i++){
			string op; cin >> op;
			
			if (!check(op)){
				st.push(stoll(op));
			}
			else{
				long long v1 = st.top();
				st.pop();
				long long v2 = st.top();
				st.pop();
				long long res = tinh(v2, v1, op);
				st.push(res);
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}