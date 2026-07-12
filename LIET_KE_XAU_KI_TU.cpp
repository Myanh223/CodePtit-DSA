#include <bits/stdc++.h>

using namespace std;

int n, k, X[101];
string a[101];
char c;

void Try(int i){
	for (int j = X[i - 1]; j <= n; j++){
		X[i] = j;
		if (i == k){
			for (int l = 1; l <= k; l++){
				cout << (char)('A' + X[l] - 1);
			}
			cout << endl;
		}
		else Try(i + 1);
	}
}

int main(){
	cin >> c >> k;
	n = (c - 'A') + 1;
	X[0] = 1;
	Try(1);
	return 0;
}