#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		int k; cin >> k;
		string s; cin >> s;
		map<char, int> mp;
		for (char c : s){
			mp[c]++;
		}
		priority_queue<int> Q;
		for (auto it : mp){
			Q.push(it.second);
		}
		while (k--){
			int top = Q.top();
			Q.pop();
			top--;
			Q.push(max(top, 0));
		}
		long long res = 0;
		while (!Q.empty()){
			res += Q.top() * Q.top();
			Q.pop();
		}
		cout << res << endl;
	}
	return 0;
}