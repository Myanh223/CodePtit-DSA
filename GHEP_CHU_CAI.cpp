#include <bits/stdc++.h>

using namespace std;

int n, X[101];
char c;
bool used[101];

bool isVowel(char ch){
	return (ch == 'A' || ch == 'E');
}

bool check(string s){
	for (int i = 1; i < s.length() - 1; i++){
		if (isVowel(s[i])){
			if (!isVowel(s[i - 1]) && !isVowel(s[i + 1])){
				return false;
			}
		}
	}
	return true;
}

void Try(int i, string s){
	for (int j = 0; j < n; j++){
		if (!used[j]){
			char ch = 'A' + j;
			used[j] = true;
			
			if (i == n - 1){
				if (check(s + ch)){
					cout << s + ch << endl;
				}
			}
			else Try(i + 1, s + ch);	
			used[j] = false;
		}
	}
}

int main(){
	cin >> c;
	n = c - 'A' + 1;
	memset(used, false, sizeof(used));
	Try(0, "");
	return 0;
}