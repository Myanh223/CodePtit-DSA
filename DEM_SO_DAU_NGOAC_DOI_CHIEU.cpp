#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int n = s.length();
		stack<char> st;
		for (int i = 0; i < n; i++){
			if (s[i] == '(') st.push(s[i]);
			else{
				if (!st.empty() && st.top() == '(') st.pop();
				else st.push(s[i]);
			}
		}
		int a = 0, b = 0;
		while (!st.empty()){
			if (st.top() == '(') a++;
			else b++;
			st.pop();
		}
		cout << (a + 1)/2 + (b + 1)/2 << endl;
	}
	return 0;
}
