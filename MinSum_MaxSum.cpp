#include <bits/stdc++.h>

using namespace std;

long long doi(string s, char from, char to){
	for (int i = 0; i < s.length(); i++){
		if (s[i] == from){
			s[i] = to;
		}
	}
	return stoll(s);
}

int main(){
	string a, b;
	cin >> a >> b;
	int min_sum = 0, max_sum = 0;
	long long minA = doi(a, '6', '5');
	long long minB = doi(b, '6', '5');
	long long minSum = minA + minB;
	
	long long maxA = doi(a, '5', '6');
	long long maxB = doi(b, '5', '6');
	long long maxSum = maxA + maxB;
	
	cout << minSum << " " << maxSum << endl;
	return 0;
}