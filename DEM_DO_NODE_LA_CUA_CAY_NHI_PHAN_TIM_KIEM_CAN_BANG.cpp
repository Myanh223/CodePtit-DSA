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

Node* build(vector<int>& a, int l, int r){
	if (l > r) return NULL;
	int m = (l + r)/ 2;
	Node *root = new Node(a[m]);
	root -> left = build(a, l, m - 1);
	root -> right = build(a, m + 1, r);
	return root;
}

void nutLa(Node *root){
	if (root == NULL) return;
	if (root -> left == NULL && root -> right == NULL){
		v.push_back(root -> val);
	}
	nutLa(root -> left);
	nutLa(root-> right);
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node* root = NULL;
		vector<int> a;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		root = build(a, 0, a.size() - 1);
		v.clear();
		nutLa(root);
		cout << v.size() << endl;
	}
	return 0;
}