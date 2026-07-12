#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int a[n], dp[n];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < i; j++){
			if (a[i] > a[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp + 1, dp + 1 + n) << endl;
	return 0;
}