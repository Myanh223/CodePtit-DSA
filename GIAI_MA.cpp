#include <bits/stdc++.h>

using namespace std;

int dp[1005];

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		dp[0] = 1;
		dp[1] = 1;
		int n = s.length();
		if (s[0] == '0'){
			cout << 0 << endl;
			continue;
		}
		for (int i = 2; i <= n; i++){
			dp[i] = 0;
			if (s[i - 1] != '0'){
				dp[i] += dp[i - 1];
			}
			int val = (s[i-2] - '0') * 10 + (s[i - 1] - '0');
			if (val >= 10 && val <= 26){
				dp[i] += dp[i - 2];
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}