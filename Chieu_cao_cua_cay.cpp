#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[1001];
bool visited[1001];
int height[1001];

void Init(){
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u, int par){
	visited[u] = true;
	if (par != 0){
		height[u] = height[par] + 1;
	}
	else{
		height[u] = 0;
	}
	for (int v : adj[u]){
		if (!visited[v]){
			dfs(v, u);
		}
	}
}

int main(){
	Init();
	dfs(1, 0);
	for (int i = 1; i <= n; i++){
		cout << height[i] << " ";
	}
	cout << endl;
	return 0;
}