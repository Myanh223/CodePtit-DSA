#include <bits/stdc++.h>

using namespace std;

bool solve(){
	int n, k, t; cin >> n >> k >> t;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	multiset<int> ms;
	for (int j = 0; j < k; j++){
		//Kiem tra xem trong ms co phan tu a[i] >= a[j] - t ko
		auto it = ms.lower_bound(a[j] - t);
		if (it != ms.end() && (*it <= a[j] + t)){
			return true;
		}
		ms.insert(a[j]);
	}
	for (int j = k; j < n; j++){
		ms.erase(ms.find(a[j-k]));
		auto it = ms.lower_bound(a[j] - t);
		if (it != ms.end() && (*it <= a[j] + t)){
			return true;
		}
		ms.insert(a[j]);
	}
	return false;
}

int main(){
	int T; cin >> T;
	while (T--){
		if (solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}