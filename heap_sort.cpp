#include <bits/stdc++.h>

using namespace std;

//heap: la 1 cay nhi phan hoan chinh
// tinh chat: node o goc luon lon hon cac con (maxheap) nguoc lai laf (minheap)

/* Heapify: tao ra 1 maxheap -> ktao chi so lon nhat -> tinh ra 2 chi so con
-> ktra lieu rang 2 con < cha -> cap nhat chi so phan tu lon nhat = cha
-> neu ko thi swap -> dam bao cha luon lon hon con
*/

//tu tuong: xay dung maxheap -> swap ptu goc voi ptu cuoi cung trong cay hien tai
/*cach lam: 
buoc 1: xay dung max heap
buoc 2: hoan doi: loai bo phan tu goc va dat o cuoi mang
buoc 3: giam kich thuoc cua heap di 1
buoc 4: heapify lai phan tu goc de chung ta co phan tu cao nhat o goc
buoc 5: qua trinh lap lai den khi het ds dc sap xep
*/

void heapify (int a[], int n, int i){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	
	if (l < n && a[l] > a[largest]){
		largest = l;
	}
	if (r < n && a[r] > a[largest]){
		largest = r;
	}
	if (largest != i){
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapsort(int a[], int n){
	//Xay dung maxheap
	for (int i = n /2 - 1; i >= 0; i--){
		heapify(a, n, i);
	}
	// doi cho va giam kich thuoc cua heap di 1
	for (int i = n - 1; i >= 0; i--){
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}
int main(){
	int n; cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}	
	heapsort(a, n);
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}