#include <bits/stdc++.h>

using namespace std;

int a[8][8];
bool cot[10], d1[10], d2[10];
int max_score;

void Try(int i, int sum){
	if (i == 8){
		max_score = max(max_score, sum);
		return;
	}
	for (int j = 0; j < 8; j++){
		if (!cot[j] && !d1[i - j + 8] && !d2[i + j - 1]){
			cot[j] = d1[i - j + 8] = d2[i + j - 1] = true;
			Try(i + 1, sum + a[i][j]);
			cot[j] = d1[i - j + 8] = d2[i + j - 1] = false;
		}
	}
}

int main(){
	int T; cin >> T;
	for (int t = 1; t <= T; t++){
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				cin >> a[i][j];
			}
		}
		memset(cot, false, sizeof(cot));
		memset(d1, false, sizeof(d1));
		memset(d2, false, sizeof(d2));
		max_score = 0;
		Try(0, 0);
		cout << max_score << endl;
	}
	return 0;
}