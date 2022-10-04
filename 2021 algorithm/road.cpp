#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
struct pa {
	int x, y,color;
};
struct pl {
	int x, color;
	int idx;
};
int n, k;
bool visited[10001];
vector<struct pl>v[10001];
bool ch;
int cnt;
void paint(int x, int y, int color) {
	visited[x] = true;
	if (y == x) {
		ch = true;
	}
	else {
		for (int i = 0; i < v[x].size(); i++) {
			int to = v[x][i].x;
			if (!visited[to]) paint(to, y, color);
			if (ch) {
				int idx = v[x][i].idx;
				v[x][i].color = color;
				v[to][idx].color = color;
				break;
			}
		}
	}
}
bool color[10001];
void find(int start) {
	visited[start] = 1;
	for (int i = 0; i < v[start].size(); i++) {
		if (!visited[v[start][i].x]) {
			if (!color[v[start][i].color]) {
				color[v[start][i].color] = true;
				cnt++;
			}
			find(v[start][i].x);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("road.inp", "r", stdin);
	freopen("road.out", "w", stdout);
	int t;
	cin >> t;
	v[0].push_back({ 1, 0,0});
	for (int T = 0; T < t; T++) {
		cin >> n;
		int a, b, c;
		int Max = 0;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			int lena = v[a].size();
			int lenb = v[b].size();
			v[a].push_back({b,0,lenb});
			v[b].push_back({a,0,lena});
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c;
			if (Max < c)Max = c;
			ch = false;
			for (int i = 1; i <= n; i++) {
				visited[i] = false;
			}
			paint(a, b, c);
		}
		for (int i = 1; i <= n; i++) {
			visited[i] = false;
		}
		cnt = 0;
		find(0);
		cout << cnt << "\n";
		memset(color, 0, sizeof(color));
		for (int i = 1; i <= n; i++) {
			visited[i] = false;
			v[i].clear();
		}
		for (int i = 1; i <= Max; i++) {
			color[i] = false;
		}
	}
	return 0;
}

