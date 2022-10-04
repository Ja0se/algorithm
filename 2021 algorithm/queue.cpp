#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#define ll long long
#pragma warning(disable:4996)
using namespace std;

string str;
int key;
int pre;
vector<int>v;
void ins() {
	v.push_back(key);
	int idx = v.size()-1;
	while (1) {
		if (idx <= 1)return;
		if (key > v[idx / 2]) {
			int tmp = v[idx];
			v[idx] = v[idx / 2];
			v[idx / 2] = tmp;
		}
		else break;
		idx /= 2;
	}
}
void adj() {
	//auto it = find(v.begin(), v.end(), pre);
	//v[1] = pre;
	//v.erase(it);
	int idx = 1;
	v[1] = v[v.size() - 1];
	v.pop_back();
	while (idx*2<v.size()) {
		int idx2 = idx * 2;
		int idx1 = idx * 2 + 1;
		if (v.size() == idx1) {
			if (v[idx] < v[idx2]) {
				int tmp = v[idx2];
				v[idx2] = v[idx];
				v[idx] = tmp;
				idx = idx2;
			}
			return;
		}
		if (v[idx] < v[idx2] && v[idx] < v[idx1]) {
			int tmp = v[idx];
			if (v[idx1] < v[idx2]) {
				v[idx] = v[idx2];
				v[idx2] = tmp;
				idx = idx2;
			}
			else {
				v[idx] = v[idx1];
				v[idx1] = tmp;
				idx = idx1;
			}
		}
		else if (v[idx] < v[idx2]) {
			int tmp = v[idx2];
			v[idx2] = v[idx];
			v[idx] = tmp;
			idx = idx2;
		}
		else if (v[idx] < v[idx1]) {
			int tmp = v[idx1];
			v[idx1] = v[idx];
			v[idx] = tmp;
			idx = idx1;
		}
		else break;
	}
}
void print(int n) {
	if (n >= v.size())	return;
	cout << v[n] << " ";
	print(2 * n);
}

int main(void) {
	freopen("queue.inp", "r", stdin);
	freopen("queue.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	v.push_back(0);
	while (1) {
		cin >> str;
		if (str[0] == 'q') {
			break;
		}
		else if (str[0] == 'r') {
			print(1);
			cout << "\n";
			//memset(visited, false, sizeof(v.size()+1));
		}
		else if (str[0] == 'd') {
			adj();
		}
		else {
			key = stoi(str);
			ins();
			pre = key;
		}
	}
	

	return 0;
}