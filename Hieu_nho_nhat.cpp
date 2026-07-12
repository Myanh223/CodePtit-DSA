#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		int a[n];
		int total = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			total += a[i];
		}
		sort(a, a + n);
		int min_e = min(k, n - k);
		int s1 = 0, s2 = 0;
		for (int i = 0; i < min_e; i++){
			s1 += a[i];
		}
		s2 = total - s1;
		cout << s2 - s1 << endl;
	}
	return 0;
}