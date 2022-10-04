#include<iostream>
#include<vector>
#include<deque>
#include<cmath>
#include<algorithm>
#define ll long long
#pragma warning(disable:4996)
using namespace std;
int Min;
vector<int> v;
int n;
deque<int> dq;

int main(void) {
	freopen("jump.inp", "r", stdin);
	freopen("jump.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		v.clear();
		int a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end(), greater<int>());
		dq.push_back(v[0]);
		dq.push_back(v[1]);
		dq.push_front(v[2]);
		for (int i = 3; i < n; i++) {
			int front = dq.front();
			int back = dq.back();
			if (front - v[i] < back - v[i]) {
				dq.push_back(v[i]);
			}
			else dq.push_front(v[i]);
		}
		int Max = 0;
		while (1) {
			int m = dq.front();
			dq.pop_front();
			if (dq.empty())break;
			Max = max(Max,abs(m - dq.front()));
		}
		cout << Max << "\n";
	}

	return 0;
}