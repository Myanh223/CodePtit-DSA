#include <bits/stdc++.h>

using namespace std;

int kiemtra(string s){
	int n = s.length(); stack<char> st;
	for (int i = 0; i < n; i++){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
			st.push(s[i]);
		}
		else{
			if (st.empty()) return 0;
			else{
				char in = st.top(), out = s[i];
				if (in == '(' && out == ')') st.pop();
				else if (in == '{' && out == '}') st.pop();
				else if(in == '[' && out == ']') st.pop();
				else return 0;
			}
		}
	}
	return st.empty();
}

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		string s; cin >> s;
		if (kiemtra(s)) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}	