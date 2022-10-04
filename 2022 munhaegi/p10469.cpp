#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	freopen("p10469.inp", "r", stdin);
	freopen("p10469.out", "w", stdout);
	long long n, m;
	string a, b;
	while (1) {
		cin >> n >> m;
		if (cin.eof())break;
		long long Xor = n ^ m;
		cout << Xor<<"\n";
	}


	return 0;
}



/*
6=0110
7=0111
and 0110
or 0111
ans  0001


*/