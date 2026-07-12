#include <bits/stdc++.h>
using namespace std;

int x[9]; 
int digits[] = {0, 2};
set<string> res; 

void check() {

    if (x[1] != x[8] || x[2] != x[7] || x[3] != x[6] || x[4] != x[5]) return;

    int d = x[1] * 10 + x[2];
    int m = x[3] * 10 + x[4];
    int y = x[5] * 1000 + x[6] * 100 + x[7] * 10 + x[8];

    if (x[5] == 0) return;

    if (m < 1 || m > 12) return;

    if (d < 1 || d > 31) return; 
    if (m == 2 && d > 29) return;

    string s = "";
    s += to_string(x[1]) + to_string(x[2]) + "/";
    s += to_string(x[3]) + to_string(x[4]) + "/";
    s += to_string(x[5]) + to_string(x[6]) + to_string(x[7]) + to_string(x[8]);
    res.insert(s);
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = digits[j];
        if (i == 8) {
            check();
        } else Try(i + 1);
    }
}

int main() {
    Try(1);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}