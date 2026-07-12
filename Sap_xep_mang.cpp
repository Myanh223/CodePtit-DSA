#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		bool ok = true;
		sort(b, b + n);
		for (int i = 0; i < n; i++){
			if (a[i] != b[i] && a[i] != b[n - 1 - i]){
				ok = false;
				break;
			}
		}
		if (!ok) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}