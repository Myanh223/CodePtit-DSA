#include <bits/stdc++.h>

using namespace std;

int N;
char board[105][105];
int dxM[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dyM[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dxV[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dyV[] = {1, 0, -1, 1, -1, 1, 0, -1};

vector<vector<int>> bfs(int sx, int sy, bool isKing) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        int x = curr.first, y = curr.second;

        int directions = isKing ? 8 : 8;
        for (int i = 0; i < 8; i++) {
            int nx = x + (isKing ? dxV[i] : dxM[i]);
            int ny = y + (isKing ? dyV[i] : dyM[i]);

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist;
}

int main() {
    cin >> N;
    pair<int, int> king;
    vector<pair<int, int>> knights;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'T') king = {i, j};
            else if (board[i][j] == 'M') knights.push_back({i, j});
        }
    }
    vector<vector<int>> distV = bfs(king.first, king.second, true);
    vector<vector<vector<int>>> allDistM;
    for (auto m : knights) {
        allDistM.push_back(bfs(m.first, m.second, false));
    }

    int minSteps = 1e9;
    bool possible = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '#') continue;
            
            int maxAtThisCell = distV[i][j];
            if (maxAtThisCell == -1) continue;

            bool canReach = true;
            for (auto& distM : allDistM) {
                if (distM[i][j] == -1) {
                    canReach = false;
                    break;
                }
                maxAtThisCell = max(maxAtThisCell, distM[i][j]);
            }

            if (canReach) {
                minSteps = min(minSteps, maxAtThisCell);
                possible = true;
            }
        }
    }

    if (!possible) cout << -1 << endl;
    else cout << minSteps << endl;

    return 0;
}