#include<iostream>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
int n;
vector<string> str;
//a~z 97~ 122
//A~Z 65~90
//* 42
//? 63
char goods[28];
int glen;
char p[1002];
char s[1002];
int plen, slen;
bool goodc(char a) {
	for (int i = 0; i < glen; i++) {
		if (goods[i] == a) {
			return true;
		}
	}
	return false;
}
bool ch() {
	int idx = 0;
	bool star = false;
	bool visited[1001] = { 0, };
	int len;
	slen > plen ? len = slen : len = plen;
	while (idx < len) {
		if (p[idx] == '?') {
			if (!goodc(s[idx]))	return false;
		}
		else if (p[idx] == '*') {
			star = true;
			break;
		}
		else {
			if (p[idx] == '\0') {
				break;
			}
			if (p[idx] != s[idx])	return false;
		}
		visited[idx] = true;
		idx++;
	}
	int rdx = slen - 1;
	int ridx = plen - 1;
	bool ans = false;
	if (!star) {
		if (slen != plen)	return false;
		return true;
	}
	else {//*ÀÌ ÀÖÀ»¶§
		while (ridx > idx) {
			if (p[ridx] == '?') {
				if (visited[rdx])return false;
				if (!goodc(s[rdx]))	return false;
			}
			else if (p[ridx] == '*') {
				break;
			}
			else if (p[ridx] != s[rdx])	return false;
			else if (p[ridx] == s[rdx]) {
				if (visited[rdx])return false;
			}
			visited[rdx] = true;
			rdx--;
			ridx--;
		}
		if (idx <= rdx) {
			for (int i = idx; i <= rdx; i++) {
				if (!goodc(s[i]))ans = true;
			}
		}
		else if (idx > rdx)	ans = true;//ºóÄ­

		return ans;
	}

	return true;
}
int main(void) {
	freopen("exam.inp", "r", stdin);
	freopen("exam.out", "w", stdout);
	int T;
	scanf("%d ", &T);
	for (int test = 1; test <= T; test++) {
		char a;
		int cnt = 0;
		while (1) {
			scanf("%c", &a);
			if (a == '\n')break;
			goods[cnt] = a;
			cnt++;
		}
		glen = cnt;
		cnt = 0;
		a = ' ';
		while (1) {
			scanf("%c", &a);
			if (a == '\n')break;
			p[cnt] = a;
			cnt++;
		}
		plen = cnt;
		scanf("%d ", &n);

		cout << "Test Case: #" << test << "\n";
		for (int i = 0; i < n; i++) {
			int j = 0;
			a = ' ';
			while (1) {
				scanf("%c", &a);
				if (a == '\n' || a == '\0')break;
				s[j] = a;
				j++;
			}
			slen = j;
			s[slen] = '\0';
			if (ch()) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}

	}
	return 0;
}