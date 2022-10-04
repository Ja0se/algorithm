#pragma warning(disable:4996)
#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> v[5001];
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
	freopen("show.inp", "r", stdin);	freopen("show.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> k >> n;
		finished.clear();
		finished.resize(2 * k + 1);
		s.clear();
		for (int i = 1; i <= 2 * k; i++) {
			v[i].clear();
			sn[i] = 0;
			dfsn[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int a, b, c;
			char x, y, z;
			cin >> a >> x >> b >> y >> c >> z;
			a = (x == 'R') ? a : -a;
			b = (y == 'R') ? b : -b;
			c = (z == 'R') ? c : -c;
			v[(a > 0) ? a + k : -a].push_back((b > 0) ? b : -b + k);//!x1->x2
			v[(b > 0) ? b + k : -b].push_back((c > 0) ? c : -c + k);//!x2->x3
			v[(c > 0) ? c + k : -c].push_back((a > 0) ? a : -a + k);//!x3->x1
			v[(b > 0) ? b + k : -b].push_back((a > 0) ? a : -a + k);//!x2->x1
			v[(c > 0) ? c + k : -c].push_back((b > 0) ? b : -b + k);//!x3->x2
			v[(a > 0) ? a + k : -a].push_back((c > 0) ? c : -c + k);//!x1->x3
		}
		level = ans = 0;
		for (int i = 1; i < 2 * k + 1; i++) {
			if (dfsn[i] == 0) {
				level = 0;
				int a = dfs(i);
			}
		}
		bool flag = false;
		for (int i = 1; i <= k; i++) {
			if (sn[i] == sn[k + i]) {
				flag = true;
			}
		}
		flag ? cout << "-1\n" : cout << "1\n";
	}


	return 0;
}