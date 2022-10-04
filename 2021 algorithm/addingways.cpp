#include<iostream>
#define ll long long
#pragma warning(disable:4996)
using namespace std;
ll n, k;
ll dp[21][301];
int main(void) {
	freopen("addingways.inp", "r", stdin);
	freopen("addingways.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	for (int i = 1; i <= 300; i++) {
		dp[1][i] = 1;
		if (i <= 20)dp[i][i] = 1;
	}
	for (int i = 2; i <= 20; i++) {
		for (int j = i + 1; j <= 300; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - i];
			dp[i][j] %= 1000000007;
		}
	}
	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0)	break;
		cout << dp[k][n] << "\n";
	}
	return 0;
}