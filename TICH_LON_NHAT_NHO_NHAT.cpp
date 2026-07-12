#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int a[n], b[m];
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		int min = *min_element(b, b + m);
		int max = *max_element(a, a + n);
		cout << 1LL * min * max << endl;
	}
	return 0;
}