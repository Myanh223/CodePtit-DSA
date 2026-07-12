#include <bits/stdc++.h>

using namespace std;

struct Node{
	string val;
	Node *left, *right;
	Node (string x){
		val = x;
		left = right = NULL;
	}
};

bool check(string c){
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

