 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool soLapPhuong(string cube, string s){
	int i = 0, j = 0;
	while (i < cube.length() && j < s.length()){
		if (cube[i] == s[j]){
			i++;
		}
		j++;
	}
	return (i == cube.length());
}

int main(){
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		string s = to_string(n);
		bool ok = false;
		for (int i = 1000000; i >= 1; i--){
			ll cubeVal = i * i * i;
			string cubeStr = to_string(cubeVal);
			
			if (cubeVal > n) continue;
			if (soLapPhuong(cubeStr, s)){
				ok = true;
				cout << cubeVal << endl;
				break;
			}
		}
		if (!ok) cout << -1 << endl;
	}
	return 0;
}