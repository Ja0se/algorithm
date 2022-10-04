#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
struct pa {
	ll x, y;
};
vector<struct pa> v,ans;
ll ccw2(struct pa a, struct pa b) {
	return a.x * b.y - a.y * b.x;
}
ll ccw(struct pa a, struct pa b, struct pa c) {
	return 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y - 1LL * a.y * b.x - 1LL * b.y * c.x - 1LL * c.y * a.x;
}
bool between(struct pa a, struct pa b, struct pa c) {
	if (ccw(a, b, c) != 0)return false;
	if (a.x != b.x)return(a.x <= c.x && c.x <= b.x) || (b.x <= c.x && c.x <= a.x);
	return (a.y <= c.y && c.y <= b.y) || (b.y <= c.y && c.y <= a.y);
}
int direction(struct pa a, struct pa b, struct pa c) {
	if (ccw(a, b, c) < 0)return -1;
	if (ccw(a, b, c) > 0)return 1;
	return 0;
}
bool intersectProp(struct pa a, struct pa b, struct pa c,struct pa d) {
	return direction(a, b, c) * direction(a, b, d) <= 0 && direction(c, d, a) * direction(c, d, b) < 0;
}
bool insidePolygon(struct pa a) {
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
	freopen("triangle.inp", "r", stdin);
	freopen("triangle.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		ll x, y;
		for (int i = 0; i < 3; i++) {
			cin >> x >> y;
			v.push_back({ x,y });
		}
		vector<struct pa> r;
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			cin >> x >> y;
			r.push_back({ x,y });
			bool ch = false;
			for (int j = 0; j < 3; j++) {
				int next = (j + 1) % 3;
				if (between(v[j], v[next], { x,y })) {
					cnt++;
					ch = true;
					break;
				}
			}
			if (ch)continue;
			if (insidePolygon({ x,y })) {
				cnt++;
			}
		}
		vector<struct pa> tmp = v;
		v = r;
		r = tmp;
		int pcnt = 0;
		for (int i = 0; i < 3; i++) {
			bool ch = false;
			for (int j = 0; j < 3; j++) {
				int next = (j + 1) % 3;
				if (between(v[j], v[next],r[i])) {
					pcnt++;
					ch = true;
					break;
				}
			}
			if (ch)continue;
			if (insidePolygon(r[i])) {
				pcnt++;
			}
		}
		int dir = 0;
		for (int i = 0; i < 3; i++) {
			int b = (i + 1) % 3;
			for (int j = 0; j < 3; j++) {
				int d = (j + 1) % 3;
				if (intersectProp(v[i], v[b], r[j], r[d]))dir++;
			}
		}
		if (cnt == 0 && pcnt == 0) {
			dir == 0 ? cout << "1\n" : cout << "3\n";
		}
		else if (cnt == 3||pcnt==3)cout << "2\n";
		else cout << "3\n";
		v.clear();
		r.clear();
	}
	
	return 0;
}