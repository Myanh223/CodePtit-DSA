#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int main(){
	int n, v; cin >> n >> v;
	int w[n + 1], c[n + 1];
	for (int i = 1; i <= n; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= v; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
			}
		}
	}
	cout << dp[n][v] << endl;
	return 0;
}