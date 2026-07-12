#include <bits/stdc++.h>

using namespace std;

int n, min_step = INT_MAX;

void Try(int i, int step){
	if (step >= min_step) return;
	if (i == 1){
		min_step = min(min_step, step);
		return;
	}
	if (i % 3 == 0){
		Try(i / 3, step + 1);
	}
	if (i % 2 == 0){
		Try(i / 2, step + 1);
	}
	Try(i - 1, step + 1);
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		min_step = n;
		Try(n, 0);
		cout << min_step << endl;
	}
	return 0;
}