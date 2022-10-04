#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
bool visited[50001];
vector<int> v[50001];
int dp[50001][2];//cycle
int Max;
void dfs(int start,int cnt) {
	visited[start] = true;
	dp[start][0] = cnt;
	int Max1, Max2;
	Max1 = Max2 = 0;
	for (int i = 0; i < v[start].size(); i++) {
		int to = v[start][i];
		if (!visited[to]) {
			dfs(to, cnt + 1);
			dp[start][0] = max(dp[to][0],dp[start][0]);
			if (Max1 <= dp[to][0]) {
				Max2 = Max1;
				Max1 = dp[to][0];
			}
			else if (Max2 < dp[to][0]) {
				Max2 = dp[to][0];
			}
		}
	}
	if (Max1 != 0)Max1 -= cnt;
	if (Max2 != 0)Max2 -= cnt;
	dp[start][1] = Max1 + Max2 + 1;
	Max = max(Max, dp[start][1]);
}

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("cycle.inp","r",stdin);
	freopen("cycle.out","w",stdout);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int a, b;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		Max = 0;
		dfs(1, 0);
		cout << Max << "\n";
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			dp[i][0]=dp[i][1] = 0;
			visited[i] = false;
		}
	}

	return 0;
}