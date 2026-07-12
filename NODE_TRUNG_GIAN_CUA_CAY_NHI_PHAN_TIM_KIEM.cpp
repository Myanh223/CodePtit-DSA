#include <bits/stdc++.h>

using namespace std;

vector<int> v;

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

void nutTrungGian(Node *root){
	if (root == NULL) return;
	if ((root -> left == NULL && root -> right != NULL) || (root -> left != NULL && root -> right == NULL) || (root -> left != NULL && root -> right != NULL)){
		v.push_back(root -> val);
	}
	nutTrungGian(root -> left);
	nutTrungGian(root -> right);
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
		v.clear();
		nutTrungGian(root);
		cout << v.size() << endl;
	}
}