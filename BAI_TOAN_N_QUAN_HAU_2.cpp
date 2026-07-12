#include <bits/stdc++.h>

using namespace std;

int a[10][10], cot[10], d1[10], d2[10];
int max_sum;

void Try(int i, int sum){
	for (int j = 1; j <= 8; j++){
		if (cot[j] == 0 && d1[i + j - 1] == 0 && d2[i - j + 8] == 0){
			cot[j] = d1[i + j - 1] = d2[i - j + 8] = 1;
			if (i == 8){
				if (sum + a[i][j] > max_sum){
					max_sum = sum + a[i][j];
				}
			}
			else{
				Try(i + 1, sum + a[i][j]);
			}
			cot[j] = d1[i + j - 1] = d2[i - j + 8] = 0;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i = 1; i <= 8; i++){
			for (int j = 1; j <= 8; j++){
				cin >> a[i][j];
			}
		}
		memset(cot, 0, sizeof(cot));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		max_sum = 0;
		Try(1, 0);
		cout << max_sum << endl;
	}
	return 0;
}