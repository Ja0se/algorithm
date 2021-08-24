#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct pa {
	int x, y;
	int shape;
};
//shpae == 0 horizontal / 1 vertical / 2 diagonal
int n;
int arr[17][17];
int cnt;
queue<struct pa> q;

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	q.push({ 1,2,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int shape = q.front().shape;
		q.pop();
		if (x == n && y == n) {
			cnt++;
			continue;
		}
		if (shape == 0) {//가로
			if (y < n && arr[x][y + 1] == 0) q.push({ x,y + 1,0 });
			if (x < n && y < n && arr[x + 1][y + 1] == 0) {
				if (arr[x][y + 1] == 0 && arr[x + 1][y] == 0)q.push({ x + 1,y + 1,2 });
			}
		}
		else if (shape == 1) {//세로
			if (x < n && y < n && arr[x + 1][y + 1] == 0) {
				if (arr[x][y + 1] == 0 && arr[x + 1][y] == 0)q.push({ x + 1,y + 1,2 });
			}
			if (x < n && arr[x + 1][y] == 0) q.push({ x + 1,y,1 });
		}
		else {//대각선
			if (x < n && y < n && arr[x + 1][y + 1] == 0) {
				if (arr[x][y + 1] == 0 && arr[x + 1][y] == 0)q.push({ x + 1,y + 1,2 });
			}
			if (y < n && arr[x][y + 1] == 0) q.push({ x,y + 1,0 });
			if (x < n && arr[x + 1][y] == 0) q.push({ x + 1,y,1 });
		}

	}
	cout << cnt;
	return 0;
}