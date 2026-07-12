#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort (a, a + n);
		long long res = 0;
		for (int i = 0; i < n; i++){
			long long tmp = (a[i] * i) % MOD;
			res = (res + tmp) % MOD;
		}
		cout << res << endl;
	}
	return 0;
}