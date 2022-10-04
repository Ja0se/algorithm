#pragma warning(disable:4996)
#include<iostream>

using namespace std;
int solve(int n) {
	int cnt = 1;
	while (n != 1) {
		if (n & 1) {
			n = 3 * n + 1;
		}
		else n /= 2;
		cnt++;
	}
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("cycle.inp", "r", stdin);
	freopen("cycle.out", "w", stdout);
	int n, m;
	while (cin >> n >> m) {
		bool ch = true;
		if (n > m) {
			int tmp = n;
			n = m;
			m = tmp;
			ch = false;
		}
		int Max = 0;
		for (int i = n; i <= m; i++) {
			int a = solve(i);
			if (Max < a) {
				Max = a;
			}
		}
		if (ch)cout << n << " " << m << " " << Max << "\n";
		else cout << m << " " << n << " " << Max << "\n";
	}
	return 0;
}