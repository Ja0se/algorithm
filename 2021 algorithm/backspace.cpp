#include<iostream>
#include<string>
#pragma warning(disable:4996)

using namespace std;

string s, st;
int lens;
int lent;
int idx = 0;
int idxs = 0;
bool ch;
void dfs(int sidx, int stidx) {
	for (int i = sidx; i < lens; i++) {
		if (lent - stidx > lens - i)	return;
		if (s[i] == st[stidx]) {
			stidx++;
			if (stidx == lent) {
				if ((lens - i - 1) % 2 == 0) {
					ch = true;
				}
				return;
			}
		}
		else {
			i++;
		}
	}
}
int main(void) {
	freopen("backspace.inp", "r", stdin);
	freopen("backspace.out", "w", stdout);
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int t;
	cin >> t;
	string str;
	for (int T = 0; T < t; T++) {
		cin >> s >> st;
		idx = idxs = 0;
		ch = false;
		lens = s.length();
		lent = st.length();
		if (lent > lens) {
			cout << "NO\n";
			continue;
		}
		if (lens == lent) {
			if (s.compare(st) == 0) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
			continue;
		}
		for (int i = 0; i <= lens - lent; i++) {
			if (s[i] == st[0]) {
				dfs(i + 1, 1);
			}
			if (ch)break;
		}

		ch ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}

