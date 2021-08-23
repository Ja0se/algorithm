#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int INF = 1000000000;

struct pa {
	int cost, y;
};

int n, m;
int arr[1001];
int route[1001];
vector<struct pa> v[1001];

priority_queue<pair<int, int> > pq;

vector<int> ans;

int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m;
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x].push_back({ z,y });
	}
	cin >> x >> y;

	for (int i = 1; i <= n; i++) {
		arr[i] = INF;
	}
	arr[x] = 0;
	pq.push({ 0,x });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > arr[cur])continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int arrive = v[cur][i].y;
			int ccost = cost + v[cur][i].cost;
			if (arr[arrive] > ccost) {
				route[arrive] = cur;
				arr[arrive] = ccost;
				pq.push({ -ccost,arrive });
			}
		}
	}
	cout << arr[y] << "\n";
	int temp = y;
	while (temp) {
		ans.push_back(temp);
		temp = route[temp];
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	return 0;
}
