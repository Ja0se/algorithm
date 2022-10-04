#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;
//A~Z 26ro 65~
string str1, str2;
int sum[29];
int arr1[5002][29];
int arr2[5002][29];
int dp[5002][5002];

void d(int i, int j, int cnt)
{
	if (i != 0 && j != 0)
		dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cnt;
	else if (i != 0)
		dp[i][j] = dp[i - 1][j] + cnt;
	else if (j != 0)
		dp[i][j] = dp[i][j - 1] + cnt;
}

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("color.inp", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> str1 >> str2;
		memset(sum, 0, sizeof(sum));
		//deflen();
		int str1len = str1.length();
		int str2len = str2.length();
		for (int i = 0; i < str1len; i++)
		{
			sum[str1[i] - 65]++;
			for (int j = 0; j < 27; j++)
			{
				arr1[i + 1][j] = arr1[i][j];
			}
			arr1[i + 1][str1[i] - 65]++;
		}

		for (int i = 0; i < str2len; i++)
		{
			sum[str2[i] - 65]++;
			for (int j = 0; j < 27; j++)
			{
				arr2[i + 1][j] = arr2[i][j];
			}
			arr2[i + 1][str2[i] - 65]++;
		}

		for (int i = 0; i <= str1len + 1; i++)
		{
			for (int j = 0; j <= str2len + 1; j++)
			{
				int cnt = 0;
				for (int k = 0; k < 27; k++)
				{
					int s = arr1[i][k] + arr2[j][k];
					if (s <= 0) continue;
					else if (s == sum[k]) continue;
					else cnt++;
				}
				d(i, j, cnt);
			}
		}
		cout << dp[str1len][str2len] << "\n";
	}

	return 0;
}