#pragma warning(disable:4996)
#include<iostream>
#include<string>
#define endl "\n"

using namespace std;
string str[51];
int n, m;
bool horizontally(int x,int y, string s) {
	string com = "";
	string tmp = "";
	int len = s.length();
	int ty = y;
	for (int i = 0; i < len; i++) {
		if (y + i == m) y = ( - 1)* i;
		com += str[x][y + i];
		tmp += str[x][ty - i];
		if (ty - i == 0) ty = m + i;
	}
	
	if (com == s) return true;
	if (tmp == s)return true;
	return false;
}//col
bool vertically(int x, int y, string s) {
	string com = "";
	string tmp = "";
	int len = s.length();
	int tx = x;
	for (int i = 0; i < len; i++) {
		if (x + i == n) x = (-1) * i;
		com += str[x+i][y];
		tmp += str[tx-i][y];
		if (tx - i == 0) tx = n + i;
	}

	if (com == s) return true;
	if (tmp == s)return true;
	return false;
}//row
bool diagonally(int x, int y, string s) {
	string com = "";
	string tmp = "";
	int len = s.length();
	int ty = y;
	int sy = y;
	int sx = x;
	int tx = x;
	for (int i = 0; i < len; i++) {
		if (sx + i == n) sx = (-1) * i;
		if (sy + i == m) sy = (-1) * i;
		com += str[sx+i][sy + i];
		tmp += str[tx-i][ty - i];
		if (ty - i == 0) ty = m + i;
		if (tx - i == 0) tx = n + i;
	}

	if (com == s) return true;
	if (tmp == s)return true;
	com = "";
	tmp = "";
	tx = x;
	sx = x;
	sy = y;
	ty = y;
	for (int i = 0; i < len; i++) {
		if (tx + i == n) tx = (-1) * i;
		if (sy + i == m) sy = (-1) * i;
		com += str[sx - i][sy + i];
		tmp += str[tx + i][ty - i];
		if (sx - i == 0) sx = n + i;
		if (ty - i == 0) ty = m + i;
	}
	if (com == s) return true;
	if (tmp == s)return true;

	return false;
}//row,col
bool search(int x, int y, string s) {
	if (horizontally(x, y, s) || vertically(x, y, s) || diagonally(x, y, s))return true;
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("1.inp", "r", stdin);
	freopen("1.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)cin >> str[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				str[i][j] = tolower(str[i][j]);
			}
		}
		int k;
		cin >> k;
		string s;
		for (int i = 0; i < k; i++) {
			cin >> s;
			for (int j = 0; j < s.length(); j++) {
				s[j] = tolower(s[j]);
			}
			bool ch = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (str[i][j] == s[0]) {
						if (search(i, j, s)) {
							cout << i + 1 << " " << j + 1 << "\n";
							ch = true;
							break;
						}
					}
				}
				if (ch)break;
			}

		}
		cout << "\n";
	}
	return 0;
}


/*
4 2 -> 12
*/