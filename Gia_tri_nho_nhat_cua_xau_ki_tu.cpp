#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		int k; cin >> k;
		string s; cin >> s;
		map<char, int> freq;
		for (char c : s){
			freq[c]++;
		}
		priority_queue<int> q;
		for (auto it : freq){
			q.push(it.second);
		}
		while (k--){
			//chon ra ki tu co tan suat xuat hien lon nhat
			int top = q.top();
			q.pop();
			--top;
			q.push(max(top, 0));
		}
		long long res = 0;
		while (!q.empty()){
			long long val = q.top();
			q.pop();
			res += val * val;
		}
		cout << res << endl;
	}
	return 0;
}