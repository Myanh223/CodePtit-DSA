#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<int> st;
	string command; 
	while (cin >> command){
		if (command == "push"){
			int val; cin >> val;
			st.push(val);
		}
		else if (command == "pop"){
			if (!st.empty()){
				st.pop();
			}
		}
		else if (command == "show"){
			if (st.empty()){
				cout << "empty" << endl;
			}
			else{
				vector <int> tmp;
				while (!st.empty()){
					tmp.push_back(st.top());
					st.pop();
				}
				for (int i = tmp.size() - 1; i >= 0; i--){
					cout << tmp[i] << " ";
				}
				cout << endl;
				for (int i = tmp.size() - 1; i >= 0; i--){
					st.push(tmp[i]);
				}
			}
		}
	}
	return 0;
}