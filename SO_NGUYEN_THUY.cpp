#include <bits/stdc++.h>

using namespace std;

string taoso(string s){
	string rev = s;
	reverse(rev.begin(), rev.end());
	return s + rev;
}

void xuly(int n){
	queue<string> Q;
	Q.push("4");
	Q.push ("5");
	int cnt = 0;
	while (cnt < n){
		string s = Q.front();
		Q.pop();
		cout << taoso(s) << " ";
		cnt++;
		Q.push(s + "4");
		Q.push(s + "5");
	}
	cout << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		xuly(n);
	}
	return 0;
}