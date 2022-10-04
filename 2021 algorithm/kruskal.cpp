#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#pragma warning(disable:4996)
using namespace std;

struct pa {
	ll w;
	ll x, y;
	int idx;
};
const ll INF = 1000000000001;
bool com(struct pa& a, struct pa& b) {
	if (a.w < b.w)return true;
	else if (a.w == b.w) if (a.idx < b.idx)return true;
	return false;
}
vector<struct pa> v;
int n, m;
int parent[10001];
bool visited[1000001];
bool cycle(int idx) {
	int p, q;
	p = v[idx].x;
	q = v[idx].y;
	while (p!=parent[p]) {
		p = parent[p];
	}
	int c = v[idx].x;
	int cx;
	while (c!=p) {
		cx = c;
		c=parent[c];
		parent[cx] = p;
	}
	while (q != parent[q]) {
		q = parent[q];
	}
	c = v[idx].y;
	while (c != q) {
		cx = c;
		c = parent[c];
		parent[cx] = q;
	}
	if (p == q)	return false;
	else {
		parent[q] = p;
		return true;
	}
}
int main(void) {
	freopen("kruskal.inp", "r", stdin);
	freopen("kruskal.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m;
	ll a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ c,a,b,i});
	}
	sort(v.begin(), v.end(), com);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int sum = 0;
	vector<int> vc;
	for (int i = 0; i < m; i++) {
		int p = v[i].x;
		int c = v[i].y;
		
		if (cycle(i)) {
			sum += v[i].w;
			vc.push_back(v[i].idx);
		}
	}
	cout << sum << "\n";
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << "\n";
	}
	return 0;
}