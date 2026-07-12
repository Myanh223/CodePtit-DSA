#include <bits/stdc++.h>

using namespace std;

int cnt[5];

int dem(int y[], int m, int x){
	if (x == 0) return 0;
	if (x == 1) return cnt[0];
	auto it = upper_bound(y, y + m, x);
	long long res = (y + m) - it;
	res += (cnt[0] + cnt[1]);
	if (x == 2) res -= (cnt[3] + cnt[4]);
	if (x == 3) res += cnt[2];
	return res;
}
int main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int a[n], b[m];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
			if (b[i] <= 4) cnt[b[i]]++;
		}
		sort(b, b + m);
		long long ans = 0;
		for (int x : a){
			ans += dem(b, m, x);
		}
		cout << ans << endl;
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}