#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		sort(a, a + n);
		int l = 0, r = n - 1;
		while (l < r){
			for (int i = l; i < r; i++){
				cout << a[r] << " " << a[l] << " ";
				++l; --r;
			}
		}
		if (l == r) cout << a[l] << endl;
	}
	return 0;
}