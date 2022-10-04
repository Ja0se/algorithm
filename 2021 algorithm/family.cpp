#include<iostream>
#include<vector>
#include<cstring>
#pragma warning(disable:4996)

using namespace std;

int Max;
int n;
int p[500001];
vector<int> c[500001];
bool visited[500001];
void de(int me,int cnt) {
	if (c[me].empty()) {
		if (Max < cnt)Max = cnt;
		return;
	}
	for (int i = 0; i < c[me].size(); i++) {
		de(c[me][i],cnt + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	freopen("family.inp", "r", stdin);
	freopen("family.out", "w", stdout);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		Max = 0;
		memset(visited, 0, n + 1);
		int a, b;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			p[b] = a;
			c[a].push_back(b);
			visited[b] = true;
		}
		int parent;
		for (int i = 1; i <= n; i++) {
			if (!visited[i])	parent = i;
		}
		de(parent, 1);
		cout << Max << "\n";
		for (int i = 1; i <= n; i++) {
			c[i].clear();
		}
	}

	return 0;
}