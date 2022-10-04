#pragma warning(disable:4996)
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
string str;
int index;
int arr[1001];
void dfs(int lo, int hi) {
	if (lo == hi)return;
	for (int i = lo; i < hi; i++) {
		if (arr[i] == index) {
			index++;
			cout << "(";
			dfs(lo, i);
			cout << ")";
			dfs(i + 1, hi);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("transform.inp", "r", stdin);
	freopen("transform.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		cout << n << " ";
		if (k == 0) {
			for (int i = 0, a; i < n; i++) {
				cin >> arr[i];
			}
			index = 1;
			dfs(0, n);
		}
		else {
			cin >> str;
			vector<int> v;
			int cnt = 0;
			for (int i = 0; i < 2 * n; i++) {
				if (str[i] == '(') {
					v.push_back(++cnt);
				}
				else {
					cout << v.back() << " ";
					v.pop_back();
				}
			}
		}
		cout << "\n";
	}

}