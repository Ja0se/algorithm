#include<iostream>
#include<cstring>

#define ll long long
#pragma warning(disable:4996)
using namespace std;
int n, k;
int arr[100001];
int temp[100001];
int ans[100001];
void air() {
	int tp;
	int pos;
	for (int i = 0; i < k; i++) {
		tp = temp[i];
		pos = arr[i]-1;
		if (ans[pos] > tp) ans[pos] = tp;
		int npos = i-1;
		while (1) {
			if (pos == 0)break;
			--pos;
			tp++;
			if (ans[pos] > tp) {
				ans[pos] = tp;
			}
			else {
				break;
			}
			if (npos>0&&pos == arr[npos]-1&&tp>temp[npos]) {
				break;
			}
			if(pos==arr[npos]-1){
				npos--;
			}
		}
		tp = temp[i];
		pos = arr[i]-1;
		npos = i + 1;
		while (1) {
			if (pos == n)break;
			++pos;
			tp++;
			if (ans[pos] > tp) {
				ans[pos] = tp;
			}
			else {
				break;
			}
			if (npos < k && pos == arr[npos]-1 && tp > temp[npos]) {
				break;
			}
			if (pos == arr[npos] - 1) {
				npos++;
			}
		}
	}
}
int main(void) {
	freopen("airconditiner.inp", "r", stdin);
	freopen("airconditiner.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> temp[i];
		}
		for (int i = 0; i < n; i++) {
			ans[i] = 1234567890;
		}
		air();
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}