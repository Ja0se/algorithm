#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
struct pa {
	ll x, y;
};
struct pa arr[4];
ll ccw(struct pa a, struct pa b, struct pa c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("point.inp", "r", stdin);
	freopen("point.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 4; i++) {
			cin >> arr[i].x >> arr[i].y;
		}
		int left = 0;
		int right = 0;
		for (int i = 0; i < 4; i++) {
			int next = (i + 1) % 4;
			int tonext = (i + 2) % 4;
			if (ccw(arr[i], arr[next], arr[tonext]) < 0) {
				left++;
			}
			else right++;
		}
		if (left == 2)cout << "1\n";
		else if (left == 1 || right == 1)cout << "2\n";
		else cout << "3\n";


	}

	return 0;
}