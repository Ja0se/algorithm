#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

struct pa {
	int x, y,val,idx;
};
bool compareX(const struct pa& a, const struct pa& b) {
	return a.x < b.x;
}
bool compareY(const struct pa& a, const struct pa& b) {
	return a.y < b.y;
}
int arr[4001][4001];
int n;
int totally;
int partially;
int notcovered;
//map  [100000000][100000000]100m*100m stack overflow  -> 2000 2000으로 변경  ->4000, 4000 으로 바꿈
vector<struct pa> v,ans;//input index

//덮음
//ㄷ자로 덮음
//가운데 ㅁ안에 ㅁ 으로 덮음
void sorting() {
	//x sort
	sort(v.begin(), v.end(), compareX);
	v[0].val = 0;
	for (int i = 1; i < 2 * n; i++) {
		if (v[i - 1].x != v[i].x) v[i].val = v[i-1].val+1;
		else	v[i].val = v[i-1].val;
	}
	for (int i = 0; i < 2 * n; i++) {
		v[v[i].idx].x = v[i].val;
	}
	for (int i = 0; i < 2 * n; i++) {
		ans[i].x = v[i].x;
	}

	//y sort
	sort(v.begin(), v.end(), compareY);
	v[0].val = 0;
	for (int i = 1; i < 2 * n; i++) {
		if (v[i - 1].y != v[i].y) v[i].val = v[i-1].val+1;
		else	v[i].val = v[i-1].val;
	}
	for (int i = 0; i < 2 * n; i++) {
		v[v[i].idx].y = v[i].val;
	}
	for (int i = 0; i < 2 * n; i++) {
		ans[i].y = v[i].y;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	freopen("paper.inp", "r", stdin);
	freopen("paper.out", "w", stdout);
	cin >> n;
	int a, b, c, d;
	int x, y, w, h;
	v.resize(2*n);
	ans.resize(2*n);
	for (int i = 0; i < n; i++) {
		cin >> a>>b>>c>>d;//x,y,w,h
		c += a;//x+w
		d += b;//y+h
		v[i].x = a;
		v[i].y = b;
		v[i].idx = i;
		v[i+n].x = c;
		v[i+n].y = d;
		v[i+n].idx = i+n;
		ans[i].idx = i;
		ans[i + n].idx = i + n;
	}
	int cnt = 0;
	sorting();
	for (int i = 0; i < n; i++) {
		x = ans[i].x;
		y = ans[i].y;
		w = ans[i + n].x;
		h = ans[i + n].y;
		for (int j = x; j < w; j++) {
			for (int k = y; k < h; k++) {
				arr[j][k] = i;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cnt = 0;
		x = ans[i].x;
		y = ans[i].y;
		w = ans[i + n].x;
		h = ans[i + n].y;
		int Max = (w - x) * (h - y);
		for (int j = x; j < w; j++) {
			for (int k = y; k < h; k++) {
				if (arr[j][k] == i)cnt++;
			}
		}
		if (cnt == Max)notcovered++;
		else if (cnt == 0)totally++;
		else partially++;
	}
	cout << totally << " " << partially << " " << notcovered;
	return 0;
}