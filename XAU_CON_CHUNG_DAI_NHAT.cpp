#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int main(){
	int t; cin >> t;
	while (t--){
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 1; i <= s1.length(); i++){
			for (int j = 1; j <= s2.length(); j++){
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (s1[i - 1] == s2[j - 1]){
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[s1.length()][s2.length()] << endl;
	}
}