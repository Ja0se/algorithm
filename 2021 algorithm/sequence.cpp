#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int n;
vector<int> c;
vector<int> s;
int arr[1001];
bool visited[1001];
int visitcnt;
int mini(int x,int idx) {
	int cnt = 0;
	for (int i = 0; i < idx; i++) {
		if(arr[i]<x)cnt++;
	}
	return cnt;
}
//void dfs() {
//	if (visitcnt == n) {
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		int num = mini(s[i],visitcnt);
//		if (num > c[visitcnt])break;
//		if (c[visitcnt] == num&&!visited[i]) {
//			arr[visitcnt] = s[i];
//			visited[i] = true;
//			visitcnt++;
//			dfs();
//			if (visitcnt == n)	return;
//			visitcnt--;
//			visited[i] = false;
//		}
//	}
//}
//over time limit
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	freopen("sequence.inp", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		c.push_back(a);
	}
	sort(s.begin(), s.end());
	for (int i = n - 1; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (visited[j])continue;
			if (cnt == c[i]) {
				arr[i] = s[j];
				visited[j] = true;
				break;
			}
			if (!visited[j]) {
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}