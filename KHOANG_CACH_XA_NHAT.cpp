#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			int l = i, r = n - 1;
			while (l < r){
				if (a[r] < a[l]){
					++l; --r;
				}
				else {
					cout << a[r] - a[l] << endl;
					break;
				}
			}
		}
	}
	return 0;
}