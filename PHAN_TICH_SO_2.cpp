#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> res;
vector<vector<int>> final;

void Try(int limit, int sum){
	if(sum == n){
		final.push_back(res);
		return;
	}
	for (int j = limit; j <= n; j++){
		if (sum + j <= n){
			res.push_back(j);
			Try(j, sum + j);
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
		cin >> n;
		res.clear();
		final.clear();
		Try(1, 0);
		cout << final.size() << endl;
		for (auto v : final){
			cout << "(";
			for (int i = 0; i < v.size(); i++){
				cout << v[i];
				if (i == v.size() - 1) cout << ") ";
				else cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}