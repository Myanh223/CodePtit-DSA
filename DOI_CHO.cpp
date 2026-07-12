#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int l, int r){
	int pivot = a[l];
	int i = l - 1, j = r + 1;
	while (true){
		do{
			++i;
		}while (a[i] < pivot);
		do{
			--j;
		}while (a[j] > pivot);
		if (i >= j) return j;
		swap(a[i], a[j]);
		cout << i + 1 << " " << j + 1 << endl;
	}
}

void qs (int a[], int l, int r){
	while (l < r){
		int p = partition(a, l, r);
		qs(a, l , p);
		qs(a, p + 1, r);
	}
}

int main(){
	int n; cin >> n;
	int a[n];
	for (int &x : a) cin >> x;
	qs(a, 0, n- 1);
	return 0;
}