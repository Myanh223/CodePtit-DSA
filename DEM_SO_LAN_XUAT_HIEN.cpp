#include <bits/stdc++.h>

using namespace std;

int dautien(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while (l <= r){
		int m = (l + r)/2;
		if (a[m] == x){
			res = m + 1;
			r = m - 1;
		}
		else if (a[m] < x) l = m + 1;
		else r = m - 1;
	}
	return res;
}

int cuoicung(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1;
	while (l <= r){
		int m = (l + r)/2;
		if (a[m] == x){
			res = m;
			l = m + 1;
		}
		else if(a[m] < x) l = m + 1;
		else r = m - 1;
	}
	return res;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n, x; cin >> n >> x;
		int a[n];
		for (int &x : a) cin >> x;
		int dau = dautien (a, n, x);
		int cuoi = cuoicung(a, n, x);
		if (dau != -1){
			cout << cuoi - dau + 1 << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}