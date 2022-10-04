#include<iostream>
#include<string>
#include<cmath>
#pragma warning(disable:4996)

using namespace std;
struct pa {
	int y, m, d;
	int cnt;
	int day;
};
string Sun = "Sun";//6
string Mon = "Mon";//0
string Tue = "Tue";
string Wed = "Wed";
string Thu = "Thu";
string Fri = "Fri";
string Sat = "Sat";
int type;
bool sec(char c) {
	if (c != '-' && c != '\0')	return true;
	return false;
}
//31,28,31,30,31,30,31,31,30,31,30,31
//1-1-1  Mon
//2-1-1  Fri  +4
//3-1-1  Tue
//4-1-1

int mcheck(int y, int m) {
	y--;
	int date = y * 365;

	if (y != 0)	date += y / 4;
	date -= y / 100;
	date += y / 400;
	y++;
	if (m == 1)return date;
	date += 31;
	if (m == 2)return date;
	date += 28;
	if (y % 4 == 0) {
		date++;
		if (y % 100 == 0 && y % 400 != 0) {
			date--;
		}
	}
	if (m == 3)return date;
	date += 31;
	if (m == 4)return date;
	date += 30;
	if (m == 5)return date;
	date += 31;
	if (m == 6)return date;
	date += 30;
	if (m == 7)return date;
	date += 31;
	if (m == 8)return date;
	date += 31;
	if (m == 9)return date;
	date += 30;
	if (m == 10)return date;
	date += 31;
	if (m == 11)return date;
	date += 30;
	if (m == 12)return date;

}
int check(struct pa first, struct pa second) {

	if (type == 0 || type == 1) {
		switch (first.m) {
		case 1:
			if (first.d > 31)	return -1;
			break;
		case 2:
			if (first.y % 4 != 0 && first.d > 28)	return -1;
			if (first.y % 4 == 0) {//À±³â
				if (first.y % 100 == 0) {//Æò³â
					if (first.y % 400 == 0) {//À±³â
						if (first.d > 29)return -1;
					}
					if (first.d > 28)	return -1;
				}
				if (first.d > 29)return -1;
			}
			break;
		case 3:
			if (first.d > 31)	return -1;
			break;
		case 4:
			if (first.d > 30)	return -1;
			break;
		case 5:
			if (first.d > 31)	return -1;
			break;
		case 6:
			if (first.d > 30)	return -1;
			break;
		case 7:
			if (first.d > 31)	return -1;
			break;
		case 8:
			if (first.d > 31)	return -1;
			break;
		case 9:
			if (first.d > 30)	return -1;
			break;
		case 10:
			if (first.d > 31)	return -1;
			break;
		case 11:
			if (first.d > 30)	return -1;
			break;
		case 12:
			if (first.d > 31)	return -1;
			break;
		}
	}
	if (type == 0 || type == 2) {
		switch (second.m) {
		case 1:
			if (second.d > 31)	return -1;
			break;
		case 2:
			if (second.y % 4 != 0 && second.d > 28)	return -1;
			if (second.y % 4 == 0) {//À±³â
				if (second.y % 100 == 0) {//Æò³â
					if (second.y % 400 == 0) {//À±³â
						if (second.d > 29)return -1;
					}
					if (second.d > 28)	return -1;
				}
				if (second.d > 29)return -1;
			}
			break;
		case 3:
			if (second.d > 31)	return -1;
			break;
		case 4:
			if (second.d > 30)	return -1;
			break;
		case 5:
			if (second.d > 31)	return -1;
			break;
		case 6:
			if (second.d > 30)	return -1;
			break;
		case 7:
			if (second.d > 31)	return -1;
			break;
		case 8:
			if (second.d > 31)	return -1;
			break;
		case 9:
			if (second.d > 30)	return -1;
			break;
		case 10:
			if (second.d > 31)	return -1;
			break;
		case 11:
			if (second.d > 30)	return -1;
			break;
		case 12:
			if (second.d > 31)	return -1;
			break;
		}
	}
	int fd = mcheck(first.y, first.m);//1¿ù 1ÀÏ°úÀÇ °Å¸® Â÷ÀÌ
	int sd = mcheck(second.y, second.m);
	bool fdate[6][8] = { 0, };
	bool sdate[6][8] = { 0, };
	if (type == 0 || type == 1)	fd += first.d - 1;
	if (type == 0 || type == 2) sd += second.d - 1;
	int fday = (fd + 1) % 7;//y.m.1 day
	int sday = (sd + 1) % 7;
	int fplus = 0;
	int splus = 0;
	if (type == 2 || type == 3) {
		if (first.m == 1 || first.m == 3 || first.m == 5 || first.m == 7 || first.m == 8 || first.m == 10 || first.m == 12) {
			int cnt = 0;
			for (int i = 0; i < 31; i++) {
				if (i % 7 == 0) {
					cnt++;
				}
				fdate[cnt][fday] = true;
				if (cnt == first.cnt && fday == first.day)break;
				fplus++;
				fday++;
				fday %= 7;
			}
		}
		else if (first.m == 2) {
			int cnt = 0;
			for (int i = 0; i < 28; i++) {
				if (i % 7 == 0) {
					cnt++;
				}
				fdate[cnt][fday] = true;
				if (cnt == first.cnt && fday == first.day)break;
				fplus++;
				fday++;
				fday %= 7;
				if (i == 27) {
					if (first.y % 4 == 0) {
						if (first.y % 100 == 0 && first.y % 400 != 0) {
							break;
						}
						fdate[5][fday] = true;
						if (cnt == first.cnt && fday == first.day) fplus++;
					}
				}
			}

		}
		else {
			int cnt = 0;
			for (int i = 0; i < 30; i++) {
				if (i % 7 == 0) {
					cnt++;
				}
				fdate[cnt][fday] = true;
				if (cnt == first.cnt && fday == first.day)break;
				fplus++;
				fday++;
				fday %= 7;
			}
		}
	}
	if (type == 1 || type == 3) {
		if (second.m == 1 || second.m == 3 || second.m == 5 || second.m == 7 || second.m == 8 || second.m == 10 || second.m == 12) {
			int cnt = 0;
			for (int i = 0; i < 31; i++) {
				if (i % 7 == 0) {
					cnt++;
				}
				sdate[cnt][sday] = true;
				if (cnt == second.cnt && sday == second.day)break;
				splus++;
				sday++;
				sday %= 7;
			}
		}
		else if (second.m == 2) {
			int cnt = 0;
			for (int i = 0; i < 28; i++) {
				if (i % 7 == 0) {
					cnt++;
				}
				sdate[cnt][sday] = true;
				if (cnt == second.cnt && sday == second.day)break;
				splus++;
				sday++;
				sday %= 7;
				if (i == 27 && second.y % 4 == 0) {
					if (second.y % 100 == 0 && second.y % 400 != 0) {
						break;
					}
					sdate[5][sday] = true;
					if (cnt == second.cnt && sday == second.day) splus++;
				}
			}

		}
		else {
			int cnt = 0;
			for (int i = 0; i < 30; i++) {
				if (i % 7 == 0) {
					cnt++;
				}
				sdate[cnt][sday] = true;
				if (cnt == second.cnt && sday == second.day)break;
				splus++;
				sday++;
				sday %= 7;
			}
		}
	}
	if (type == 2 || type == 3)if (!fdate[first.cnt][first.day])	return -1;
	if (type == 1 || type == 3)if (!sdate[second.cnt][second.day])	return -1;
	fd += fplus;
	sd += splus;
	return abs(fd - sd);

}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	freopen("calendar.inp", "r", stdin);
	freopen("calendar.out", "w", stdout);
	while (1) {
		cin >> type;
		string s1, s2;
		if (type == -1)	break;
		cin >> s1 >> s2;
		struct pa c1 = { 0, };
		struct pa c2 = { 0, };
		string s = "";
		int idx = 0;
		while (1) {
			if (!sec(s1[idx]))	break;
			s += s1[idx];
			idx++;
		}
		c1.y = stoi(s);
		idx++;
		//48~57  0~9
		//mm
		s = "";
		while (1) {
			if (!sec(s1[idx]))	break;
			s += s1[idx];
			idx++;
		}
		c1.m = stoi(s);
		idx++;
		//dd
		s = "";
		while (1) {
			if (!sec(s1[idx]))	break;
			s += s1[idx];
			idx++;
		}
		if (type == 0 || type == 1) c1.d = stoi(s);
		else c1.cnt = stoi(s);
		idx++;
		s = "";
		if (type == 2 || type == 3) {
			while (1) {
				if (!sec(s1[idx]))	break;
				s += s1[idx];
				idx++;
			}
			if (s.compare(Mon) == 0) c1.day = 1;
			else if (s.compare(Tue) == 0)c1.day = 2;
			else if (s.compare(Wed) == 0)c1.day = 3;
			else if (s.compare(Thu) == 0)c1.day = 4;
			else if (s.compare(Fri) == 0)c1.day = 5;
			else if (s.compare(Sat) == 0)c1.day = 6;
			else if (s.compare(Sun) == 0)c1.day = 0;
		}

		//c2
		s = "";
		idx = 0;
		while (1) {
			if (!sec(s2[idx]))	break;
			s += s2[idx];
			idx++;
		}
		c2.y = stoi(s);
		idx++;
		s = "";
		while (1) {
			if (!sec(s2[idx]))	break;
			s += s2[idx];
			idx++;
		}
		c2.m = stoi(s);
		idx++;
		//dd
		s = "";
		while (1) {
			if (!sec(s2[idx]))	break;
			s += s2[idx];
			idx++;
		}
		if (type == 0 || type == 2)c2.d = stoi(s);
		else c2.cnt = stoi(s);
		s = "";
		idx++;
		if (type == 1 || type == 3) {
			//day
			while (1) {
				if (!sec(s2[idx]))	break;
				s += s2[idx];
				idx++;
			}
			if (s.compare(Mon) == 0) c2.day = 1;
			else if (s.compare(Tue) == 0)c2.day = 2;
			else if (s.compare(Wed) == 0)c2.day = 3;
			else if (s.compare(Thu) == 0)c2.day = 4;
			else if (s.compare(Fri) == 0)c2.day = 5;
			else if (s.compare(Sat) == 0)c2.day = 6;
			else if (s.compare(Sun) == 0)c2.day = 0;
		}
		int ans = check(c1, c2);
		cout << ans << "\n";
	}


	return 0;
}