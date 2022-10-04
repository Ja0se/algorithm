#include<iostream>
#include<string>
#include<vector>
#pragma warning(disable:4996)
using namespace std;


//S > W > N > E left turn
vector<string> S, W, N, E;

void input(int turn, string s) {
	switch (turn) {
	case 1:
		S.push_back(s);
		break;
	case 2:
		W.push_back(s);
		break;
	case 3:
		N.push_back(s);
		break;
	case 4:
		E.push_back(s);
		break;
	}
	return;
}
bool check(char a, char b) {
	int ascii1 = a - '2';
	int ascii2 = b - '2';
	if (ascii1 < 8) {//number
		if (ascii2 < 8) {//both number
			if (ascii1 > ascii2)	return true;
			else	return false;
		}
		else return false;
	}
	else if (ascii1 == 34) {//T
		if (ascii2 < 8)	return true;//number true
		else	return false;
	}
	else if (ascii1 == 24) {//J
		if (ascii2 < 8 || ascii2 == 34)	return true;
		else	return false;
	}
	else if (ascii1 == 31) {//Q
		if (ascii2 < 8 || ascii2 == 34 || ascii2 == 24)	return true;
		else	return false;
	}
	else if (ascii1 == 25) {//K
		if (ascii2 < 8 || ascii2 == 34 || ascii2 == 24 || ascii2 == 31)	return true;
		else	return false;
	}
	else return true;//A
}
bool ch(string s1, string s2) {
	//C<D<S<H
	//2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < T < J < Q < K < A
	//2~9 = ASCII 50~57
	//T=84  J= 74  Q=81  K=75  A=65

	if (s1[0] == 'C') {
		if (s2[0] == 'C') {
			return check(s1[1], s2[1]);
		}
		else return false;
	}
	else if (s1[0] == 'D') {
		if (s2[0] == 'C') return true;
		else if (s2[0] == 'D') {
			return check(s1[1], s2[1]);
		}
		else return false;
	}
	else if (s1[0] == 'S') {
		if (s2[0] == 'C') return true;
		else if (s2[0] == 'D') return true;
		else if (s2[0] == 'S') {
			return check(s1[1], s2[1]);
		}
		else return false;
	}
	else {
		if (s2[0] == 'H') {
			return check(s1[1], s2[1]);
		}
		else return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	freopen("bridge.inp", "r", stdin);
	freopen("bridge.out", "w", stdout);
	char n;
	while (1) {
		cin >> n;
		if (n == '#')break;
		string s1, s2;
		cin >> s1 >> s2;
		S.clear();
		W.clear();
		N.clear();
		E.clear();
		int turn = 0;//S==1,W==2,N==3,E==4
		if (n == 'S')	turn = 2;
		else if (n == 'W')	turn = 3;
		else if (n == 'N')	turn = 4;
		else turn = 1;

		int len1 = s1.length();
		int len2 = s2.length();
		string s;
		for (int i = 0; i < len1; i+=2) {
			s = "";
			s += s1[i];
			s += s1[i + 1];
			input(turn, s);
			turn++;
			if (turn == 5)	turn = 1;
		}
		for (int i = 0; i < len2; i += 2) {
			s = "";
			s += s2[i];
			s += s2[i + 1];
			input(turn, s);
			turn++;
			if (turn == 5)	turn = 1;
		}

		//sort
		
		for (int i = 0; i < 12; i++) {//bubble
			for (int j = i + 1; j < 13; j++) {
				if (ch(S[i], S[j])) {
					string str = S[i];
					S[i] = S[j];
					S[j] = str;
				}
			}
		}
		for (int i = 0; i < 12; i++) {//bubble
			for (int j = i + 1; j < 13; j++) {
				if (ch(E[i], E[j])) {
					string str = E[i];
					E[i] = E[j];
					E[j] = str;
				}
			}
		}
		for (int i = 0; i < 12; i++) {//bubble
			for (int j = i + 1; j < 13; j++) {
				if (ch(N[i], N[j])) {
					string str = N[i];
					N[i] = N[j];
					N[j] = str;
				}
			}
		}
		for (int i = 0; i < 12; i++) {//bubble
			for (int j = i + 1; j < 13; j++) {
				if (ch(W[i], W[j])) {
					string str = W[i];
					W[i] = W[j];
					W[j] = str;
				}
			}
		}
		//print
		cout << "S:";
		for (int i = 0; i < 13; i++) {
			cout << " " << S[i];
		}
		cout << "\nW:";
		for (int i = 0; i < 13; i++) {
			cout << " " << W[i];
		}
		cout << "\nN:";
		for (int i = 0; i < 13; i++) {
			cout << " " << N[i];
		}
		cout << "\nE:";
		for (int i = 0; i < 13; i++) {
			cout << " " << E[i];
		}
		cout << "\n";
	}
	
	return 0;

}