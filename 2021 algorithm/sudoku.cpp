#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
int arr[10][10];
char tmp[10][10];
bool c;
vector<int> v[9];
bool ch[10][10];
bool ro[10][10];
bool co[10][10];
bool check(int cnt, int num)
{
	if (ro[cnt / 9][num])return false;
	if (co[num][cnt % 9])return false;
	int a = tmp[cnt / 9][cnt % 9] - 'a';
	if (ch[a][num])return false;
	return true;
}
void print() {
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << arr[i][j] << " ";
		} 
		cout << "\n";
	}
}
void dfs(int cnt) {
	if (cnt == 81){
		print();
		c = true;
		return;
	}
	if (arr[cnt / 9][cnt % 9] == 0){
		for (int i = 1; i <= 9; i++){
			int a = tmp[cnt / 9][cnt % 9] - 'a';
			if (check(cnt, i)) {
				arr[cnt / 9][cnt % 9] = i;
				ch[a][i] = true;
				ro[cnt / 9][i] = true;
				co[i][cnt % 9] = true;
				dfs(cnt + 1);
				if (c)return;
				ch[a][i] = false;
				ro[cnt / 9][i] = false;
				co[i][cnt % 9] = false;
				arr[cnt / 9][cnt % 9] = 0;
			}
			if (c)return;
		}
	}
	else if(!c)	dfs(cnt + 1);
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("sudoku.inp", "r", stdin);
	freopen("sudoku.out", "w", stdout);
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		cout << "Test Case No: " << T + 1 << "\n";
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> arr[i][j];
				
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++) {
				cin >> tmp[i][j];
				int a = tmp[i][j] - 'a';
				v[a].push_back(i * 9 + j);
				if (arr[i][j] != 0) {
					ro[i][arr[i][j]] = true;
					co[arr[i][j]][j] = true;
					ch[a][arr[i][j]] = true;
				}
			}
		}
		c = false;
		dfs(0);
		cout << "\n";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				ro[i][j] = co[i][j] = ch[i][j] = false;
			}
			v[i].clear();
		}
	}
	return 0;
}

