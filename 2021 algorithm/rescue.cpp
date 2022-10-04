#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[10002];
int dp[10002];
int n;
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("rescue.inp", "r", stdin);
	freopen("rescue.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i+1];
		}
		dp[1] = arr[1];
		dp[2] = arr[1] + arr[2];
		dp[3] = max(arr[1] + arr[3],arr[2]+arr[3]);
		for (int i = 4; i <= n; i++) {
			dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		}
		cout << dp[n] << "\n";
	}

	return 0;
}