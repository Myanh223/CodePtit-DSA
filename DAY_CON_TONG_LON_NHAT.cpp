#include <bits/stdc++.h>

using namespace std;

long long dp[100005];

int main(){
	int n, q; cin >> n >> q;
	long long a[n + 1];
	dp[0]= 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] > 0){
			dp[i] = dp[i - 1] + a[i];
		}
		else dp[i] = dp[i - 1];
	}
	while (q--){
		int l, r; cin >> l >> r;
		long long ans = dp[r] - dp[l - 1];
		cout << ans << endl;
	}
	return 0;
}