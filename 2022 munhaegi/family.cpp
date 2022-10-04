#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int parent[1001];
int Max = 0;
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("family.inp", "r", stdin);
	freopen("family.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, h;
		Max = 0;
		cin >> n >> h;
		vector<int> deep(n+1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> parent[i];
		}
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			int me = parent[i];
			while (me != 0) {
				deep[me]++;
				me = parent[me];
				cnt++;
			}
			Max = max(Max, cnt);
		}
		cout << Max << "\n";
		for (int i = 1; i <= h; i++)cout << deep[i]+1 << " ";
		cout << "\n";
	}

	return 0;
}