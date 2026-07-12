#include <bits/stdc++.h>

using namespace std;

int in[1001], level[1001], mark[1001];
int n;

void inp(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> in[i];
		mark[in[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		cin >> level[i];
	}
}

void posOrder(int l, int r){
	if (l > r) return;
	else if (l == r){
		cout << in[l] << " ";
	}
	else{
		int pos;
		for (int i = 1; i <= n; i++){
			if (mark[level[i]] >= l && mark[level[i]] <= r){
				pos = level[i];
				break;
			}
		}
		pos = mark[pos];
		posOrder(l, pos - 1);
		posOrder(pos + 1, r);
		cout << in[pos] << " ";
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
		posOrder(1, n);
		cout << endl;
	}
	return 0;
}