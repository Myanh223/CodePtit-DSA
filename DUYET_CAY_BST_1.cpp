#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	Node *left, *right;
	Node(int x){
		val = x;
		left = right = NULL;
	}
};

Node* build(int pre[], int &idx, int l, int r, int n){
	if (*idx >= n || l > r) return NULL;
	Node *root = new Node(pre[*idx]);
	(*idx)++;
	if (l == r) return root;
	int ans;
	for (int i = l; i <= r; i++){
		if (pre[i] > root -> val) {
			ans = i;
			break;
		}
	}
	root -> left = build(pre, idx, *idx, ans - 1, n);
	root -> right = build(pre, idx, ans, r, n);
}

int main(){
	
}

