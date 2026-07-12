#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int minStep(ii a, ii b){
    if (a.fi == b.fi && a.se == b.se) return 0;
    int visited[9][9];
    memset(visited, 0, sizeof(visited));

    queue<pair<ii, int>> q;
    q.push({a, 0});
    visited[a.fi][a.se] = 1;
    while (!q.empty()){
        pair<ii, int> t = q.front();
        q.pop();
        if (t.fi.fi == b.fi && t.fi.se == b.se) return t.se;

        for (int i = 0; i < 8; i++){
            int x = t.fi.fi + dx[i];
            int y = t.fi.se + dy[i];
            if (x >= 1 && x <= 8 && y >= 1 && y <= 8 && !visited[x][y]){
                visited[x][y] = 1;
                q.push({{x, y}, t.se + 1});
            }
        }
    }
    return -1;
}

int main(){
    int t; 
    if(!(cin >> t)) return 0;
    while (t--){
        string ST, EN;
        cin >> ST >> EN;
        ii a = {ST[0] - 'a' + 1, ST[1] - '0'};
        ii b = {EN[0] - 'a' + 1, EN[1] - '0'};
        cout << minStep(a, b) << endl;
    }
    return 0;
}