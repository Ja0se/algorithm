#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	freopen("snail.inp", "r", stdin);
	freopen("snail.out", "w", stdout);
	while (1) {
		int H, U, D, F;//High, Up, Down, Fatigue
		cin >> H >> U >> D >> F;
		if (H == 0)break;
		int Minus = U * F;
		int now = 0;
		int day = 0;
		H *= 100;
		U *= 100;
		D *= 100;
		while (1) {
			if (U > Minus * day)now += U - (Minus * day);
			day++;
			if (now > H) { cout << "success on day " << day << "\n"; break; }
			now -= D;
			if (now <= 0) { cout << "failure on day " << day << "\n"; break; }
			//if (U < Minus * day) { cout << "failure on day " << day << "\n"; break; }
		}
		/*	now < 0||U<=Minus*day ? cout << "failure on day " : cout << "success on day ";
			cout << day << "\n";*/
	}
	return 0;
}