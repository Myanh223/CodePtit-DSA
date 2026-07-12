#include <bits/stdc++.h>

using namespace std;

/*y tuong: su dung phuong phap chia va tri, chia day ban dau thanh cac day con
cho toi khi day chi con 1 phan tu, sau do thuc hien tron 2 day con tang dan 
thanh 1 day tang dan voi do phuc tap tuyen tinh
*/

// tron: o moi buoc, so sanh a[i] voi b[j] xem cai nao nho hon, roi tang chi so len
void merge(int a[], int l, int m, int r){
	vector <int> x(a + l, a + m + 1);
	vector <int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while (i < x.size() && j < y.size()){
		if (x[i] <= y[j]){
			a[l] = x[i]; ++l; ++i;
		}
		else{
			a[l] = y[j]; ++l; ++j;
		}
	}
	while (i < x.size()){
		a[l] = x[i]; ++l; ++i;
	}
	while (j < y.size()){
		a[l] = y[j]; ++l; ++j;
	}
}

void MergeSort(int a[], int l, int r){
	if (l >= r) return;
	int m = (l + r)/2;
	MergeSort(a, l, m);
	MergeSort(a, m + 1, r);
	merge(a, l, m, r);
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		MergeSort(a, 0, n - 1);
		for (int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}