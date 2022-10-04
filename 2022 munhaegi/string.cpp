#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string prev(string str) {
	int idx = str.length() - 1;
	int size = str.length();
	int len = 1;
	while (1) {
		if (idx == 0) {
			return "-1";
		}
		if (str[idx] >= str[idx - 1]) len++;
		else break;
		idx--;
	}
	string ans = "";
	for (int i = 0; i < idx - 1; i++)ans += str[i];
	string sorting = "";
	int ch=idx;
	for (int i = idx; i < size; i++) {
		if (str[idx - 1] > str[i])ch = i;
		else break;
	}
	ans += str[ch];
	for (int i = idx - 1; i < size; i++) {
		if (i == ch)continue;
		sorting += str[i];
	}
	sort(sorting.begin(), sorting.end());
	for (int i = sorting.length() - 1; i >= 0; i--) {
		ans += sorting[i];
	}
	return ans;
}
string after(string str) {
	int idx = str.length()-1;
	int len = 1;
	while (1) {
		if (idx == 0) {
			return "-1";
		}
		if (str[idx] <= str[idx-1]) len++;
		else break;
		idx--;
	}
	int size = str.length();
	string ans = "";
	string Sorting = "";
	for (int i = 0; i < idx - 1; i++)ans += str[i];
	int ch = size - 1;
	while (str[ch] <= str[idx - 1])ch--;
	ans += str[ch];
	for (int i = idx - 1; i < size; i++) {
		if (i == ch)continue;
		Sorting += str[i];
	}
	sort(Sorting.begin(), Sorting.end());
	for (int i = 0; i < Sorting.length(); i++)ans += Sorting[i];
	return ans;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("string.inp", "r", stdin);
	freopen("string.out", "w", stdout);
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		string str;
		cin >> str;
		string P = "";
		string A = "";
		P = prev(str);
		A = after(str);
		cout << P << " " << A << "\n";
	}
	return 0;
}