#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

struct pa {
	int x, y;
	int p, q;
	bool diff;
	int idx;
	bool operator <(const struct pa& b) const {
		if (1LL * q * b.p != 1LL * p * b.q) return 1LL * q * b.p < 1LL * p * b.q;
		else if (x == b.x) {
			if (y < b.y)return true;
			else return false;
		}
		else {
			if (x < b.x)return true;
			return false;
		}
		return x == b.x ? y < b.y : x < b.x;
	}
};
//bool cmp(const struct pa& a, const struct pa& b) {
//	if ((a.x * b.y) != (a.y * b.x)) return (a.q * b.p) < (a.p * b.q);
//	if (a.y != b.y)return a.x < b.x;
//	return a.y < b.y;
//}
vector<struct pa> v1;
vector<struct pa> v2;
vector<struct pa> v;
ll ccw2(struct pa a, struct pa b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}
ll ccw(struct pa a, struct pa b, struct pa c) {
	//ll A=ccw2({ b.x - a.x,b.y - a.y ,0,0,0,0}, { c.x - a.x,c.y - a.y ,0,0,0,0});
	//if (A == 0)return 0;
	//else if (A > 0)return 1;
	//return -1;
	//return A;
	return 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y - 1LL * a.y * b.x - 1LL * b.y * c.x - 1LL * c.y * a.x;
}
bool between(struct pa a, struct pa b, struct pa c) {
	if (ccw(a, b, c) != 0)return false;
	if (a.x != b.x)return(a.x <= c.x && c.x <= b.x) || (b.x <= c.x && c.x <= a.x);
	return (a.y <= c.y && c.y <= b.y) || (b.y <= c.y && c.y <= a.y);
}
double area(vector<struct pa>& p) {
	double ret = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		ret += (p[i].x * p[j].y - p[i].y * p[j].x);
	}

	return ret;
}
void swap(vector<struct pa>& p, int x, int y) {
	struct pa tmp = p[x];
	p[x] = p[y];
	p[y] = tmp;
}
bool Same(struct pa a, struct pa b) {
	return a.x == b.x && a.y == b.y;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("tangent.inp", "r", stdin); freopen("tangent.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v1.push_back({ a,b ,0,0,false,i });
			v.push_back(v1[i]);
			if (v[0].x > v[i].x) swap(v, 0, i);
			else if (v[0].x == v[i].x && v[0].y > v[i].y)swap(v, 0, i);
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v2.push_back({ a,b ,0,0,true,i });
			v.push_back(v2[i]);
			if (v[0].x > v[i + n].x) swap(v, 0, i + n);
			else if (v[0].x == v[i + n].x && v[0].y > v[i + n].y)swap(v, 0, i + n);
		}

		for (int i = 1; i < n + m; i++) {
			v[i].p = v[i].x - v[0].x;
			v[i].q = v[i].y - v[0].y;
		}
		sort(v.begin() + 1, v.end());
		vector<struct pa> convex;
		for (int i = 0; i < n + m; i++) {
			while (convex.size() > 1 && ccw(convex[convex.size() - 2], convex.back(), v[i]) <= 0) {
				convex.pop_back();
			}
			convex.push_back(v[i]);
		}
		vector<struct pa> ap, bp;
		for (int i = 0; i < convex.size(); i++) {
			int j = (i + 1) % convex.size();
			if (convex[i].diff != convex[j].diff) {
				if (convex[i].diff) {
					bp.push_back(convex[i]);
					ap.push_back(convex[j]);
				}
				else {
					ap.push_back(convex[i]);
					bp.push_back(convex[j]);
				}
			}
		}
		//change closer point
		for (int i = 0; i < n + m; i++) {
			if (v[i].diff) {
				if (between(ap[0], bp[0], v[i])) bp[0] = v[i];
				if (between(ap[1], bp[1], v[i])) bp[1] = v[i];
			}
			else {
				if (between(ap[0], bp[0], v[i])) ap[0] = v[i];
				if (between(ap[1], bp[1], v[i])) ap[1] = v[i];
			}
		}
		convex.clear();
		bool flag = false;
		if (bp[0] < ap[0])flag = true;
		if (!flag) {
			for (int i = ap[0].idx;; i = (i + 1) % n) {
				convex.push_back(v1[i]);
				if (Same(v1[i], ap[1])) break;
			}
			for (int i = bp[1].idx;; i = (i + 1) % m) {
				convex.push_back(v2[i]);
				if (Same(v2[i], bp[0])) break;
			}
		}
		else {
			for (int i = bp[0].idx;; i = (i + 1) % m) {
				convex.push_back(v2[i]);
				if (Same(v2[i], bp[1])) break;
			}
			for (int i = ap[1].idx;; i = (i + 1) % n) {
				convex.push_back(v1[i]);
				if (Same(v1[i], ap[0])) break;
			}
		}

		double ans = 0;
		ans += area(convex);
		if (Same(ap[0], ap[1])) {
			ans += area(v1);
		}
		else if (Same(bp[0], bp[1]))ans += area(v2);
		if (ans < 0)ans *= -1;
		cout.precision(1);
		cout << fixed;
		cout << ans / 2.0 << "\n";
		v1.clear(); v2.clear(); v.clear();
	}

	return 0;
}
