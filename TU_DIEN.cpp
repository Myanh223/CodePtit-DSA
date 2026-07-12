#include <bits/stdc++.h>

using namespace std;

int k, n, m;
char a[10][10];
string dic[101];
bool used[10][10];
bool found;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Init(){
	cin >> k >> m >> n;
	for (int i = 1; i <= k; i++){
		cin >> dic[i];
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}

void Try(int i, int j, string word, int idx){
	if (idx == word.length()){
		found = true;
		return;
	}
	for (int t = 0; t < 8; t++){
		int i_moi = i + dx[t];
		int j_moi = j + dy[t];
		
		if (i_moi >= 1 && i_moi <= m && j_moi >= 1 && j_moi <= n
		&& !used[i_moi][j_moi] && a[i_moi][j_moi] == word[idx]){
			used[i_moi][j_moi] = true;
			Try(i_moi, j_moi, word, idx + 1);
			if (found) return;
			used[i_moi][j_moi] = false;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		Init();
		vector<string> res;
		for (int i = 1; i <= k; i++){
			found = false;
			string target = dic[i];
			
			for (int r = 1; r <= m; r++){
				for (int c = 1; c <= n; c++){
					if (a[r][c] == target[0]){
						memset(used, false, sizeof(used));
						used[r][c] = true;
						Try(r, c, target, 1);
						if (found) break;
					}
				}
				if (found) break;
			}
			if (found) res.push_back(target);
		}
		if (res.empty()) cout << -1;
		else{
			for (string s : res) cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}