#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		vector<int> v;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '['){
				v.push_back(i);
			}
		}
		int cnt = 0, trace = 0, res = 0;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '['){
				cnt++;
				trace++;
			}
			else if (s[i] == ']'){
				cnt--;
			}
			if (cnt < 0){
				res += v[trace] - i;
				swap(s[i], s[v[trace]]);
				cnt = 1;
				trace++;
			}
		}
		cout << res << endl;
	}
	return 0;
}