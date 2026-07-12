#include <bits/stdc++.h>

using namespace std;

int n, cot[101], d1[101], d2[101], X[101], cnt = 0;

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (cot[j] == 0 && d2[i - j + n] == 0 && d1[i + j - 1] == 0){
			X[i] = j;
			cot[j] = d2[i - j + n] = d1[i + j - 1] = 1;
			if (i == n){
				cnt++;
			}
			else Try(i + 1);
			cot[j] = d1[i + j - 1] = d2[i - j + n] = 0;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		cnt = 0;
		memset(cot, 0, sizeof(cot));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		Try(1);
		cout << cnt << endl;
	}
	return 0;
}