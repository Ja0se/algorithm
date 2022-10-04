#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#define ll long long
#pragma warning(disable:4996)
using namespace std;
struct pa {
	char color;
	int cnt;
};
int m;
vector<struct pa> v;
int arr[101];
int cnt;
//g는 상관 없고 r은 홀수번 이동, b는 짝수번 이동
bool visited[101];
//void hanoi(int n, int from, int by, int to) {
//	if (n == 1) {
//		cnt += v[1].cnt;
//		return;
//	}
//	else if (n == m) {
//		if (v[n].cnt == 1 || v[n].color == 'R' || v[n].color == 'G') {
//			hanoi(n - 1, from, to, by);
//			cnt += v[n].cnt;
//			visited[n] = true;
//			hanoi(n - 1, by, from, to);
//		}
//		else {
//			hanoi(n - 1, from, by, to);
//			cnt += v[n].cnt;
//			hanoi(n - 1, to, by, from);
//			cnt += v[n].cnt;  
//			visited[n] = true;
//			hanoi(n - 1, from, by, to);
//		}
//	}
//	else {
//		if (!visited[n + 1]) {
//			hanoi(n - 1, from, to, by);
//			cnt += v[n].cnt;
//			hanoi(n - 1, by, from, to);
//		}
//		else {		
//			if (v[n].cnt == 1 || v[n].color == 'B' || v[n].color == 'G') {
//				hanoi(n - 1, from, to, by);
//				cnt += v[n].cnt;
//				visited[n] = true;
//				hanoi(n - 1, by, from, to);
//			}
//			else {
//				hanoi(n - 1, from, by, to);
//				cnt += v[n].cnt;
//				hanoi(n - 1, to, by, from);
//				cnt += v[n].cnt;
//				visited[n] = true;
//				hanoi(n - 1, from, by, to);
//			}
//		}
//	}
//}


int main(void) {
	freopen("hanoi.inp", "r", stdin);
	freopen("hanoi.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> m;
		char a;
		int b;
		v.push_back({ '0',0 });
		cnt = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			cnt += b;
			arr[i + 1] = cnt;
			v.push_back({ a,b });
		}
		cnt = 0;
		int power = 1;
		for (int i = m; i > 0; i--) {
			char a = v[i].color;
			if (a == 'R') {//even
				if (v[i].cnt != 1 && power % 2 == 0) {
					cnt += (power + 1) * v[i].cnt;
					if (i == 1)cnt--;
					power *= 2;
					power++;
					continue;
				}
			}
			else if (a == 'B') {//odd
				if (v[i].cnt != 1 && power % 2 == 1) {
					cnt += (power + 1) * v[i].cnt;
					if (i == 1)cnt--;
					power *= 2;
					power++;
					continue;
				}
			}
			cnt += power * v[i].cnt;
			power *= 2;
		}
		//hanoi(m,1,2,3);
		cout << cnt << "\n";
		v.clear();
		memset(visited, false, sizeof(visited));
	}
	

	return 0;
}