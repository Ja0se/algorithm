//1723871 Jang Se Jin
#include<iostream>
#include<algorithm>

#define ll long long
#pragma warning(disable:4996)
using namespace std;

int w,l,h;
int dp[201][201][201];
int main(void) {
	freopen("cube.inp", "r", stdin);
	freopen("cube.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			for (int k = 1; k <= 200; k++) {

				
				if (i == 1 || j == 1 || k == 1) {//min == 1
					dp[i][j][k] = i * j * k;
				}
				else if (i == j && j == k) {
					dp[i][j][k] = 1;
				}
				else if (dp[i][j][k] == 0) {
					int a = 1;
					int Min = 987654321;
					while (1) {
						if (a > i / 2)	break;
						Min = min(Min, dp[i - a][j][k] + dp[a][j][k]);
						a++;
					}
					a = 1;
					while (1) {
						if (a > j / 2)	break;
						Min = min(Min, dp[i][j - a][k] + dp[i][a][k]);
						a++;
					}
					a = 1;
					while (1) {
						if (a > k / 2)	break;
						Min = min(Min, dp[i][j][k - a] + dp[i][j][a]);
						a++;
					}
					dp[i][j][k] = dp[j][i][k] = dp[j][k][i] = dp[i][k][j] = dp[k][i][j] = dp[k][j][i] = Min;
				}
			}
		}
	}

	for (int t = 0; t < T; t++) {
		cin >> w >> h >> l;
		cout << dp[w][h][l] << "\n";
	}
	

	return 0;
}