#include <bits/stdc++.h>

using namespace std;

bool dp[1005];

int main(){
	int c, n; cin >> c >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[0] = true;
	for (int i = 1; i <= n; i++){
		for (int j = c; j >= a[i]; j--){
			if (dp[j - a[i]]){
				dp[j] = true;
			}
		}
	}
	for (int j = c; j >= 0; j--){
		if (dp[j]){
			cout << j << endl;
			break;
		}
	}
	return 0;
}