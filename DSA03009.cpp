#include <bits/stdc++.h>

using namespace std;

struct Job{
	int id, dl, profit;
};

bool cmp(Job a, Job b){
	return a.profit > b.profit;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<Job> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i].id >> v[i].dl >> v[i].profit;
		}
		sort(v.begin(), v.end(), cmp);
		bool used[1001] = {false};
		int cnt = 0, total = 0;
		for (int i = 0; i < n; i++){
			for (int j = v[i].dl; j >= 1; j--){
				if (!used[j]){
					used[j] = true;
					total += v[i].profit;
					cnt++;
					break;
				}
			}
		}
		cout << cnt << " " << total << endl;
	}
	return 0;
}