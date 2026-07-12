#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int cntX = 0, cntT = 0, cntD = 0;
	for (char c : s){
		if (c == 'X') cntX++;
		else if (c == 'T') cntT++;
		else cntD++;
	}
	int X_trong_T = 0, X_trong_D = 0;
	int T_trong_X = 0, T_trong_D = 0;
	int D_trong_X = 0, D_trong_T = 0;
	for (int i = 0; i < n; i++){
		if (i < cntX){
			if (s[i] == 'T') T_trong_X++;
			if (s[i] == 'D') D_trong_X++;
		}
		else if (i < cntX + cntT){
			if (s[i] == 'X') X_trong_T++;
			if (s[i] == 'D') D_trong_T++;
		}
		else{
			if(s[i] == 'X') X_trong_D++;
			if (s[i] == 'T') T_trong_D++;
		}
	}
	int ans = 0;
	int swap_XT = min(X_trong_T, T_trong_X);
	ans += swap_XT;
	X_trong_T -= swap_XT, T_trong_X -= swap_XT;
	int swap_XD = min(X_trong_D, D_trong_X);
	ans += swap_XD;
	X_trong_D -= swap_XD, D_trong_X -= swap_XD;
	int swap_TD = min(T_trong_D, D_trong_T);
	ans += swap_TD;
	T_trong_D -= swap_TD, D_trong_T -= swap_TD;
	
	int con_lai = X_trong_T + X_trong_D;
	ans += con_lai * 2;
	cout << ans << endl;
	return 0;
}