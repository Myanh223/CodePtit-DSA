#include <bits/stdc++.h>

using namespace std;

int dp[1000001];

int main(){
	int n, s; cin >> n >> s;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= s; i++){
		dp[i] = 1e9;
		for (int c : a){
			if (i >= c){
				dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
	}
	cout << dp[s] << endl;
	return 0;
}