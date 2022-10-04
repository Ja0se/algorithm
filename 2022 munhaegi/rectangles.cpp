#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct pa {
	int x1, y1;
	int y2;
	bool finish;
};
bool cmp(const struct pa &a, const struct pa& b) {
	return a.x1 < b.x1;
}
vector<struct pa> v;
int arr[20001];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	freopen("rectangles.inp", "r", stdin);
	freopen("rectangles.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 10000;
		y1 += 10000;
		x2 += 10000;
		y2 += 10000;
		v.push_back({ x1,y1,y2,0 });
		v.push_back({ x2,y1,y2,1 });
	}
	sort(v.begin(), v.end(), cmp);
	int start=0;
	for (auto& p : v) {
		int cnt = 0;
		for (int i = 0; i < 20001; i++) {
			if (arr[i] > 0)cnt++;
		}
		sum += cnt * (p.x1 - start);
		for (int i = p.y1 + 1; i <= p.y2; i++) {
			if (!p.finish) arr[i]++;
			else arr[i]--;
		}
		start = p.x1;
	}
	cout << sum;
	return 0;
}