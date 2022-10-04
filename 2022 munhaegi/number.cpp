#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#define Max 101
using namespace std;
struct bignum {
    string str;
    char arr[Max];
    int signbit;
    int lastbit;
};
void Init(struct bignum* c);
void Zero(struct bignum* c);
void Minus(struct bignum* a, struct bignum* b, struct bignum* c);
void Plus(struct bignum* a, struct bignum* b, struct bignum* c);
int Compare(struct bignum* a, struct bignum* b);
int main(void) {
    ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
    freopen("number.inp", "r", stdin);    freopen("number.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        struct bignum a, b, c, d, e, f;
        char oper;
        cin >> a.str >> oper >> b.str;
        Init(&a);
        Init(&b);
        Init(&d);
        Init(&e);
        a.lastbit = a.str.length() - 1;
        b.lastbit = b.str.length() - 1;
        for (int i = 0; i <= a.lastbit; i++) {
            if (a.str[i] == '.') {
                d.lastbit = a.lastbit - i - 1;
                for (int j = i + 1; j <= a.lastbit; j++) {
                    d.str += a.str[j];
                }
                a.lastbit = i - 1;
                for (int j = -1; j <= d.lastbit; j++) {
                    a.str.pop_back();
                }
                break;
            }
        }
        for (int i = 0; i <= b.lastbit; i++) {
            if (b.str[i] == '.') {
                e.lastbit = b.lastbit - i - 1;
                for (int j = i + 1; j <= b.lastbit; j++) {
                    e.str += b.str[j];
                }
                b.lastbit = i - 1;
                for (int j = -1; j <= e.lastbit; j++) {
                    b.str.pop_back();
                }
                break;
            }
        }
        reverse(a.str.begin(), a.str.end());
        reverse(b.str.begin(), b.str.end());

        while (a.str.length() > 1 && a.str.back() == '0') {
            a.str.pop_back();
        }
        while (b.str.length() > 1 && b.str.back() == '0')b.str.pop_back();
        //while (d.str.length() > 1 && d.str.back() == '0')d.str.pop_back();
        //while (e.str.length() > 1 && e.str.back() == '0')e.str.pop_back();
        a.lastbit = a.str.length() - 1;
        b.lastbit = b.str.length() - 1;
        d.lastbit = d.str.length() - 1;
        e.lastbit = e.str.length() - 1;

        strcpy(a.arr, a.str.c_str());
        strcpy(b.arr, b.str.c_str());
        strcpy(d.arr, d.str.c_str());
        strcpy(e.arr, e.str.c_str());
        for (int i = a.lastbit + 1; i < Max; i++)a.arr[i] = '0';
        for (int i = b.lastbit + 1; i < Max; i++)b.arr[i] = '0';
        for (int i = d.lastbit + 1; i < Max; i++)d.arr[i] = '0';
        for (int i = e.lastbit + 1; i < Max; i++)e.arr[i] = '0';
        int Maxbit;
        switch (oper) {
        case '-':
            Minus(&a, &b, &c);
            Maxbit = max(d.lastbit, e.lastbit);
            for (int i = d.lastbit + 1; i <= Maxbit; i++)d.str.push_back('0');
            for (int i = e.lastbit + 1; i <= Maxbit; i++)e.str.push_back('0');
            reverse(d.str.begin(), d.str.end());
            reverse(e.str.begin(), e.str.end());
            d.lastbit = e.lastbit = Maxbit;
            for (int i = 0; i <= Maxbit; i++) {
                d.arr[i] = d.str[i];
                e.arr[i] = e.str[i];
            }

            Minus(&d, &e, &f);
            f.lastbit = Maxbit;
            if ((f.lastbit == 0 || f.lastbit == -1) && f.arr[0] == '0')f.signbit = c.signbit;
            if (f.signbit != c.signbit) {// 음수일경우
                //if ((f.signbit==-1&&c.signbit == 1)||) {// 그대로 추가하면 된다.
                struct bignum g;
                Init(&g);
                g.arr[0] = '1';
                a = c;
                if (c.signbit == 1)Minus(&a, &g, &c);
                else Plus(&a, &g, &c);

                /*f.arr[f.lastbit + 1] = '\0';
                f.str = f.arr;
                reverse(f.str.begin(), f.str.end());
                for (int i = 0; i <= f.lastbit; i++) {
                    f.arr[i] = f.str[i];
                }
                f.arr[f.lastbit + 1] = '0';*/
                f.lastbit = Maxbit;
                g.lastbit = f.lastbit + 1;
                g.arr[0] = '0';
                g.arr[g.lastbit] = '1';
                d = f;
                if (d.signbit == 1)Minus(&d, &g, &f);
                else Plus(&d, &g, &f);
                f.lastbit = Maxbit;
                //Zero(&f);
                f.arr[f.lastbit + 1] = '\0';
                f.str = f.arr;
                reverse(f.str.begin(), f.str.end());

                // }
                 //else {
                 //    f.arr[f.lastbit + 1] = '\0';
                 //    f.str = f.arr;
               //  }
            }
            else {
                f.arr[f.lastbit + 1] = '\0';
                f.str = f.arr;
                reverse(f.str.begin(), f.str.end());
            }
            break;
        case '+':
            Plus(&a, &b, &c);
            Maxbit = max(d.lastbit, e.lastbit);
            for (int i = d.lastbit + 1; i <= Maxbit; i++)d.str.push_back('0');
            for (int i = e.lastbit + 1; i <= Maxbit; i++)e.str.push_back('0');
            reverse(d.str.begin(), d.str.end());
            reverse(e.str.begin(), e.str.end());
            d.lastbit = e.lastbit = Maxbit;
            for (int i = 0; i <= Maxbit; i++) {
                d.arr[i] = d.str[i];
                e.arr[i] = e.str[i];
            }
            Plus(&d, &e, &f);
            if (f.lastbit > Maxbit && Maxbit != -1) {//한자리수 올림
                struct bignum g;
                Init(&g);
                g.arr[0] = '1';
                a = c;
                Plus(&a, &g, &c);
            }
            else f.lastbit = Maxbit;
            f.arr[Maxbit + 1] = '\0';
            f.str = f.arr;
            reverse(f.str.begin(), f.str.end());
            break;
        }
        for (int i = f.lastbit; i >= 0; i--) {
            if (!f.str.empty() && f.str.back() == '0') {
                f.str.pop_back();
            }
            else break;
        }

        c.arr[c.lastbit + 1] = '\0';
        c.str = c.arr;
        reverse(c.str.begin(), c.str.end());
        if (c.signbit == -1)cout << "-";
        if (!f.str.empty() && !(f.lastbit == 0 && f.arr[0] == '0'))cout << c.str << "." << f.str << "\n";
        else cout << c.str << "\n";
    }
    return 0;
}
void Init(struct bignum* c) {
    for (int i = 0; i < Max; i++) { c->arr[i] = '0'; }
    c->lastbit = 0;
    c->signbit = 1;
}
void Zero(struct bignum* c) {
    while ((c->lastbit > 0) && (c->arr[c->lastbit] == '0'))c->lastbit--;
    if ((c->lastbit == 0) && (c->arr[0] == '0'))c->signbit = 1;
}
void Minus(struct bignum* a, struct bignum* b, struct bignum* c) {
    Init(c);
    if (a->signbit == -1 || b->signbit == -1) {
        b->signbit = -1 * b->signbit;
        Plus(a, b, c);
        b->signbit = -1 * b->signbit;
        return;
    }
    if (Compare(a, b) == 1) {
        Minus(b, a, c);
        c->signbit = -1;
        return;
    }
    c->lastbit = max(a->lastbit, b->lastbit);
    int borrow = 0;
    int v;
    for (int i = 0; i <= c->lastbit; i++) {
        int A = a->arr[i] - '0';
        int B = b->arr[i] - '0';
        v = A - borrow - B;
        if (A > 0)borrow = 0;
        if (v < 0) {
            v += 10;
            borrow = 1;
        }
        c->arr[i] = (v % 10) + '0';
    }
    Zero(c);
}

