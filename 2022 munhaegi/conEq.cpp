#pragma warning(disable:4996)
#include <iostream>
#define ll long long
using namespace std;
struct pa {
	ll a, b;
};
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
ll Diopantos(ll a, ll b) {
	//a*x+b*y=1;
	bool flag = 0;
	if (a < b) {
		flag = 1;
		ll tmp = a;
		a = b;
		b = tmp;
	}
	ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	ll q, r, s, t;
	while (r2 != 0) {
		q = r1 / r2;
		r = r1 % r2;
		s = s1 - q * s2;
		t = t1 - q * t2;
		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}
	return !flag ? s1 : t1;
}
int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("conEq.inp", "r", stdin);
	freopen("conEq.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		ll a, b, n;
		cin >> a >> b >> n;
		a %= n;
		b %= n;
		ll g;
		if (a > n) {
			g = gcd(a, n);
			if (b % g != 0) {
				cout << "-1\n";
				continue;
			}
			if (g != 1) {
				a /= g;
				b /= g;
				n /= g;
			}
		}
		else {
			g = gcd(n, a);
			if (b % g != 0) {
				cout << "-1\n";
				continue;
			}
			if (g != 1) {
				a /= g;
				b /= g;
				n /= g;
			}
		}
		ll d = Diopantos(a, n);
		
		b *= d;
		if (b < 0) {
			while (b < 0)b += n;
		}
		b %= n;
		cout << b << " " << b + n << "\n";
	}

}