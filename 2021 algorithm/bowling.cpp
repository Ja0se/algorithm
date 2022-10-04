#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	freopen("bowling.inp", "r",stdin);
	freopen("bowling.out", "w", stdout);
	int T;
	cin >> T;
	int N;
	int a, b;
	for (int test = 0; test < T; test++) {
		int score = 0;
		int arr[10][3] = { 0, };
		for (int i = 0; i < 9; i++) {
			cin >> a;
			arr[i][0] = a;
			if (a == 10)	continue;
			cin >> b;
			arr[i][1] = b;
		}
		cin >> a;
		arr[9][0] = a;
		if (a == 10) {
			cin >> a>>b;
			arr[9][1] = a;
			arr[9][2] = b;
		}
		else {
			cin >> b;
			arr[9][1] = b;
			if (a + b == 10) {
				cin >> arr[9][2];
			}
		}


		for (int i = 0; i < 8; i++) {
			if (arr[i][0] == 10) {//strike
				score += arr[i][0] + arr[i + 1][0];
				if (arr[i + 1][0] == 10) {
					score += arr[i + 2][0];
				}
				else {
					score += arr[i + 1][1];
				}
			}
			else if (arr[i][0] + arr[i][1] == 10) {//spare;
				score += 10 + arr[i + 1][0];
			}
			else {
				score += arr[i][0] + arr[i][1];
			}
		}
		if (arr[8][0] == 10) {//9frame stike
			score += 10 + arr[9][0] + arr[9][1];
		}
		else if (arr[8][1] + arr[8][0] == 10) {//9frame spare
			score += 10 + arr[9][0];
		}
		else {
			score += arr[8][0] + arr[8][1];
		}
		score += arr[9][0] + arr[9][1] + arr[9][2];



		cout << score << "\n";
	}
	
	
	return 0;

}