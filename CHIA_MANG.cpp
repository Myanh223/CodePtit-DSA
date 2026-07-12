#include <bits/stdc++.h>

using namespace std;

int n, k, a[101], target;
bool ok;
bool used[101];

void Try(int cnt, int sum, int i){
	if (ok) return;
	if (cnt == k){
		ok = true;
		return;
	}
	if (sum == target){
		Try(cnt + 1, 0, 1);
		return;
	}
	for (int j = i; j <= n; j++){
		if (!used[j] && sum + a[j] <= target){
			used[j] = true;
			Try(cnt, sum + a[j], j + 1);
			used[j] = false;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		int sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}
		if (sum % k != 0){
			cout << 0 << endl;
		}
		else{
			target = sum / k;
			ok = false;
			memset(used, false, sizeof(used));
			
			sort(a + 1, a + 1 + n, greater<int>());
			if (a[1] > target) cout << 0 << endl;
			else{
				Try(0, 0, 1);
				if (ok) cout << 1 << endl;
				else cout << 0 << endl;
			}
		}
	}
	return 0;
}