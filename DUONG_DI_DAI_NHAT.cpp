#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj[25][25];
bool vs[25][25];
int max_len;

void Try(int u, int len){
	max_len = max(max_len, len);
	for (int i = 0; i < n; i++){
		if (adj[u][i] > 0 && !vs[u][i]){
			vs[u][i] = vs[i][u] = true;
			Try(i, len + 1);
			vs[u][i] = vs[i][u] = false;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
		memset(vs, false, sizeof(vs));
		max_len = 0;
		for (int i = 0; i < m; i++){
			int u, v; cin >> u >> v;
			adj[u][v] = adj[v][u] = 1;
		}
		for (int i = 0; i < n; i++){
			Try(i, 0);
		}
		cout << max_len << endl;
	}
	return 0;
}