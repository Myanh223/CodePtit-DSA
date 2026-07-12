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

Node* build(vector<int>& a, int l, int r){
	if (l > r) return NULL;
	int mid = (l + r)/2;
	Node *root = new Node(a[mid]);
	root -> left = build(a, l, mid - 1);
	root -> right = build(a, mid + 1, r);
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
		vector<int> a;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		root = build(a, 0, a.size() - 1);
		posOrder(root);
		cout << endl;
	}
	return 0;
}