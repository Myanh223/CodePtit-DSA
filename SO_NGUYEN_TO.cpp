#include <bits/stdc++.h>

using namespace std;

int nt(int n){
	if (n == 0 || n == 1) return 0;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return 0;
	}
	return n > 1;
}

int n, p, s, X[101];
vector<int> nto;
vector<vector<int>> res;

void Init(){
	cin >> n >> p >> s;
	nto.clear();
	res.clear();
	for(int i = p + 1; i <= s; i++){
		if (nt(i)){
			nto.push_back(i);
		}
	}
}

void Try(int i, int sum, int pos){
	if (i == n && sum == s){
		vector<int> tmp(X, X + n);
		res.push_back(tmp);
	}
	else{
		for (int j = pos; j < nto.size(); j++){
			if (sum + nto[j] <= s){
				X[i] = nto[j];
				Try(i + 1, sum + nto[j], j + 1);
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		Init();
		Try(0, 0, 0);
		cout << res.size() << endl;
		for (auto it : res){
			for (int x : it){
				cout << x << " ";
			}
			cout << endl;
		}
	}
}