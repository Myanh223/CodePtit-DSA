#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> chan, le;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		if ((i + 1) % 2 == 0) chan.push_back(x);
		else le.push_back(x);
	}
	sort(chan.begin(), chan.end(), greater<int>());
	sort(le.begin(), le.end());
	int i = 0, j = 0;
	for (int k = 0; k < n; k++){
		if ((k + 1) % 2 == 0){
			cout << chan[i] << " ";
			++i;
		}
		else {
			cout << le[j] << " ";
			++j;
		}
	}
	return 0;
}