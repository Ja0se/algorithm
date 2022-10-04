#pragma warning(disable:4996)
#include<iostream>

using namespace std;
#define ll long long
int arr[100001];
int mer[100001];
ll cnt;
int n;
void merge(int lo, int mid, int hi) {
	int l = lo, m = mid + 1, h = lo;
	while (l <= mid && m <= hi) {
		if (arr[l] <= arr[m]) {
			mer[h] = arr[l];
			h++;
			l++;
		}
		else {
			cnt += mid - l + 1;
			mer[h] = arr[m];
			h++; m++;
		}
	}
	if (l <= mid) {
		for (int i = l; i <= mid; i++) {
			mer[h] = arr[i];
			h++;
		}
	}
	else {
		for (int i = m; i <= hi; i++) {
			mer[h] = arr[i];
			h++;
		}
	}
	for (int i = lo; i <= hi; i++)arr[i] = mer[i];
}

void mergesort(int lo, int hi) {
	if (lo < hi) {
		int mid = (lo + hi) / 2;
		mergesort(lo, mid);
		mergesort(mid + 1, hi);
		merge(lo, mid, hi);
	}
}


int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("inv.inp", "r", stdin);
	freopen("inv.out", "w", stdout);
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		cin >> n;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		mergesort(1, n);
		cout << cnt << "\n";
	}
	return 0;
}

