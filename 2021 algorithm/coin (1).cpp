#include<iostream>
#include<vector>
#define ll long long
#pragma warning(disable:4996)
using namespace std;
struct pa {
	int x, y;
};
int arr[3][100001];
int sum[3][100001];
int m;
ll Max;
ll Min;
vector<struct pa> v;
int Alice() {
	int idx;
	/*for (int i = 1; i <= m; i++) {
		if (Min >= sum[1][i] + sum[2][m] - sum[2][i - 1]) {
			Min = sum[1][i] + sum[2][m] - sum[2][i - 1];
			idx = i;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i <= idx) {
			arr[1][i] = 0;
		}
		else {
			arr[2][i] = 0;
		}
	}
	arr[2][idx] = 0;*/
	for (int i = 1; i <= m; i++) {
		if (sum[2][i-1] > sum[1][m] - sum[1][i]) {
			if (Min > sum[2][i-1]) {
				Min = sum[2][i-1];
				idx = i;
			}
		}
		else {
			if (Min > sum[1][m] - sum[1][i]) {
				Min = sum[1][m] - sum[1][i];
				idx = i;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i <= idx) {
			arr[1][i] = 0;
		}
		else {
			arr[2][i] = 0;
		}
	}
	arr[2][idx] = 0;
	return idx;
}

void Bob(int idx) {
	if (sum[2][idx - 1] < sum[1][m]) {
		Max = sum[1][m];
	}
	else {
		Max = sum[2][idx - 1];
	}
}

int main(void) {
	freopen("coin.inp", "r", stdin);
	freopen("coin.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	
	int T;
	cin >> T;
	int a,b;
	for (int t = 0; t < T; t++) {
		cin >> m;
		Max = 0;
		Min = 123456789012;
		for (int i = 1; i <= m; i++) {
			cin >> arr[1][i];
			sum[1][i] = sum[1][i - 1] + arr[1][i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> arr[2][i];
			sum[2][i] = sum[2][i - 1] + arr[2][i];
		}
		v.clear();
		a=Alice();
		for (int i = 1; i <= m; i++) {
			sum[1][i] = sum[1][i - 1] + arr[1][i];
			sum[2][i] = sum[2][i - 1] + arr[2][i];
		}
		Bob(a);
		cout << Max << "\n";
	}

	return 0;
}