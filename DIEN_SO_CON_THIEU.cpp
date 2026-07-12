#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[10001] = {0};
		int l = INT_MAX, r = INT_MIN;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			l = min(l, x);
			r = max(r, x);
			a[x] = 1;
		}
		int res = 0;
		for (int i = l; i < r; i++){
			if (a[i] == 0){
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}