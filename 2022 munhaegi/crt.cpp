#pragma warning(disable:4996)
#include <iostream>
#include<vector>
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
vector<struct pa> v;
vector<bool> visited;
int N;
bool flag2;
struct pa find(ll A, ll B,int cnt) {
	struct pa ans;
	if (cnt == N||flag2) {
		flag2 = true;
		return { A, B };
	}
	for (int i = 1; i < N; i++) {
		ll a = A;
		ll b = B;
		if (!visited[i]) {
			ll r = v[i].a;
			ll m = v[i].b;
			
			
			//if (r == 0) {
			//	ll d = gcd(a, m);
			//	if (d != 1) {
			//		m /= d;
			//	}
			//	//a *= m;
			//	visited[i] = true;
			//	ans = find(A*m, b,cnt+1);
			//	if (flag2)return ans;
			//	visited[i] = false;
			//	continue;
			//}
			r -= b;
			if (r < 0) {
				ll s = r / m;
				s = -s;
				r += ++s * m;
			}
			r %= m;
			if (r == 0) {
				ll d = gcd(a, m);
				if (d != 1) {
					m /= d;
				}
				//a *= m;
				visited[i] = true;
				ans = find(A*m, B, cnt + 1);
				if (flag2)return ans;
				visited[i] = false;
				continue;
			}
			ll d;
			d = gcd(m, a);
			if (r % d != 0) {
				continue;
			}
			else if (d != 1) {
				a /= d;
				r /= d;
				m /= d;
			}
			d = Diopantos(a, m);
			r *= d;
			//while (r < 0)r += m;
			//r %= m;
			if (r == 0) {
				d = gcd(m, a);
				a /= d;
				m /= d;
				if (m == 1||a==m) {
					visited[i] = true;
					ans = find(a, b, cnt + 1);
					if (flag2)return ans;
					visited[i] = false;
				}
			}
			else if (r < 0) {
				ll s = r / m;
				s = -s;
				r += ++s * m;
			}
			r %= m;
			//b += A * r;
			//a *= m;
			visited[i] = true;
			ans=find(A*m, B+A*r,cnt+1);
			if (flag2) {
				return ans;
			}
			visited[i] = false;
		}
	}
	return { 0,0 };
}
int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("crt.inp", "r", stdin);
	freopen("crt.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		v.clear();
		visited.clear();
		visited.resize(N);
		visited[0] = true;
		flag2 = 0;
		for (int i = 0; i < N;i++) {
			ll p, q;
			cin >> p >> q;
			v.push_back({ p,q });
		}
		struct pa ans;
		ans = find(v[0].b, v[0].a, 1);
		if (!flag2) {
			cout << "-1\n";
		}
		else cout << ans.b << "\n";
		//cin >> b >> a;

		//while (N--) {
		//	ll r, m;
		//	cin >> r >> m;
		//	//as+b=r(mod3)
		//	r -= b;
		//	if (r < 0) {
		//		ll s = r / m;
		//		s = -s;
		//		r += ++s * m;
		//	}
		//	else if (r == 0) {
		//		ll d = gcd(a, m);
		//		if (d != 1) {
		//			m /= d;
		//		}
		//		a *= m;
		//		continue;
		//	}
		//	r %= m;
		//	ll d;
		//	d = gcd(r, a);
		//	if (m % d == 0 && d != 1) {
		//		a /= d;
		//		r /= d;
		//		m /= d;
		//	}
		//	d = Diopantos(a, m);
		//	r *= d;
		//	//while (r < 0)r += m;
		//	//r %= m;
		//	if (r == 0) {
		//		a > m ? d = gcd(a, m) : d = gcd(m, a);
		//		a /= d;
		//		m /= d;
		//		if (m == 1||a==m) {
		//			continue;
		//		}
		//		
		//	}
		//	else if (r < 0) {
		//		ll s = r / m;
		//		s = -s;
		//		r += ++s * m;
		//	}
		//	r %= m;
		//	b += a * r;
		//	a *= m;
		//}
		//cout << b << "\n";
	}

}