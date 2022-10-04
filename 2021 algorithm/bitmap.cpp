#include<iostream>
#include<string>
#include<cstring>
#pragma warning(disable:4996)
#define ll long long
using namespace std;
//1 black  0 white
string str[1001];
char ans[201][201];
string arr;
//Â¦¼ö Â¦¼ö  --> µ¿ÀÏ
//Â¦¼ö È¦¼ö  --> ¿ŞÂÊ+1
//È¦¼ö Â¦¼ö  --> À§ÂÊ+1
int checkm(int x,int y,int w, int h) {//0 white 1 balck 2 D
	int black = 0;
	int white = 0;
	for (int i = x; i < x+w; i++) {
		for (int j = y; j < y+h; j++) {
			if (ans[i][j] == '1') {
				black++;
			}
			else if (ans[i][j] == '0') {
				white++;
			}
			if (black != 0 && white != 0) {
				return 2;
			}
		}
	}
	if (black == 0)	return 0;
	else  if (white == 0)	return 1;
	return 2;
}
void halfB(int x,int y, int w, int h) {//BÀÏ¶§ D·Î ¹Ù²Ù´Â °úÁ¤
	int m = checkm(x, y, w, h);
	if (m == 0) {//all white
		/*for (int i = x; i < x + w; i++) {
			for (int j = y; j < y + h; j++) {
				ans[i][j] = '0';
			}
		}*/
		arr += '0';
	}
	else if (m == 1) {// all black
		arr += '1';
	}
	else {//D
		arr += 'D';
		if (w != 1 && h != 1) {
			if (w % 2 == 0 && h % 2 == 0) {//µÑ´Ù Â¦¼ö
				halfB(x, y, (w / 2), (h / 2));//top left
				halfB(x, y + (h / 2), (w / 2), (h / 2));//top right
				halfB(x + (w / 2), y, (w / 2), (h / 2));//bottom left
				halfB(x + (w / 2), y + (h / 2), (w / 2), (h / 2));//bottom right
			}
			else if (w % 2 == 0 && h % 2 == 1) {//¿ŞÂÊ +1
				halfB(x, y, (w / 2), (h / 2) + 1);//top left
				halfB(x, y + (h / 2) + 1, (w / 2), (h / 2));//top right
				halfB(x + (w / 2), y, (w / 2), (h / 2) + 1);//bottom left
				halfB(x + (w / 2), y + (h / 2) + 1, (w / 2), (h / 2));//bottom right
			}
			else if (w % 2 == 1 && h % 2 == 0) {//À§ÂÊ +1
				halfB(x, y, (w / 2) + 1, (h / 2));//top left
				halfB(x, y + (h / 2), (w / 2) + 1, (h / 2));//top right
				halfB(x + (w / 2) + 1, y, (w / 2), (h / 2));//bottom left
				halfB(x + (w / 2) + 1, y + (h / 2), (w / 2), (h / 2));//bottom right
			}
			else {//µÑ´Ù È¦¼ö
				halfB(x, y, (w / 2) + 1, (h / 2)+1);//top left
				halfB(x, y + (h / 2)+1, (w / 2) + 1, (h / 2));//top right
				halfB(x + (w / 2) + 1, y, (w / 2), (h / 2)+1);//bottom left
				halfB(x + (w / 2) + 1, y + (h / 2)+1, (w / 2), (h / 2));//bottom right
			}
		}
		else if (w == 1 && h != 1) {
			if (h % 2 == 1) {//¿ŞÂÊ+1
				halfB(x, y, 1, (h / 2)+1);
				halfB(x, y + (h / 2) + 1, 1, (h / 2));
			}
			else {
				halfB(x, y, 1, (h / 2));
				halfB(x, y + (h / 2), 1, (h / 2));
			}
		}
		else if (w != 1 && h == 1) {
			if (w % 2 == 1) {
				halfB(x, y, (w/2)+1, 1);
				halfB(x + (w / 2) + 1, y, (w / 2), 1);
			}
			else {
				halfB(x, y, (w / 2), 1);
				halfB(x + (w / 2), y, (w / 2), 1);
			}
		}
	}
}
void halfD(int x, int y, int w, int h) {
	if (arr.length()==0)	return;
	if (arr[0] == 'D') {
		arr.erase(0, 1);
		if (w != 1 && h != 1) {
			if (w % 2 == 0 && h % 2 == 0) {//µÑ´Ù Â¦¼ö
				halfD(x, y, (w / 2), (h / 2));
				halfD(x, y + (h / 2), (w / 2), (h / 2));
				halfD(x + (w / 2), y, (w / 2), (h / 2));
				halfD(x + (w / 2), y + (h / 2), (w / 2), (h / 2));
			}
			else if (w % 2 == 0 && h % 2 == 1) {//¿ŞÂÊ +1
				halfD(x, y, (w / 2), (h / 2) + 1);//top left
				halfD(x, y + (h / 2) + 1, (w / 2), (h / 2));//top right
				halfD(x + (w / 2), y, (w / 2), (h / 2) + 1);//bottom left
				halfD(x + (w / 2), y + (h / 2) + 1, (w / 2), (h / 2));//bottom right
			}
			else if (w % 2 == 1 && h % 2 == 0) {//À§ÂÊ +1
				halfD(x, y, (w / 2) + 1, (h / 2));//top left
				halfD(x, y + (h / 2), (w / 2) + 1, (h / 2));//top right
				halfD(x + (w / 2) + 1, y, (w / 2), (h / 2));//bottom left
				halfD(x + (w / 2) + 1, y + (h / 2), (w / 2), (h / 2));//bottom right
			}
			else {//µÑ´Ù È¦¼ö
				halfD(x, y, (w / 2) + 1, (h / 2) + 1);//top left
				halfD(x, y + (h / 2) + 1, (w / 2) + 1, (h / 2));//top right
				halfD(x + (w / 2) + 1, y, (w / 2), (h / 2) + 1);//bottom left
				halfD(x + (w / 2) + 1, y + (h / 2) + 1, (w / 2), (h / 2));//bottom right
			}
		}
		else if (w == 1 && h != 1) {
			if (h % 2 == 1) {//¿ŞÂÊ+1
				halfD(x, y, 1, (h / 2) + 1);
				halfD(x, y + (h / 2) + 1, 1, (h / 2));
			}
			else {
				halfD(x, y, 1, (h / 2));
				halfD(x, y + (h / 2), 1, (h / 2));
			}
		}
		else if (w != 1 && h == 1) {
			if (w % 2 == 1) {
				halfD(x, y, (w / 2) + 1, 1);
				halfD(x + (w / 2) + 1, y, (w / 2), 1);
			}
			else {
				halfD(x, y, (w / 2), 1);
				halfD(x + (w / 2), y, (w / 2), 1);
			}
		}
	}
	else if (arr[0] == '1') {
		arr.erase(0, 1);
		for (int i = x; i < x + w; i++) {
			for (int j = y; j < y + h; j++) {
				ans[i][j] = '1';
			}
		}
	}
	else if (arr[0] == '0') {
		arr.erase(0, 1);
		for (int i = x; i < x + w; i++) {
			for (int j = y; j < y + h; j++) {
				ans[i][j] = '0';
			}
		}
	}
}

