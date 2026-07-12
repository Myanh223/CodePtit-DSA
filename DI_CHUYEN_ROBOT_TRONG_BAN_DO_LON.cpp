#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
    int xA, yA, xB, yB;
    cin >> xA >> yA >> xB >> yB;

    int n;
    cin >> n;
    set<ii> valid_cells;
    for (int i = 0; i < n; i++) {
        int x, y1, y2;
        cin >> x >> y1 >> y2;
        for (int y = y1; y <= y2; y++) {
            valid_cells.insert({x, y});
        }
    }
    map<ii, int> dist;
    queue<ii> q;

    q.push({xA, yA});
    dist[{xA, yA}] = 0;

    while (!q.empty()) {
        ii curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;
        int d = dist[curr];

        if (x == xB && y == yB) {
            cout << d << endl;
            return;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            ii next = {nx, ny};

            if (valid_cells.count(next) && dist.find(next) == dist.end()) {
                dist[next] = d + 1;
                q.push(next);
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}