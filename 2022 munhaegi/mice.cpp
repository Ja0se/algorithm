#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;

struct pa {
	int x, y;
	int cost;
	int level;
};
int n, K, h, m;
vector<struct pa> v, hole, mice, micetohole[251];
bool visited[251];

ll ccw(struct pa a, struct pa b, struct pa c) {
	ll r= 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y - 1LL * a.y * b.x - 1LL * b.y * c.x - 1LL * c.y * a.x;
	return r;
}
int direction(struct pa a, struct pa b, struct pa c) {
	if (ccw(a, b, c) < 0)return -1;
	if (ccw(a, b, c) > 0)return 1;
	return 0;
}
bool intersectProp(struct pa a, struct pa b, struct pa c, struct pa d) {
	return direction(a, b, c) * direction(a, b, d) < 0 && direction(c, d, a) * direction(c, d, b) <= 0;
}

int cnt;
vector<int> Inhole[251];
bool dfs(int L) {
	/*int Min ;
	for (int i = 0; i < micetohole[L].size(); i++) {
		Min = min(mice[L].cost,min(micetohole[L][i].y,hole[micetohole[L][i].x].cost));
		mice[L].cost -= Min;
		micetohole[L][i].y -= Min;
		hole[micetohole[L][i].x].cost -= Min;
		if (Min != 0) {
			return true;;
		}
	}*/
	visited[L] = 1;
	for (int i = 0; i < micetohole[L].size(); i++) {
		if (Inhole[micetohole[L][i].x].size() < K) {
			Inhole[micetohole[L][i].x].push_back(L);
			return true;
		}
		else {
			for (int j = 0; j < Inhole[micetohole[L][i].x].size(); j++) {
				int cur = Inhole[micetohole[L][i].x][j];
				if (!visited[cur] && dfs(cur)) {
					Inhole[micetohole[L][i].x][j] = L;//change another mice
					return true;
				}
			}
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("mice.inp", "r", stdin);
	freopen("mice.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		mice.clear();
		hole.clear();
		v.clear();
		cin >> n >> K >> h >> m;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b ,0,-1 });
		}
		for (int i = 0; i < h; i++) {
			int a, b;
			cin >> a >> b;
			hole.push_back({ a,b ,K,i });
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			Inhole[i].clear();
			cin >> a >> b;
			micetohole[i].clear();
			mice.push_back({ a,b ,1,i });
			for (int j = 0; j < h; j++) {
				bool ch = false;
				for (int k = 0; k < n; k++) {
					int next = (k + 1) % n;
					if (intersectProp(v[k], v[next], hole[j], mice[i])) {
						ch = true;
						break;
					}
				}
				if (!ch)micetohole[i].push_back({ j,1,0,0 });//i to j cost = 1

			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (dfs(i)) {
				for (int j = 0; j < m; j++)visited[j] = 0;
				ans++;
			}
		}
		ans >= m ? cout << "Possible\n" : cout << "Impossible\n";
	}
	return 0;
}


/*

입력 순서에 따라 지금 틀린 값을 보인다.
Input 1을 봤을 때 쥐 1번과 2번을 바꾸면 틀린 값이 나옴
*/