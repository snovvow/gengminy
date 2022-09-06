//[BOJ] 개미굴 / 골드3 https://www.acmicpc.net/problem/14725

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
struct Node{
	map<string, Node*> child;
	map<string, Node*>::iterator iter;

	void insert(vector<string> input, int idx) {
		if (idx == input.size())
            return;

		string ss = input[idx];
		iter = child.find(ss);
        //이미 존재하는 원소면 다음 칸으로 이동
		if (iter != child.end())
			iter->second->insert(input, idx + 1);
        //새로운 원소면 추가후 이동
		else {
			Node* n = new Node;
			child.insert(make_pair(ss,n));
			n->insert(input, idx + 1);
		}
	}

	void print(int idx) {
		if (child.empty())
            return;
		for (map<string, Node *>::iterator it = child.begin(); it != child.end(); it++) {
			for (int i = 0; i < idx; i++)
				cout << "--";
			cout << it->first << '\n';
			it->second->print(idx + 1);
		}
	}
};

Node tmp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N, K;
	Node* root = new Node;
	string ss;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> K;
		vector<string> item_list;
		for (int j = 0; j < K; j++) {
			cin >> ss;
			item_list.push_back(ss);
		}
		root->insert(item_list, 0);
	}
	root->print(0);
	return 0;
}
