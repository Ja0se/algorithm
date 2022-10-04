#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
vector<int> v;
vector<int> tree;
void update(int idx, ll value, int end) {
	while (idx <= end) {
		tree[idx] += value;
		idx += (idx & (-idx));
	}
}
ll sum(int idx) {
	ll value = 0;
	while (idx > 0) {
		value += tree[idx];
		idx -= (idx & (-idx));
	}
	return value;
}

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("bit.inp", "r", stdin);	freopen("bit.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	tree.resize(n + 1);
	v.resize(n + 1);
	v[1] = 1;
	update(1, 1, n);
	v[2] = 1;
	update(2, 1, n);
	for (int i = 3; i <= n; i++) {
		v[i] = (v[i - 1] + v[i - 2]) % m;
		update(i, v[i], n);
	}
	for (;;) {
		char c;
		int a, b;
		cin >> c >> a >> b;

		if (c == 'C') {
			int tmp = b % m;
			int diff = tmp - v[a];
			v[a] = tmp;
			update(a, diff, n);
		}
		else if (c == 'S') {
			int Sum = sum(b);
			Sum -= sum(a - 1);
			cout << c << " " << a << " " << b << " : " << Sum << "\n";

		}
		else if (c == 'P') {
			cout << c << " " << a << " " << b << " : ";
			for (int i = a; i <= b; i++) {
				cout << tree[i] << " ";
			}
			cout << "\n";
		}
		else break;

	}
	return 0;
}