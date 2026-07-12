#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int i = curr.first;
        int j = curr.second;

       
        if (i == n && j == m) return dist[n][m];


        if (i + 1 <= n) {
            int step = abs(a[i][j] - a[i + 1][j]);
            if (step > 0 && i + step <= n && dist[i + step][j] == -1) {
                dist[i + step][j] = dist[i][j] + 1;
                q.push({i + step, j});
            }
        }

        if (j + 1 <= m) {
            int step = abs(a[i][j] - a[i][j + 1]);
            if (step > 0 && j + step <= m && dist[i][j + step] == -1) {
                dist[i][j + step] = dist[i][j] + 1;
                q.push({i, j + step});
            }
        }
        if (i + 1 <= n && j + 1 <= m) {
            int step = abs(a[i][j] - a[i + 1][j + 1]);
            if (step > 0 && i + step <= n && j + step <= m && dist[i + step][j + step] == -1) {
                dist[i + step][j + step] = dist[i][j] + 1;
                q.push({i + step, j + step});
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}