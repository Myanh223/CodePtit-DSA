#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	for (int &x : a){
		cin >> x;
	}
	for (int i = 0; i < n - 1; i++){
		int min_pos = i;
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[min_pos]){
				min_pos = j;
			}
		}
		swap(a[i], a[min_pos]);
		cout << "Buoc " << i + 1 << " : ";
		for (int x : a) cout << x << " ";
		cout << endl;
	}
	return 0;
}