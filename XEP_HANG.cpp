#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int end_t = a[0].first + a[0].second;
	for (int i = 1; i < n; i++){
		end_t = max(end_t, a[i].first) + a[i].second;
	}
	cout << end_t << endl;
	return 0;
}