void Plus(struct bignum* a, struct bignum* b, struct bignum* c) {
    Init(c);
    if (a->signbit == b->signbit)c->signbit = a->signbit;
    else {
        if (a->signbit == -1) {
            a->signbit = 1;
            Minus(b, a, c);
            a->signbit = -1;
        }
        else {
            b->signbit = 1;
            Minus(a, b, c);
            b->signbit = -1;
        }
        return;
    }
    int carry = 0;
    c->lastbit = max(a->lastbit, b->lastbit) + 1;
    for (int i = 0; i <= c->lastbit; i++) {
        int A = a->arr[i] - '0';
        int B = b->arr[i] - '0';
        int cal = carry + A + B;
        c->arr[i] = (cal % 10) + '0';
        carry = cal / 10;
    }
    Zero(c);
}

int Compare(struct bignum* a, struct bignum* b) {
    if (a->signbit == -1 && b->signbit == 1) return 1;
    if (a->signbit == 1 && b->signbit == -1)return -1;
    if (b->lastbit > a->lastbit) return a->signbit;
    if (a->lastbit > b->lastbit)return -1 * a->signbit;
    for (int i = a->lastbit; i >= 0; i--) {
        if (a->arr[i] > b->arr[i])return -1 * a->signbit;
        if (b->arr[i] > a->arr[i])return a->signbit;
    }
    return 0;
}