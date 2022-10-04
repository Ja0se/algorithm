#include<iostream>
#include<string>
//#include<cstring>
#pragma warning(disable:4996)

using namespace std;

string str;

////rrbgbg rbbgrg
//bool visited[6];
//bool ch(int cnt) {
//	if (cnt == 3)return true;
//	int i = 6+cnt;
//	for (int j = 0; j < 6; j++) {
//		if (str[i] == str[j]&& str[17 - i] == str[5 - j]&&!visited[j]) {
//			visited[j] = true;
//			visited[5 - j] = true;
//			if (ch(cnt + 1))return true;
//			visited[j] = false;
//			visited[5 - j] = false;
//		}
//	}
//	return false;
//}
//some case not applicate

//hard coding
/*
123 456
142 536
135 246
154 326

263 415
231 645
214 365

312 564
351 624

421 653
462 513

541 632

*/
bool check() {
	if (str[0] == str[6] && str[1] == str[7] && str[2] == str[8] && str[3] == str[9] && str[4] == str[10] && str[5] == str[11])	return true;//123
	else if (str[0] == str[6] && str[3] == str[7] && str[1] == str[8] && str[4] == str[9] && str[2] == str[10] && str[5] == str[11])	return true;//142
	else if (str[0] == str[6] && str[2] == str[7] && str[4] == str[8] && str[1] == str[9] && str[3] == str[10] && str[5] == str[11])	return true;//135
	else if (str[0] == str[6] && str[4] == str[7] && str[3] == str[8] && str[2] == str[9] && str[1] == str[10] && str[5] == str[11])	return true;//154
	else if (str[1] == str[6] && str[5] == str[7] && str[2] == str[8] && str[3] == str[9] && str[0] == str[10] && str[4] == str[11])	return true;//263
	else if (str[1] == str[6] && str[2] == str[7] && str[0] == str[8] && str[5] == str[9] && str[3] == str[10] && str[4] == str[11])	return true;//231
	else if (str[1] == str[6] && str[0] == str[7] && str[3] == str[8] && str[2] == str[9] && str[5] == str[10] && str[4] == str[11])	return true;//214
	else if (str[2] == str[6] && str[1] == str[7] && str[5] == str[8] && str[0] == str[9] && str[4] == str[10] && str[3] == str[11])	return true;//326
	else if (str[2] == str[6] && str[0] == str[7] && str[1] == str[8] && str[4] == str[9] && str[5] == str[10] && str[3] == str[11])	return true;//312
	else if (str[2] == str[6] && str[5] == str[7] && str[4] == str[8] && str[1] == str[9] && str[0] == str[10] && str[3] == str[11])	return true;//365
	else if (str[2] == str[6] && str[4] == str[7] && str[0] == str[8] && str[5] == str[9] && str[1] == str[10] && str[3] == str[11])	return true;//351
	else if (str[3] == str[6] && str[4] == str[7] && str[5] == str[8] && str[0] == str[9] && str[1] == str[10] && str[2] == str[11])	return true;//456
	else if (str[4] == str[6] && str[2] == str[7] && str[5] == str[8] && str[0] == str[9] && str[3] == str[10] && str[1] == str[11])	return true;//536
	else if (str[1] == str[6] && str[3] == str[7] && str[5] == str[8] && str[0] == str[9] && str[2] == str[10] && str[4] == str[11])	return true;//246
	else if (str[3] == str[6] && str[0] == str[7] && str[4] == str[8] && str[1] == str[9] && str[5] == str[10] && str[2] == str[11])	return true;//415
	else if (str[5] == str[6] && str[3] == str[7] && str[4] == str[8] && str[1] == str[9] && str[2] == str[10] && str[0] == str[11])	return true;//645
	else if (str[4] == str[6] && str[5] == str[7] && str[3] == str[8] && str[2] == str[9] && str[0] == str[10] && str[1] == str[11])	return true;//564
	else if (str[5] == str[6] && str[1] == str[7] && str[3] == str[8] && str[2] == str[9] && str[4] == str[10] && str[0] == str[11])	return true;//624
	else if (str[3] == str[6] && str[1] == str[7] && str[0] == str[8] && str[5] == str[9] && str[4] == str[10] && str[2] == str[11])	return true;//421
	else if (str[5] == str[6] && str[4] == str[7] && str[2] == str[8] && str[3] == str[9] && str[1] == str[10] && str[0] == str[11])	return true;//653
	else if (str[3] == str[6] && str[5] == str[7] && str[1] == str[8] && str[4] == str[9] && str[0] == str[10] && str[2] == str[11])	return true;//462
	else if (str[4] == str[6] && str[0] == str[7] && str[2] == str[8] && str[3] == str[9] && str[5] == str[10] && str[1] == str[11])	return true;//513
	else if (str[4] == str[6] && str[3] == str[7] && str[0] == str[8] && str[5] == str[9] && str[2] == str[10] && str[1] == str[11])	return true;//541
	else if (str[5] == str[6] && str[2] == str[7] && str[1] == str[8] && str[4] == str[9] && str[3] == str[10] && str[0] == str[11])	return true;//632
	else return false;
}
bool finish() {
	char c = str[0];
	for (int i = 1; i < 12; i++) {
		if (c != str[i])return false;
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	freopen("cube.inp", "r", stdin);
	freopen("cube.out", "w", stdout);
	//pair must be located opposite
	while (1) {
		cin >> str;
		//memset(visited, false, sizeof(visited));
		check() == true ? cout << "TRUE\n" : cout << "FALSE\n";
		if (finish())break;
	}
	return 0;
}