#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int a[n], b[m];
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		sort(a, a + n);
		sort (b, b + m);
		vector<int> c;
		int i = 0, j = 0;
		while (i < n && j < m){
			if (a[i] <= b[j]){
				c.push_back(a[i]);
				++i;
			}
			else {
				c.push_back(b[j]);
				++j;
			}
		}
		while (i < n){
			c.push_back(a[i]);
			++i;
		}
		while (j < m){
			c.push_back(b[j]);
			++j;
		}
		for (int x : c) cout << x << " ";
		cout << endl;
	}
	return 0;
}