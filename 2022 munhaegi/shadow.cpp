#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
vector<int> v;
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("shadow.inp", "r", stdin);
	freopen("shadow.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int sum = 0;
		int Max = 0;
		int Maxidx;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
			sum += a;
			if (a > Max) {
				Max = a;
				Maxidx = i;
			}
		}
		int ans = 0;
		int first = 0;;
		for (int i = 0; i <= Maxidx; i++) {
			if (first < v[i]) {
				first = v[i];
			}
			ans += first;
		}
		first = v.back();
		for (int i = n - 1; i > Maxidx; i--) {
			if (first < v[i])first = v[i];
			ans += first;
		}
		cout << ans - sum << "\n";
		v.clear();
	}

	return 0;
}