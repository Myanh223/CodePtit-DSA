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

void in(Node *root){
	if (root == NULL) return;
	if (root -> left == NULL && root -> right == NULL){
		cout << root -> val << " ";
		return;
	}
	in(root -> left);
	in(root -> right);
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
		in(root);
		cout << endl;
	}
	return 0;
}