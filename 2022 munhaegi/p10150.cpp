#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct pa {
	string str;
	int cur;
};
int n;
int Min;
string arr[25144];
bool check(string str, int i) {
	string b = arr[i];
	if (str.length() != b.length())return false;
	int cnt = 0;
	for (i = 0; i < b.length(); i++) {
		if (str[i] != b[i])cnt++;
		if (cnt > 1)return false;
	}
	if (cnt == 1)return true;
	return false;
}
vector<string> bfs(string start, string end,int cur) {
	vector<string> ret;
	bool visited[25144] = { 0, };
	int ans[25144] = { 0, };
	int len = start.length();
	queue<struct pa> q;
	q.push({ start,cur });
	ans[cur] = cur;
	visited[cur] = true;
	bool fin = false;
	int last=-1;
	while (!q.empty()) {
		string str = q.front().str;
		cur = q.front().cur;
		q.pop();
		if (str == end) {
			fin = true;
			break;
		}
		for (int i = 0; i < n; i++) {
			if (check(str, i)&&!visited[i]) {
				q.push({ arr[i],i });
				visited[i] = true;
				ans[i] = cur;
			}
		}
	}
	if(!fin)	return ret;
	while (1) {
		string str = arr[cur];
		ret.push_back(str);
		cur = ans[cur];
		if (str == start) break;
	}
	return ret;
}

int main(void) {
	//ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	freopen("p10150.inp", "r", stdin);
	freopen("p10150.out", "w", stdout);
	string str;
	
	while (1) {
		str = "";
		char a;
		while (1) {
			scanf("%c", &a);
			if (a == '\n')break;
			str += a;
		}
		if (str == "") {
			break;
		}
		arr[n] = str;
		n++;
	}
	string a, b;
	while (cin>>a>>b) {		
		if (a.length() != b.length()) {
			cout << "No solution.\n\n";
			continue;
		}
		else if (a == b) {
			cout << a << "\n" << b << "\n\n";
			continue;
		}
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == a) {
				cur = i;
				break;
			}
		}
		vector<string> ans = bfs(a, b, cur);
		reverse(ans.begin(), ans.end());
		if (ans.empty())cout << "No solution.\n";
		else for (int i = 0; i < ans.size(); i++)cout << ans[i] << "\n";
		cout << "\n";
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