#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

#pragma warning(disable:4996)

using namespace std;
int N, M, H;
int w[1001][1001];//i ->i,i+1   N+1,M
int h[1001][1001];//i  ->i,i+1   N,M+1
int tank[1001][1001];

bool visited[1001][1001];
bool ans[1001][1001];

void dfs(int x, int y,int weight) {
	//w[i][i],w[i+1][i]
	//h[i][i],h[i][i+1]
	//top 1, bottom2, left 3 right 4
	if (x < 0 || y < 0 || x >= N || y >= M)	return;
	if (tank[x][y] <= weight)return;
	tank[x][y] = weight;

	if (w[x][y] != -1) {//top
		/*if (x == 0) {                      중간 값이 갱신이 안됨  ->  바꿔주면서 진행?
			if (tank[x][y] > w[x][y]) {
				tank[x][y] = w[x][y];
				ans[x][y] = true;
			}
		}
		else {
			if (tank[x - 1][y] <= w[x][y] && tank[x][y] >= w[x][y]) {
				tank[x][y] = w[x][y];
				ans[x][y] = true;

			}
			else if (tank[x - 1][y] > w[x][y] && tank[x][y] > tank[x - 1][y]) {
				tank[x][y] = tank[x - 1][y];
				ans[x][y] = true;

			}
			if (!visited[x - 1][y] && x > 0) dfs(x - 1, y);

		}*/
		if (weight <= w[x][y]) {
			dfs(x - 1, y, w[x][y]);
		}
		else dfs(x - 1, y, weight);
	}
	if (w[x + 1][y] != -1) {//bottom
		/*if (x == N - 1) {
			if (tank[x][y] > w[x+1][y]) {
				tank[x][y] = w[x+1][y];
				ans[x][y] = true;
			}
		}
		else {
			if (tank[x + 1][y] <= w[x + 1][y] && tank[x][y] >= w[x + 1][y]) {
				tank[x][y] = w[x][y];
				ans[x][y] = true;

			}
			else if (tank[x + 1][y] > w[x][y] && tank[x][y] > tank[x + 1][y]) {
				tank[x][y] = tank[x + 1][y];
				ans[x][y] = true;

			}
			if (!visited[x + 1][y] && x < N) dfs(x + 1, y);

		}*/
		if (weight <= w[x+1][y]) {
			dfs(x + 1, y, w[x+1][y]);
		}
		else dfs(x + 1, y, weight);
	}
	if (h[x][y] != -1) {//left
		/*if (y == 0) {
			if (tank[x][y] > h[x][y]) {
				tank[x][y] = h[x][y];
				ans[x][y] = true;
			}
		}
		else {
			if (tank[x][y - 1] <= h[x][y] && tank[x][y] >= h[x][y]) {
				ans[x][y] = true;
				tank[x][y] = h[x][y];
			}
			else if (tank[x][y - 1] > w[x][y] && tank[x][y] > tank[x][y - 1]) {
				ans[x][y] = true;
				tank[x][y] = tank[x][y - 1];
			}
			if (!visited[x][y - 1] && y > 0) dfs(x, y - 1);
		}*/
		if (weight <= h[x][y]) {
			dfs(x, y-1, h[x][y]);
		}
		else dfs(x, y-1, weight);
	}
	if (h[x][y + 1] != -1) {//right
		/*if (y == M - 1) {
			if (tank[x][y] > h[x][y+1]) {
				ans[x][y] = true;
				tank[x][y] = h[x][y+1];
			}
		}
		else {
			if (tank[x][y + 1] <= h[x][y + 1] && tank[x][y] >= h[x][y + 1]) {
				ans[x][y] = true;
				tank[x][y] = h[x][y + 1];
			}
			else if (tank[x][y + 1] > w[x][y] && tank[x][y] > tank[x][y + 1]) {
				ans[x][y] = true;
				tank[x][y] = tank[x][y + 1];
			}
			if (!visited[x][y + 1] && y < M) dfs(x, y + 1);
		}*/
		if (weight <= h[x][y+1]) {
			dfs(x, y + 1, h[x][y+1]);
		}
		else dfs(x, y + 1, weight);
	}
	
}
int main(void) {
	freopen("watertank.inp", "r", stdin);
	freopen("watertank.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int sum = 0;
		cin >> N >> M >> H;
		//memset(visited, false, sizeof(visited));
		//memset(ans, false, sizeof(ans));
		memset(w, 0, sizeof(w));
		memset(h, 0, sizeof(h));
		memset(tank, 0, sizeof(tank));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tank[i][j] = H;
			}
		}
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < M; j++) {
				cin >> w[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M + 1; j++) {
				cin >> h[i][j];
			}
		}

		for (int i = 0; i < M; i++) {
			if (w[0][i]!=-1)dfs(0, i,w[0][i]);//top
			if (w[N][i]!=-1)dfs(N-1, i,w[N][i]);//bottom
		}
		for (int i = 0; i < N; i++) {
			if (h[i][0] != -1)dfs(i, 0,h[i][0]);//left
			if (h[i][M] != -1)dfs(i, M-1,h[i][M]);//right
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum += tank[i][j];
			}
		}
		cout << sum << "\n";
	}

	return 0;
}