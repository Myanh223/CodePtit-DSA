#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void Init(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

bool dfs(int u, int par){
	visited[u] = true;
	for (int v : adj[u]){
		if (!visited[v]){
			if (dfs(v, u)) return true;
		}
		//v ko phai la cha truc tiep cua u
		else if(v != par){
			return true;
		}
	}
	return false;
}

int main(){
	Init();
	bool ok = false;
	for (int i = 1; i <= n; i++){
		if (!visited[i] && dfs(i, 0)){
			ok = true;
			break;
		}
	}
	cout << ok << endl;
	return 0;
}

