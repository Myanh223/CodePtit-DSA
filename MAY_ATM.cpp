#include <bits/stdc++.h>

using namespace std;

int n, s, a[101];
int min_coin;

void Try(int i, int sum, int cnt){
	if (cnt >= min_coin) return;
	if (sum == s){
		min_coin = min(min_coin, cnt);
		return;
	}
	if (i > n || sum > s) return;
	if (sum + a[i] <= s){
		Try(i + 1, sum + a[i], cnt + 1);
	}
	Try(i + 1, sum, cnt);
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n, greater<int>());
		min_coin = n + 1;
		Try(1, 0, 0);
		if (min_coin == n + 1) cout << -1 << endl;
		else cout << min_coin << endl;
	}
	return 0;
}