#include <bits/stdc++.h>

using namespace std;

vector<int> b;

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

void inOrder(Node *root){
	if (root == NULL) return;
	inOrder(root -> left);
	b.push_back(root -> val);
	inOrder(root -> right);
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		Node* root = NULL;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			root = insert(root, a[i]);
		}
		b.clear();
		inOrder(root);
		bool check = true;
		for (int i = 0; i < n; i++){
			if (a[i] != b[i]){
				check = false;
				break;
			}
		}
		if (check) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}