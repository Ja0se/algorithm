#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define Mod 1000000007
using namespace std;
bool visited[10000001];
int solve(int start, int end) {
	int cnt = 0;
	for (int i = start; i <= end; i++) {
		if (!visited[i])cnt++;
	}
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("prime.inp", "r", stdin);	freopen("prime.out", "w", stdout);
	visited[1] = 1;
	int Max = 10000001;
	for (int i = 2; i < Max; i++) {
		if (!visited[i]) {
			for (int j = i+i; j < Max; j += i) {
				visited[j] = true;
			}
		}
	}
	while (1) {
		int n, m;
		int ans = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		cout << solve(n, m) << "\n";

	}
	return 0;
}