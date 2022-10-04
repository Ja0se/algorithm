#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

vector<int> v1, v2;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	freopen("cross.inp", "r",stdin);
	freopen("cross.out", "w", stdout);
	int T;
	cin >> T;
	int N;
	for (int test = 0; test < T; test++) {
		cin >> N;
		v1.clear();
		v2.clear();
		int a;
		for (int i = 0; i < N; i++) {
			cin >> a;
			v1.push_back(a);
		}
		for (int i = 0; i < N; i++) {
			cin >> a;
			v2.push_back(a);
		}
		bool visited[10001] = { 0, };
		int index=0;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v1[i] == v2[j]) {
					index = j;
					break;
				}
			}
			visited[index] = true;
			int cnt = 0;
			for (int j = index + 1; j <=N; j++) {
				if (visited[j])cnt++;
			}
			ans += cnt;
		}
		cout << "Case "<<test+1<<": "<<ans << "\n";
	}
	
	
	return 0;

}