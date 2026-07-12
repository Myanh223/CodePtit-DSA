#include <bits/stdc++.h>

using namespace std;

int n, a[101];
bool ok;

void Try(int i, int target, int sum){
	if (ok) return;
	if (sum == target){
		ok = true;
		return;
	}
	for (int j = i; j <= n; j++){
		if (sum + a[j] <= target){
			Try(j + 1, target, sum + a[j]);
		}
		if (ok) return;
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		ok = false;
		int sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}
		sort(a + 1, a + 1 + n, greater<int>());
		if (sum % 2 != 0){
			cout << "NO" << endl;
			continue;
		}
		int target = sum /2;
		Try(1, target, 0);
		if (!ok) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}

