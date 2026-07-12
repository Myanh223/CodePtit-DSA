#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		string s;
		long long n;
		cin >> s >> n;
		
		long long len = s.length();
		while (len < n){
			len *= 2;
		}
		while (len > s.length()){
			long long mid = len / 2;
			if (n > mid){
				n = n - mid;
				n = n - 1;
				
				if (n == 0) n = mid;
			}
			len = mid;
		}
		cout << s[n - 1] << endl;
	}
	return 0;
}