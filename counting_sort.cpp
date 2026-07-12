#include <bits/stdc++.h>

using namespace std;

//y tuong: dem tan suat xuat hien cua cac so -> in ra so lan xuat hien cua no theo thu tu tang dan

int cnt[10000001];
int main(){
	int a[1000], n;
	cin >> n;
	int m = INT_MIN;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
		m = max(m, a[i]);
	}
	for (int i = 0; i <= m; i++){
		if (cnt[i] != 0){
			for (int j = 0; j < cnt[i]; j++){
				cout << i << " ";
			}
		}
	}
	return 0;
}