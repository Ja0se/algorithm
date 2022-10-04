#include<iostream>
#include<vector>
#pragma warning(disable:4996)
#define ll long long
using namespace std;

ll a, b, c, d, m;
ll n;
ll cmo[2][2];
void mul(ll x[2][2], ll y[2][2]) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cmo[i][j] = 0; // 행렬 초기화
			for (int k = 0; k < 2; k++)
				cmo[i][j] += (x[i][k] * y[k][j]);
			cmo[i][j] %= m;
		}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			x[i][j] = cmo[i][j];
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("fibonacci.inp", "r", stdin);
	freopen("fibonacci.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> a >> b >> c >> d >> m;
		ll ans[2][2] = { {1,0}, {0,1} };
		ll e[2][2] = { {1,1},{1,0} };
		while (a > 0) {
			if (a % 2 == 1) {
				mul(ans, e);
			}
			a /= 2;
			mul(e, e);
		}
		ll suma = ans[0][1];
		ans[0][0] = 1;
		ans[0][1] = 0;
		ans[1][0] = 0;
		ans[1][1] = 1;
		e[0][0] = 1;
		e[0][1] = 1;
		e[1][0] = 1;
		e[1][1] = 0;
		while (b > 0) {
			if (b % 2 == 1) {
				mul(ans, e);
			}
			b /= 2;
			mul(e, e);
		}
		suma *= ans[0][1];
		suma %= m;
		ans[0][0] = 1;
		ans[0][1] = 0;
		ans[1][0] = 0;
		ans[1][1] = 1;
		e[0][0] = 1;
		e[0][1] = 1;
		e[1][0] = 1;
		e[1][1] = 0;
		while (c > 0) {
			if (c % 2 == 1) {
				mul(ans, e);
			}
			c /= 2;
			mul(e, e);
		}
		ll sumb = ans[0][1];
		ans[0][0] = 1;
		ans[0][1] = 0;
		ans[1][0] = 0;
		ans[1][1] = 1;
		e[0][0] = 1;
		e[0][1] = 1;
		e[1][0] = 1;
		e[1][1] = 0;
		while (d > 0) {
			if (d % 2 == 1) {
				mul(ans, e);
			}
			d /= 2;
			mul(e, e);
		}
		sumb *= ans[0][1];
		sumb %= m;
		ll sum = suma + sumb;
		sum %= m;
		cout << sum << "\n";
	}
	return 0;
}