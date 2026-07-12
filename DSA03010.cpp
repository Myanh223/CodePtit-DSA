#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		priority_queue<int, vector<int>, greater<int>> Q;
		int n; cin >> n;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			Q.push(x);
		}
		int ans = 0;
		while (Q.size() > 1){
			int x = Q.top();
			Q.pop();
			int y = Q.top();
			Q.pop();
			ans += (x + y);
			Q.push(x + y);
		}
		cout << ans << endl;
	}
	return 0; 
}