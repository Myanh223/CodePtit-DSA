#include <bits/stdc++.h>

using namespace std;

long long n, res;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void Try(int idx, long long val, long long uoc){
	if (uoc > n) return;
	if (uoc == n){
		res = min(res, val);
		return;
	}
	for (int i = 1; i <= 60; i++){
		if (val > res/prime[idx]) break;
		val *= prime[idx];
		Try(idx + 1, val, uoc * (i + 1));
		if (uoc * (i + 1) > n) break;
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		res = 2e18;
		Try(0, 1, 1);
		cout << res << endl;
	}
	return 0;
}