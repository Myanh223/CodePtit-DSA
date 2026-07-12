#include <bits/stdc++.h>

using namespace std;

bool isUuThe2(string s) {
    int count2 = 0;
    for (char c : s) {
        if (c == '2') count2++;
    }
    return count2 > s.length() / 2;
}

void solve() {
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    q.push("2");

    int count = 0;
    while (count < n) {
        string s = q.front();
        q.pop();
        if (isUuThe2(s)) {
            cout << s << " ";
            count++;
        }
        q.push(s + "0");
        q.push(s + "1");
        q.push(s + "2");
    }
    cout << endl;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}