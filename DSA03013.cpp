#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		int d; cin >> d;
		string s; cin >> s;
		int n = s.length();
		map<char, int> freq;
		int max_freq = 0;
		for (char c : s){
			freq[c]++;
			max_freq = max(max_freq, freq[c]);
		}
		if (1 + (max_freq - 1) * d <= n){
			cout << 1 << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}