int main(void) {
	freopen("bitmap.inp", "r", stdin);
	freopen("bitmap.out", "w", stdout);
	bool ch = false;
	char d='\0';
	char c;
	int x, y;
	while (1) {
		if (!ch)	scanf(" %c", &c);
		else c = d;
		ch = false;
		arr = "";
		memset(ans, '\0', sizeof(ans));
		if (c == '#')	break;
		scanf("%d %d", &x, & y);
		int cnt = 0;
		int len = 0;
		if (c == 'B') {
			/*while (1) {
				cin >> str[cnt];
				len += str[cnt].length();
				if (len == x * y)	break;
				cnt++;
			}*/
			
			while (1) {
				scanf(" %c", &ans[len][cnt]);
				if (len == x - 1 && cnt == y - 1)	break;
				cnt++;
				if (cnt == y) {
					cnt = 0;
					len++;
				}
			}
			halfB(0, 0, x, y);
			printf("D %3d %3d", x, y);
			for (int i = 0; i < arr.length(); i++) {
				if (i % 50 == 0)printf("\n");
				printf("%c", arr[i]);
			}
		}
		else {
			while (1) {
				cin >> str[cnt];
				if (str[cnt].length() == 1) {
					if (str[cnt][0] != '1' && str[cnt][0] != '0') {
						d = str[cnt][0];
						ch = true;
					}
					else arr.append(str[cnt]);
					break;
				}
				else if (str[cnt].length() != 50) {
					arr.append(str[cnt]);
					break;
				}
				arr.append(str[cnt]);
				cnt++;
			}

			halfD(0, 0, x, y);
			printf("B %3d %3d", x, y);
			cnt = 0;
			while (1) {
				if (cnt == (x * y))break;
				if (cnt % 50 == 0)printf("\n");
				printf("%c", ans[cnt / y][cnt % y]);
				cnt++;
			}
		}
		printf("\n");
	}
	return 0;
}