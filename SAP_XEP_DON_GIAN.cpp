#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> pos(n + 1);
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		pos[x] = i;
	}
	int max_len = 1;
	int curr_len = 1;
	for (int i = 2; i <= n; i++){
		if (pos[i] > pos[i - 1]){
			curr_len++;
		}
		else{
			curr_len = 1;
		}
		max_len = max(max_len, curr_len);
	}
	cout << n - max_len << endl;
	return 0;
}