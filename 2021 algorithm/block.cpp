#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct pa {
	int x, y, w, h, idx;
};
bool xcom(const struct pa& a, const struct pa& b) {
	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {
		if (a.y < b.y) {
			return true;
		}
	}
	return false;
}

bool ycom(const struct pa& a, const struct pa& b) {
	if (a.y < b.y) {
		return true;
	}
	else if (a.y == b.y) {
		if (a.x < b.x) {
			return true;
		}
	}
	return false;
}

int n;
int arr[10001][4];
vector<struct pa> v;

int downward() {
	int cnt = 0;
	sort(v.begin(), v.end(), ycom);
	for (int i = 0; i < n; i++) {
		int Max = 0;
		int id = v[i].idx;
		for (int j = 0; j < i; j++) {
			int idx = v[j].idx;
			if (!(arr[idx][2] <= arr[id][0]) && !(arr[id][2] <= arr[idx][0]) && Max < arr[idx][3]) {// arr[idx][3] < arr[id][1]
				Max = arr[idx][3];
			}
		}
		if (Max < arr[id][1]) {
			cnt++;
			arr[id][3] = Max + v[i].h;
			arr[id][1] = v[i].y = Max;
		}
	}
	return cnt;
}
int leftward() {
	int cnt = 0;
	sort(v.begin(), v.end(), xcom);
	for (int i = 0; i < n; i++) {
		int Max = 0;
		int id = v[i].idx;
		for (int j = 0; j < i; j++) {
			int idx = v[j].idx;
			if (!(arr[idx][3] <= arr[id][1]) && !(arr[id][3] <= arr[idx][1]) && Max < arr[idx][2]) {//&& arr[idx][2] < arr[id][0]
				Max = arr[idx][2];
			}
			/*if (arr[idx][3] <= arr[id][1])	continue;
			else if (arr[id][3] <= arr[idx][1])	continue;
			if (Max < arr[idx][2]) {
				Max = arr[idx][2];
			}*/
		}
		if (Max < arr[id][0]) {
			cnt++;
			arr[id][2] = Max + v[i].w;
			v[i].x = arr[id][0] = Max;
		}
	}
	return cnt;
}
void compact() {
	int cnt = 0;
	while (1) {
		if (downward() == 0)	return;
		if (leftward() == 0)	return;
	}
}
void Input() {
	v.clear();
	int x, y, p, q;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> p >> q;
		arr[i][0] = x;
		arr[i][1] = y;
		arr[i][2] = p;
		arr[i][3] = q;
		v.push_back({ x,y,p - x,q - y,i });
	}

}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("1.inp", "r", stdin);
	freopen("1.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		Input();
		compact();
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; i++) {
			x = max(x, arr[i][2]);
			y = max(y, arr[i][3]);
		}
		cout << x << " " << y << "\n";
	}

	return 0;
}