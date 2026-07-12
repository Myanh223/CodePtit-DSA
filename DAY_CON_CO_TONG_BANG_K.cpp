#include <bits/stdc++.h>

using namespace std;

int n, a[101], k, X[101], ans = 0;

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
}

void Try(int sum, int i, int pos){
	if (sum == k) {
		cout << "[";
		for (int j = 1; j < i; j++){
			cout << X[j];
			if (j == i - 1) cout << "] ";
			else cout << " ";
		}
		ans = 1;
		return;
	}
	for (int j = pos; j <= n; j++){
		if (sum + a[j] <= k){
			X[i] = a[j];
			Try(sum + a[j], i + 1, j + 1);
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		Init();
		ans = 0;
		Try(0, 1, 1);
		if (!ans) cout << -1 << endl;
		else cout << endl;
	}
}