#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	int a[n], b[m];
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	int i = 0, j = 0;
	int cnt = 0;
	while (i < n && j < m){
		if (a[i] <= b[j]){
			++i;
		}
		else {
			cnt++;
			++i; ++j;
		}
	}
	cout << cnt << endl;
	return 0;
}