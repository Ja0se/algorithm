#include<iostream>
#include<vector>
#include<cstring>
#pragma warning(disable:4996)
#define ll long long
using namespace std;
ll n;
vector<int> v;
ll Max;
ll arr[100001];
bool visited[100001];
ll jump(ll idx) {
	ll ans = 0;
	while (1) {
		visited[idx] = true;
		ans += v[idx];
		idx += v[idx];
		if (idx > n) {
			break;
		}
		if (visited[idx]) {
			return ans + arr[idx];
		}
	}
	return ans;
}
int main(void) {
	freopen("jump.inp", "r", stdin);
	freopen("jump.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		v.clear();
		v.push_back(0);
		memset(visited, 0, sizeof(visited));
		Max = 0;
		cin >> n;
		ll a;
		for (ll i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		ll m = 0;
		for (ll i = n; i > 0; i--) {
			if (!visited[i]) {
				m = jump(i);
				arr[i] = m;
			}
			if (Max < m)Max = m;
		}
		cout << Max << "\n";
	}

	return 0;
}

