#include <bits/stdc++.h>

using namespace std;

int n, c[101][101], x[101]; 
int cmin = INT_MAX, ans = INT_MAX;
bool used[101];

void Try(int i, int cost){
	if (cost + (n - i + 1) * cmin >= ans) return;
	for (int j = 2; j <= n; j++){
		if (!used[j]){
			used[j] = true;
			x[i] = j;
			int sum = cost + c[x[i - 1]][j];
			
			if (i == n){
				ans = min(ans, sum + c[j][1]);
			}
			else{
				Try(i + 1, sum);
			}
			used[j] = false;
		}
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> c[i][j];
			if (i != j) cmin = min(cmin, c[i][j]);
		}
	}
	memset(used, false, sizeof(used));
	x[1] = 1;
	used[1] = true;
	Try(2, 0);
	cout << ans << endl;
}