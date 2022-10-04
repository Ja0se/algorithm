#include<iostream>
#include<cstring>


#define ll long long
#pragma warning(disable:4996)
using namespace std;

int p, k, s;
int dp[1000001][7];
int main(void) {
	freopen("coinmove.inp", "r", stdin);
	freopen("coinmove.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> p >> k >> s;
		int ans=0;
        bool ch = true;
        for (int i = 0; i < k; i++)dp[0][i] = -1;
        for (int i = p; i < s; i += p)
        {
            for (int j = 0; j < k; j++)
            {
                dp[i][j] = 1;
            }
        }

        for (int i = 1; i <= s; i++)
        {
            if (((i % p) == 0) && i != s)continue;
            for (int j = 0; j < k; j++)
            {
                if (i < k && j >= i) { dp[i][j] = -1; }
                else {
                    for (int l = 0; l < k; l++)
                    {
                        if (j == l)continue;//!same number
                        if (dp[i - (j + 1)][l] == 1) { 
                            dp[i][j] = -1; 
                            ch = false; 
                            break; 
                        }
                    }
                    if (ch == false) { 
                        ch = true; 
                        continue; 
                    }
                    dp[i][j] = 1;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < k; i++)
        {
            if (dp[s][i] == 1)
            {
                ch = false;
                result = s - (i + 1);
                break;
            }
        }
        !ch ? cout << result << "\n" : cout << "-1\n";
	}

	return 0;
}