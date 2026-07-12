#include <bits/stdc++.h>

using namespace std;

bool check (const vector<int>& a, int n){
	for (int i = 1; i < n; i++){
		if (abs(a[i] - a[i - 1]) == 1){
			return false;
		}
	}
	return true;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			a[i] = i + 1;
		}
		do{
			if (check(a, n)){
				for (int x : a){
					cout << x;
				}
				cout << endl;
			}
		}
		while(next_permutation(a.begin(), a.end()));
		cout << endl;
	}
	return 0;
}