#include <bits/stdc++.h>

using namespace std;
int money[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
	int t; cin >> t;
	sort(money, money + 10, greater<int>());
	while (t--){
		int n; cin >> n;
		int cnt = 0;
		for (int i = 0; i < 10; i++){
			if (n >= money[i]){
				cnt += n / money[i];
				n %= money[i];
			}
		}
		cout << cnt << endl;
	}	
	return 0;
}