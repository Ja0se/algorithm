#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
struct pa {
	int x, y;
	bool operator<(const struct pa b)const {
		return x + y < b.x + b.y;
	}
};
bool pythagorean(int a, int b, int c) {
	if (a % 2 == 0 || c % 2 == 0)return false;
	if (b % 4 != 0)return false;
	if (a % 3 != 0 && b % 3 != 0)return false;
	if (a % 5 != 0 && b % 5 != 0 && c % 5 != 0)return false;
	ll mul = 1LL * a * b;
	if (mul % 12 != 0)return false;
	mul *= c;
	if (mul % 60 != 0)return false;
	return true;
}
int gcd(int a, int b) {
	if (b == 0)return a;
	gcd(b, a % b);
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("rectangles.inp", "r", stdin);	freopen("rectangles.out", "w", stdout);
	int T;
	vector<struct pa> v;
	for (int i = 2; i < 100; i++) {
		int j;
		if (i % 2 == 0)j = 1;
		else j = 2;
		for (; j < i; j += 2) {
			int a = i * i - j * j;
			int b = 2 * j * i;
			int c = i * i + j * j;
			bool flag = false;
			if (pythagorean(a, b, c)) {
				if (a > b) {
					int tmp = a;
					a = b;
					b = tmp;
				}
				for (struct pa k :v) {
					if (k.x * b == k.y * a) {
						flag = true;
						break;
					}
				}
				if (!flag)v.push_back({ a,b });
			}
		}
	}
	sort(v.begin(), v.end());
	cin >> T;
	while (T--) {
		int L;
		cin >> L;
		int sum = 0;
		int cnt = 0;
		bool flag = false;

		for (struct pa i :v) {
			if (sum + 2 * (i.x + i.y) <= L) {
				sum += 2 * (i.x + i.y);
				cnt++;
			}
			else break;
		}
		cout << cnt << "\n";
	}

	return 0;
}