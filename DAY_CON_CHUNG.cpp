#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n, m, k; cin >> n >> m >> k;
		int a[n], b[m], c[k];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		for (int i = 0; i < k; i++) cin >> c[i];
		int i = 0, j = 0, k_ptr = 0;
		bool found = false;
		while (i < n && j < m && k_ptr < k){
			if (a[i] == b[j] && b[j] == c[k_ptr]){
				cout << a[i] << " ";
				found = true;
				++i; ++j; ++k_ptr;
			}
			else if(a[i] < b[j] || a[i] < c[k_ptr]){
				++i;
			}
			else if(b[j] < a[i] || b[j] < c[k_ptr]){
				++j;
			}
			else ++k_ptr;
		}
		if (!found){
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
}