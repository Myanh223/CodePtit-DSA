#include <bits/stdc++.h>

using namespace std;

int n, k, X[101], m;
vector<string> name;

void Try(int i){
	for (int j = X[i - 1] + 1; j <= m - k + i; j++){
		X[i] = j;
		if (i == k){
			for (int l = 1; l <= k; l++){
				cout << name[X[l] - 1] << " ";
			}
			cout << endl;
		}
		else Try(i + 1);
	}
}

int main(){
	cin >> n >> k;
	set<string> s;
	for (int i = 1; i <= n; i++){
		string x; cin >> x;
		s.insert(x);
	}
	for (auto x : s){
		name.push_back(x);
	}
	m = name.size();
	Try(1);
	return 0;
}