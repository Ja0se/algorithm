#pragma warning(disable:4996)
#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> v[10001];
int n, k;
//r true b falseW
int dfsn[10001];
int sn[10001];
int level, ans;
vector<int> s;
vector<bool> finished;

int dfs(int x) {
	dfsn[x] = ++level;
	s.push_back(x);
	int parent = dfsn[x];
	for (int i = 0; i < v[x].size(); i++) {
		int p = v[x][i];
		if (dfsn[p] == 0)parent = min(parent, dfs(p));
		else if (!finished[p])parent = min(parent, dfsn[p]);
	}
	if (parent == dfsn[x]) {
		while (1) {
			int top = s.back();
			s.pop_back();
			finished[top] = 1;
			sn[top] = ans;
			if (top == x)break;
		}
		ans++;
	}
	return parent;
}

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("factory.inp", "r", stdin);	freopen("factory.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> k;
		finished.clear();
		s.clear();
		finished.resize(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			v[i].clear();
			sn[i] = 0;
			dfsn[i] = 0;
		}
		vector<pair<int, int> > pa;
		pa.resize(2 * n);
		int MaxTime = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			pa[i] = make_pair(a, i);
			pa[i + n] = make_pair(b, i + n);
		}
		sort(pa.begin(), pa.end());
		for (int i = 0; i < 2 * n; i++) {
			for (int j = i + 1; j < 2 * n; j++) {
				if (pa[j].first - pa[i].first >= k)break;
				int u = pa[i].second;
				int v1 = (pa[j].second >= n) ? pa[j].second - n : pa[j].second + n;
				v[v1].push_back(u);
				v[(pa[i].second >= n) ? pa[i].second - n : pa[i].second + n].push_back(pa[j].second);
			}
		}
		level = ans = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (dfsn[i] == 0) {
				level = 0;
				int a = dfs(i);
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (sn[i] == sn[n + i]) {
				flag = true; break;
			}
		}
		cout << "Test Case #" << t + 1;
		flag ? cout << ": Impossible\n" : cout << ": Possible\n";
	}


	return 0;
}