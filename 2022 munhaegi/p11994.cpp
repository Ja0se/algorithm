#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;
int Father[50001];
int Color[50001];
bool ancestor(int x, int y) {
	while (Father[y] != 0) {
		if (Father[y] == x)return true;
		y = Father[y];
	}
	return false;
}
int same_ancestor(int n,int x, int y) {
	vector<bool> v(n+1, 0);
	int tx = x;
	int ty = y;
	int cnt = 0;
	while (Father[ty] != 0) {
		v[Father[ty]] = true;
		ty = Father[ty];
	}
	while (Father[tx] != 0) {
		if (v[Father[tx]]) { cnt = Father[tx]; break; }
		tx = Father[tx];
	}
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("p11994.inp", "r", stdin); freopen("p11994.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> Father[i + 1];
	}
	for (int i = 0; i < n; i++)cin >> Color[i+1];
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			cin >> d;
			if (b == c || ancestor(b, c)) break;
			Father[b] = c;
			Color[b] = d;
			break;
		case 2:
			cin >> d;
			if (ancestor(b, c)) {//b는 c의 조상
				while (c != b) {
					Color[c] = d;
					c = Father[c];
				}
			}
			else if (ancestor(c, b)) {//c는 b의 조상
				while (b != c) {
					Color[b] = d;
					b = Father[b];
				}
			}
			else {//공통부모 찾기
				int Parent = same_ancestor(n, b, c);
				if (Parent == 0)break;
				while (c != Parent) {
					Color[c] = d;
					c = Father[c];
				}
				while (b != Parent) {
					Color[b] = d;
					b = Father[b];
				}
			}
			break;
		case 3:
			int color = 0;
			int Edge = 0;
			bool visited[50001] = { 0, };
			if (ancestor(b, c)) {
				while (c != 0) {
					int C = Color[c];
					if (!visited[C]) {
						color++;
						visited[C] = true;
					}
					Edge++;
					if (Father[c] == b)break;
					c = Father[c];
				}
			}
			else if (ancestor(c, b)) {
				while (b != 0) {
					int C = Color[b];
					if (!visited[C]) {
						color++;
						visited[C] = true;
					}
					Edge++;
					if (Father[b] == c)break;
					b = Father[b];
				}
			}
			else {
				int Parent = same_ancestor(n, b, c);
				if (Parent == 0) {
					cout << "0 0\n";
					break;
				}
				while (c != 0) {
					int C = Color[c];
					if (!visited[C]) {
						color++;
						visited[C] = true;
					}
					Edge++;
					if (Father[c] == Parent)break;
					c = Father[c];
				}
				while (b != 0) {
					int C = Color[b];
					if (!visited[C]) {
						color++;
						visited[C] = true;
					}
					Edge++;
					if (Father[b] == Parent)break;
					b = Father[b];
				}
			}
			cout << Edge << " " << color << "\n";
			break;
		}
	}

	return 0;
}