#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	Node *left, *right;
	Node (int x){
		val = x;
		left = right = NULL;
	}
};

Node* insert(Node *root, int x){
	if (root == NULL){
		return new Node(x);
	}
	if (x < root -> val){
		root -> left = insert(root -> left, x);
	}
	else if (x > root -> val){
		root -> right = insert(root -> right, x);
	}
	return root;
}

void posOrder(Node *root){
	if (root == NULL) return;
	posOrder(root -> left);
	posOrder(root -> right);
	cout << root -> val << " ";
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node* root = NULL;
		while (n--){
			int x; cin >> x;
			root = insert(root, x);
		}
		posOrder(root);
		cout << endl;
	}
	return 0;
}