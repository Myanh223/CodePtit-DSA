#include <bits/stdc++.h>

using namespace std;

bool dp[1005];

int main(){
	int t; cin >> t;
	while (t--){
		int n, s; cin >> n >> s;
		int a[n + 1];
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 0; i <= s; i++){
			dp[i] = false;
		}
		dp[0] = true;
		for (int i = 1; i <= n; i++){
			for (int j = s; j >= a[i]; j--){
				if (dp[j- a[i]]){
					dp[j] = true;
				}
			}
		}
		if(dp[s]){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}