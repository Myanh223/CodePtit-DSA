#include <bits/stdc++.h>

using namespace std;

int tinh(string s){
	int n = s.length();
	int max = 0;
	stack<char> st;
	for (int i = 0; i < n; i++){
		if (s[i] == '('){
			st.push(s[i]);
			int curr = st.size();
			if (curr > max){
				max = curr;
			}
		}
		else if(s[i] == ')'){
			if (st.empty()) return -1;
			st.pop();
		}
	}
	if (!st.empty()) return -1;
	return max;
}

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		string s; cin >> s;
		cout << tinh(s) << endl;
	}
	return 0;
}

