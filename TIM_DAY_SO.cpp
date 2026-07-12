#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	int max_val = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		max_val = max(max_val, a[i]);
	}
	int min_sum = INT_MAX;
	for (int k = 1; k <= max_val; k++){
		int curr_sum = 0;
		bool possible = true;
		for (int i = 0; i < n; i++){
			int b_min = a[i] / (k + 1) + 1;
			if (a[i] / b_min == k){
				curr_sum += b_min;
			}
			else{
				possible = false;
				break;
			}
		}
		if (possible){
			min_sum = min(min_sum, curr_sum);
		}
	}
	cout << min_sum << endl;
	return 0;
}