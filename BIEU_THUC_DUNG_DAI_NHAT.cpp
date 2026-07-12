#include<bits/stdc++.h>

using namespace std;

int tinh(string s){
	stack<char> st;
	int res = 0;
	for(char c : s){
		if(c == '(')
			st.push(c);
		else{
			if(!st.empty()){
				st.pop();
				res+=2;
			}
		}
	}
	return res;
}

int main(){
	int t,n;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << tinh(s) << endl;
	}
	return 0;
}

