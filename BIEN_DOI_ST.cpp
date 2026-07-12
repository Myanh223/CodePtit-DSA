#include <bits/stdc++.h>

using namespace std;

int biendoi(int s, int t){
	int a[20001] = {0};
	queue<int> Q;
	Q.push(s);
	while (a[t] == 0){
		int x = Q.front();
		Q.pop();
		if (x - 1 > 0 && a[x-1] == 0){
			a[x-1] = a[x] + 1;
			Q.push(x-1);
		}
		if(x * 2 < 20000 && a[x * 2] == 0){
			a[x * 2] = a[x] + 1;
			Q.push(x*2);
		}
	}
	return a[t];
}

int main(){
	int test, s, t;
	cin >> test;
	while (test--){
		cin >> s >> t;
		cout << biendoi(s, t) << endl;
	}
	return 0;
}