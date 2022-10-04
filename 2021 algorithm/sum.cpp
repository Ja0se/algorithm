#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
//int arr[202];
int dp[202][80002];
vector<int> v,arr;
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("sum.inp", "r", stdin);
	freopen("sum.out", "w", stdout);
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		cin >> n >> m;
		int a;
		arr.clear();
		for (int i = 0; i < n; i++) {
			cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}
		for (int i = 1; i <= m; i++) {
			dp[0][i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j] % 100000;
				if (j >= arr[i - 1]) {
					int x = j - arr[i - 1];
					dp[i][j] = dp[i][j] % 100000 + dp[i - 1][x] % 100000;
				}
			}
		}
		cout << dp[n][m]%100000 << "\n";
		v.clear();
	}
	return 0;
}


//for (int i = 0; i < n; i++) {
		//	int size = v.size();
		//	if (arr[i] > m)break;
		//	priority_queue<int> pq(v.begin(),v.begin()+size);
		//	if (dp[arr[i]] == 0) {
		//		v.push_back(arr[i]);
		//	}
		//	int sum;
		//	while (!pq.empty()) {
		//		int top = pq.top();
		//		pq.pop();
		//		sum = top + arr[i];
		//		if (sum > m)continue;
		//		if (dp[sum] == 0) {
		//			v.push_back(sum);
		//		}
		//		dp[sum] += dp[top]%100000;
		//		dp[sum] %= 100000;
		//	}
		//	dp[arr[i]]++;
		//	/*for (int j = 0; j < size; j++) {
		//		int sum = arr[i] + v[j];
		//		if (sum > m)continue;
		//		if (dp[sum]==0) {
		//			v.push_back(sum);
		//		}
		//		dp[sum] += dp[v[j]];
		//	}
		//	if (dp[arr[i]]==0) {
		//		dp[arr[i]]++;
		//		v.push_back(arr[i]);
		//	}*/
		//	
		//}