#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
struct pa {
	int dist, y;
};
struct compare {
	bool operator()(struct pa& a, struct pa& b) {
		if (a.dist == b.dist)	return	a.y > b.y;
		return a.dist > b.dist;
	}
};
int n, m, r;
int arr[101];
vector<struct pa> v[101];
priority_queue<struct pa, vector<struct pa>, compare> pq;

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		v[a].push_back({ l,b });
		v[b].push_back({ l,a });
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int map[101] = { 0, };
		for (int j = 0; j < v[i].size(); j++) {
			if (map[v[i][j].y] == 0 || map[v[i][j].y] > v[i][j].dist) {
				map[v[i][j].y] = v[i][j].dist;
			}
			pq.push(v[i][j]);

		}
		while (!pq.empty()) {
			int dist = pq.top().dist;
			int cur = pq.top().y;
			pq.pop();
			if (dist > m)continue;
			if (map[cur] != 0 && map[cur] < dist)	continue;
			for (int j = 0; j < v[cur].size(); j++) {
				int ndist = dist + v[cur][j].dist;
				int next = v[cur][j].y;
				if (next == i || ndist > m)continue;
				if (map[next] == 0 || ndist < map[next]) {
					map[next] = ndist;
					pq.push({ ndist,next });
				}
			}
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (map[j] <= m && map[j] != 0)cnt += arr[j];
		}
		cnt += arr[i];
		if (Max < cnt)Max = cnt;
	}
	cout << Max;
	return 0;
}