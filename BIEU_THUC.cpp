#include <bits/stdc++.h>

using namespace std;

int a[5];
bool found;

void Try(int i, int val){
	if (found) return;
	if (i == 5){
		if (val == 23){
			found = true;
		}
		return;
	}
	Try(i + 1, val + a[i]);
	Try(i + 1, val - a[i]);
	Try(i + 1, val * a[i]);
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i = 0; i < 5; i++){
			cin >> a[i];
		}
		sort(a, a + 5);
		found = false;
		do{
			Try(1, a[0]);
			if (found) break;
		}while (next_permutation(a, a + 5));
		if (!found) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}