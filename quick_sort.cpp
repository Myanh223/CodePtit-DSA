#include <bits/stdc++.h>

using namespace std;

/*tu tuong: chia va tri. Phan hoach 

- phan hoach lomuto: lay pivot la phan tu cuoi cung
->  
- phan hoach hoare: chon chot la phan tu dau tien, tim cap nghich the 
- pivot: chot
*/

//lomuto
int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++){
		if (a[j] <= pivot){
			++i;
			swap(a[i], a[j]);
		}
	}
	//dua chot ve giua
	++i;
	swap(a[i], a[r]);
	return i; //vi tri
}

//hoare
int partition2 (int a[], int l, int r){
	int pivot = a[l];
	int i = l - 1, j = r + 1;
	while (1){
		do{
			++i;
			
		}while (a[i] < pivot);
		do{
			--j;
		}while(a[j] > pivot);
		if (i < j){
			swap(a[i], a[j]);
		}
		else return j;
	}
}

void quicksort(int a[], int l, int r){
	if (l >= r) return;
	int p = partition2(a, l, r);
	quicksort(a, l, p);
	quicksort(a, p + 1, r);
}

int main(){
	int a[1000], n; cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		a[i] = rand() % 1000;
	}
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}