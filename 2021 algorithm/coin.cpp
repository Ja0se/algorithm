#include<iostream>
#include<cstring>

#define ll long long
#pragma warning(disable:4996)
using namespace std;
int arr[3];
int coin[101][101][101];
void dp() {
	coin[1][0][0] = coin[0][1][0] = coin[0][0][1] = coin[1][1][1] = -1;
	coin[0][0][0] = coin[1][1][0] = coin[1][0][1] = coin[0][1][1] = 1;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				if (coin[i][j][k] == 0) {
					coin[i][j][k] = -1;
					if (i > 0 && coin[i - 1][j][k] == -1)	coin[i][j][k] = 1;
					if (i > 1 && coin[i - 2][j][k] == -1)	coin[i][j][k] = 1;
					if (i > 2 && coin[i - 3][j][k] == -1)	coin[i][j][k] = 1;

					if (j > 0 && coin[i][j - 1][k] == -1)	coin[i][j][k] = 1;
					if (j > 1 && coin[i][j - 2][k] == -1)	coin[i][j][k] = 1;
					if (j > 2 && coin[i][j - 3][k] == -1)	coin[i][j][k] = 1;

					if (k > 0 && coin[i][j][k - 1] == -1)	coin[i][j][k] = 1;
					if (k > 1 && coin[i][j][k - 2] == -1)	coin[i][j][k] = 1;
					if (k > 2 && coin[i][j][k - 3] == -1)	coin[i][j][k] = 1;
				}
			}
		}
	}
}
int main(void) {
	freopen("coin.inp", "r", stdin);
	freopen("coin.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	
	int T;
	cin >> T;
	dp();
	for (int t = 0; t < T; t++) {
		cin >> arr[0] >> arr[1] >> arr[2];
		cout << "(" << arr[0] << " " << arr[1] << " " << arr[2] << ") : " << coin[arr[0]][arr[1]][arr[2]]<<"\n";
	}

	return 0;
}