#include <bits/stdc++.h>

using namespace std;

int sodu(string s, int n){
	int r = 0;
	for (char c : s){
		r = (r * 10 + (c - '0')) % n;
	}
	return r;
}

void xuly(int n){
	queue<string> Q;
	Q.push("1");
	while (!Q.empty()){
		string x = Q.front();
		Q.pop();
		if (sodu(x, n) == 0){
			cout << x << endl;
			break;
		}
		Q.push(x + "0");
		Q.push(x + "1");
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		xuly(n);
	}
	return 0;
}