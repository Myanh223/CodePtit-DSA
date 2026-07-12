#include <bits/stdc++.h>

using namespace std;

int n, a[15][15];
bool ok;
vector<string> res;

void Try(int i, int j, string path){
	if (i == n && j == n){
		res.push_back(path);
		ok = true;
		return;
	}
	a[i][j] = 0;
	if (i + 1 <= n && a[i + 1][j] == 1){
		a[i + 1][j] = 0;
		Try(i + 1, j, path + "D");
		a[i + 1][j] = 1;
	}
	if (j - 1 > 0 && a[i][j - 1] == 1){
		a[i][j - 1] = 0;
		Try(i, j - 1, path + "L");
		a[i][j - 1] = 1;
	}
	if (i - 1 > 0 && a[i - 1][j] == 1){
		a[i - 1][j] = 0;
		Try(i - 1, j, path + "U");
		a[i - 1][j] = 1;
	}
	if (j + 1 <= n && a[i][j + 1] == 1){
		a[i][j + 1] = 0;
		Try(i, j + 1, path + "R");
		a[i][j + 1] = 1;
	}
	a[i][j] = 1;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		string path = "";
		res.clear();
		ok = false;
		if (a[1][1] == 0 || a[n][n] == 0){
			cout << -1 << endl;
			continue;
		}
		Try(1, 1, path);
		if (!ok) cout << -1 << endl;
		sort(res.begin(), res.end());
		for (auto x : res){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}