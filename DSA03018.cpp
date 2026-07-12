#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int res4 = -1, res7 = -1;
		for (int b = n/7; b >= 0; b--){
			int remain = n - (b * 7);
			if (remain % 4 == 0){
				res4 = remain / 4;
				res7 = b;
				break;
			}
		}
		if (res4 != -1){
			for (int i = 0; i < res4; i++){
				cout << 4;
			}
			for (int i = 0; i < res7; i++){
				cout << 7;
			}
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	return 0;
}