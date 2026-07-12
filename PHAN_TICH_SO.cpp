#include <bits/stdc++.h>

using namespace std;

int n, x, a[101];
vector<int> res;
vector<vector<int>> final;

void Try(int i, int sum){
	if (sum == x){
		final.push_back(res);
		return;
	}
	for (int j = i; j < n; j++){
		if (sum + a[j] <= x){
			res.push_back(a[j]);
			Try(j, sum + a[j]);
			res.pop_back();
		}
		else{
			break;
		}
	}
}

int main(){
	int t; cin >> t; 
	while (t--){
		cin >> n >> x;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		res.clear();
		final.clear();
		Try(0, 0);
		if (final.empty()) cout << -1 << endl;
		else{
			for (auto v : final){
				cout << "[";
				for (int i = 0; i < v.size(); i++){
					cout << v[i];
					if (i == v.size() - 1) cout << "] ";
					else cout << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}