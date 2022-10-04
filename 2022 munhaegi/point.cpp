#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;
struct pa {
	int x, y;
};
vector<struct pa> v;
int ccw2(struct pa a, struct pa b) {
	return a.x * b.y - a.y * b.x;
}
int insidePolygon(struct pa a) {
	int crossings = 0;
	int size = v.size();
	vector<struct pa> p;
	for (int i = 0; i < size; i++) {
		p.push_back({ v[i].x - a.x,v[i].y - a.y });
	}
	for (int i = 0; i < size; i++) {
		int next = (i + 1) % size;
		if (p[i].x == 0 && p[i].y == 0)return 1;
		if (p[i].y < 0 && p[next].y >= 0 && ccw2(p[i], p[next]) > 0)crossings++;
		if (p[i].y >= 0 && p[next].y < 0 && ccw2(p[next], p[i]) > 0)crossings++;
	}
	return crossings & 1;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	freopen("point.inp", "r", stdin);
	freopen("point.out", "w", stdout);
	int n, m;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << insidePolygon({ x,y }) << "\n";
	}
	return 0;
}