#include <bits/stdc++.h>

using namespace std;

int main(){
	int q; cin >> q;
	queue<int> Q;
	while (q--){
		string s; cin >> s;
		if (s == "PUSH"){
			int x; cin >> x;
			Q.push(x);
		}
		else if (s == "PRINTFRONT"){
			if (!Q.empty()) cout << Q.front() << endl;
			else cout << "NONE" << endl;
		}
		else if (s == "POP"){
			if (!Q.empty()) Q.pop();
		}
	}
}