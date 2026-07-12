#include <bits/stdc++.h>

using namespace std;

int n, p, s, cnt = 0;
vector<int> res;
vector<vector<int>> final;

bool nt(int n){
	if (n == 0 || n == 1) return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

void Try(int i, int sum, int last){
	if (i == n){
		if (sum == s){
			final.push_back(res);
		}
		return;
	}
	for (int j = last + 1; j <= s - sum; j++){
		if (nt(j)){
			res.push_back(j);
			Try(i + 1, sum + j, j);
			res.pop_back();
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> p >> s;
		res.clear();
		final.clear();
		Try(0, 0, p);
		cout << final.size() << endl;
		for (auto v : final){
			for (int x : v){
				cout << x << " ";
			}
			cout << endl;
		}
	}
	return 0;
}