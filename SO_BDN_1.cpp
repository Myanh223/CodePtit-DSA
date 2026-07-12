#include <bits/stdc++.h>

using namespace std;

bool isValid(string s1, string s2) {
    if (s1.length() < s2.length()) return true;
    if (s1.length() > s2.length()) return false;
    return s1 <= s2; 
}

int main(){
	int t; cin >> t;
	while (t--){
		string n; cin >> n;
		int cnt = 0;
		queue<string> q;
		q.push("1");
		while (!q.empty()){
			string top = q.front();
			q.pop();
			if (isValid(top, n)){
				cnt++;
				q.push(top + '0');
				q.push(top + '1');
			}
			else break;
		}
		cout << cnt << endl;
	}
	return 0;
}