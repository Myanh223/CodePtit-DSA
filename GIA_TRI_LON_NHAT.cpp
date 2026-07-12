#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<long long> b(n);
	for (int i = 0; i < n; i++){
		long long x; cin >> x;
		if (x > 0){
			b[i] = 2 * x;
		}
		else{
			b[i] = 0;
		}
	}
	long long max_sum = 0;
	long long curr_sum = 0;
	for (int i = 0; i < n; i++){
		curr_sum += b[i];
		if (curr_sum > max_sum){
			max_sum = curr_sum;
		}
		if (curr_sum < 0){
			curr_sum = 0;
		}
	}
	cout << max_sum << endl;
	return 0;
}