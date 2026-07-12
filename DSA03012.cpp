#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		string s; cin >> s;
		int n = s.length();
		map<char, int> freq;
		int max_freq = 0;
		for (char c : s){
			freq[c]++;
			if (freq[c] > max_freq){
				max_freq = freq[c];
			}
		}
		if (max_freq <= (n + 1) / 2){
			cout << 1 << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}