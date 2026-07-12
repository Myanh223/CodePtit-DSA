#include <bits/stdc++.h>

using namespace std;

int k;
string s, max_s;

void Try(int k){
	if (s > max_s) max_s = s;
	if (k == 0) return;
	int n = s.length();
	for (int i = 0; i < n - 1; i++){
		char max_char = s[i];
		for (int j = i + 1; j < n; j++){
			if (s[j] > max_char){
				max_char = s[j];
			}
		}
		if (max_char > s[i]){
			for (int j = i + 1; j < n; j++){
				if (s[j] == max_char){
					swap(s[i], s[j]);
					Try(k - 1);
					swap(s[i], s[j]);
				}
			}
			return;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> k >> s;
		max_s = s;
		Try(k);
		cout << max_s << endl;
	}
	return 0;
}