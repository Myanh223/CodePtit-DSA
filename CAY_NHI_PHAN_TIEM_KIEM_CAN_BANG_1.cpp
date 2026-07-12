#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n + 1];
		int m = n / 2;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		if (n % 2 == 0){
			cout << a[m] << endl;
		}
		else{
			cout << a[m + 1] << endl;
		}
	}
	return 0;
}