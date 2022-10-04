#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct pa {
	int x, y;
	int p, q;
};
bool cmp(const struct pa& a, const struct pa& b) {
	if (a.x < b.x)return true;
	else if (a.x == b.x)return a.y < b.y;
	return false;
}
bool cmp2(const struct pa& a, const struct pa& b) {
	if ((a.q * b.p) != (a.p * b.q)) return (a.q * b.p) < (a.p * b.q);
	if (a.y != b.y)return a.x < b.x;
	return a.y < b.y;
}
vector<struct pa> v;
vector<struct pa> convex;

int ccw2(struct pa a, struct pa b) {
	return a.x * b.y - a.y * b.x;
}
int ccw(struct pa a, struct pa b, struct pa c) {
	return ccw2({ b.x - a.x,b.y - a.y,0,0 }, { c.x - a.x,c.y - a.y ,0,0 });
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("hull.inp", "r", stdin); freopen("hull.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b ,1,0 });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i < n; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}
	sort(v.begin() + 1, v.end(), cmp2);
	stack<int> s;
	s.push(0);
	s.push(1);
	for (int i = 2; i < n; i++) {
		int stop = s.top();
		s.pop();
		struct pa r = v[s.top()];
		struct pa p = v[stop];
		struct pa q = v[i];
		int a = ccw(r, p, q);
		if (a == 0) {

		}
		while (a <= 0) {
			stop = s.top();
			s.pop();
			if (s.empty()) {
				break;
			}
			a = ccw(v[s.top()], v[stop], v[i]);
		}
		s.push(stop);
		s.push(i);
	}
	cout << s.size() << "\n";
	while (!s.empty()) {
		//cout << v[s.top()].x << " " << v[s.top()].y << "\n";
		convex.push_back(v[s.top()]);
		s.pop();
	}
	reverse(convex.begin(), convex.end());
	for (int i = 0; i < convex.size(); i++) {
		cout << convex[i].x << " " << convex[i].y << "\n";
	}
	return 0;
}