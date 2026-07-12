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

Node* insert2(Node *root, int x){
	if (root == NULL){
		return new Node(x);
	}
	if (x < root -> val){
		root -> left = insert2(root -> left, x);
	}
	else if (x > root -> val){
		root-> right = insert2(root -> right, x);
	}
	return root;
}

void makeNode(Node *root, int u, int v, char c){
	if (c == 'L') root -> left = new Node(v);
	else root -> right = new Node(v);
}

void insert(Node *root, int u, int v, char c){
	if (root == NULL) return;
	if (root -> val == u){
		makeNode(root, u, v, c);
	}
	insert(root -> left, u, v, c);
	insert(root -> right, u, v, c);
}

void preOrder(Node *root){
	if (root == NULL) return;
	b.push_back(root -> val);
	preOrder(root -> left);
	preOrder(root -> right);
}

void inOrder(Node *root){
	if (root == NULL) return;
	inOrder(root -> left);
	cout << root -> val << " ";
	inOrder(root -> right);
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node* root1 = NULL;
		while (n--){
			int u, v; char c;
			cin >> u >> v >> c;
			if (root1 == NULL){
				root1 = new Node(u);
				makeNode(root1, u, v, c);
			}
			else insert(root1, u, v, c);
		}
		b.clear();
		preOrder(root1);
		Node* root2 = NULL;
		for (int i = 0; i < b.size(); i++){
			root2 = insert2(root2, b[i]);
		}
		inOrder(root2);
		cout << endl;
	}
	return 0;
}