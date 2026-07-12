#include <bits/stdc++.h>

using namespace std;

int n, k, s, ans = 0;
int X[101];

void Init(){
	cin >> n >> k >> s;
}

void Try(int i){
	for (int j = X[i-1] + 1; j <= n - k + i; j++){
		X[i] = j;
		if (i == k){
			int sum = 0;
			for (int j = 1; j <= k; j++){
				sum += X[j];
			}
			if (sum == s) ++ans;
		}
		else Try(i + 1);
	}
}

int main(){
	while (1){
		Init();
		if (n + k + s == 0) break;
		ans = 0;
		Try(1);
		cout << ans << endl;
	}
	return 0;
}
