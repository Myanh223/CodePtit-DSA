#include <bits/stdc++.h>

using namespace std;

int n, k, X[101];
int cnt;

bool nt(int n){
	if (n == 0 || n == 1) return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

void Try(int i){
	for (int j = X[i - 1] + 1; j <= n - k + i; j++){
		X[i]= j;
		if (i == k){
			cnt++;
			if (nt(cnt)){
				cout << cnt << ": ";
				for (int l = 1; l <= k; l++){
					cout << X[l] << " ";
				}
				cout << endl;
			}
		}
		else{
			Try(i + 1);
		}
	}
}

int main(){
	cin >> n >> k;
	cnt = 0;
	Try(1);
	return 0;
}