#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int min_sum = a[0] + a[1];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int current_sum = a[i] + a[j];
            
            if (abs(current_sum) < abs(min_sum)) {
                min_sum = current_sum;
            }
        }
    }
    cout << min_sum << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}