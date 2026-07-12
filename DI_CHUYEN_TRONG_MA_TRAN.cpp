#include <bits/stdc++.h>

using namespace std;

int A[1001][1001];
int C[1001][1001];
int N, M;

void xuly(){
	queue<pair<int, int>> Q;
	memset(C, -1, sizeof(C));
	Q.push({1, 1});
	C[1][1] = 0;
	while (!Q.empty()){
		pair<int, int> t = Q.front();
		Q.pop();
		
		int i = t.first;
		int j = t.second;
		
		int x = A[i][j];
		if (j + x <= M && C[i][j + x] == -1){
			C[i][j + x] = C[i][j] + 1;
			Q.push({i, j + x});
		}
		if (i + x <= N && C[i + x][j] == -1){
			C[i + x][j] = C[i][j] + 1;
			Q.push({i + x, j});
		}
		if (C[N][M] != -1) break;
	}
	cout << C[N][M] << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> N >> M;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= M; j++){
				cin >> A[i][j];
			}
		}
		xuly();
	}
	return 0;
} 