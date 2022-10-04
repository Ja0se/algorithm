#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("multiply3.inp", "r", stdin);
	freopen("multiply3.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		vector<ll> ve;
		for (int i = 0; i < n; i++) {
			ll a;
			cin >> a;
			ve.push_back(a);
		}
		ll Max = -1234567890;
		ll Min = 1234567890;
		sort(ve.begin(), ve.end());
		Max = ve[n - 1] * ve[n - 2] * ve[n - 3];
		Max = max(Max, ve[0] * ve[1] * ve[n - 1]);
		Min = ve[0] * ve[1] * ve[2];
		Min = min(Min, ve[0] * ve[n - 1] * ve[n - 2]);
		cout << Min << " " << Max << "\n";
	}

	return 0;
}