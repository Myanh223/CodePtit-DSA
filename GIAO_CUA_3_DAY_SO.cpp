#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		int a[n1], b[n2], c[n3];
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		for (int &x : c) cin >> x;
		vector<int> giao;
		int i = 0, j = 0, k = 0;
		while (i < n1 && j < n2 && k < n3){
			if (a[i] == b[j] && b[j] == c[k]){
				giao.push_back(a[i]);
				++i; ++j; ++k;
			}
			else if(a[i] <= b[j] && a[i] <= c[k]){
				++i;
			}
			else if (b[j] <= a[i] && b[j] <= c[k]){
				++j;
			}
			else if (c[k] <= a[i] && c[k] <= b[j]){
				++k;
			}
		}
		if (giao.size() == 0){
			cout << -1 << endl;
		}
		for (int x : giao) cout << x << " ";
		cout << endl;
	}
	return 0;
}