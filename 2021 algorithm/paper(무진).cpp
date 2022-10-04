#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int flat[4001][4001];

typedef struct cdn {
    int x;
    int y;
    int idx;
};

vector<cdn> arr;
vector<cdn> ret;

bool cmp1(const cdn& a, const cdn& b) {
    if (a.x < b.x)
        return true;
    return false;
}

bool cmp2(const cdn& a, const cdn& b) {
    if (a.y < b.y)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("paper.inp", "r", stdin);
    freopen("paper.out", "w", stdout);

    int N;

    cin >> N;

    arr.resize(N * 2);
    ret.resize(N * 2);
    for (int i = 0; i < N; i++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        arr[i].x = x;
        arr[i].y = y;
        arr[i].idx = i;
        arr[i + N].x = x + w;
        arr[i + N].y = y + h;
        arr[i + N].idx = i + N;
    }

    sort(arr.begin(), arr.end(), cmp1);

    int i = 1;
    int val = 0;
    ret[arr[0].idx].x = 0;
    while (i < 2 * N) {
        if (arr[i].x != arr[i - 1].x) {
            val++;
        }
        ret[arr[i].idx].x = val;
        i++;
    }

    sort(arr.begin(), arr.end(), cmp2);

    i = 1;
    val = 0;
    ret[arr[0].idx].y = 0;
    while (i < 2 * N) {
        if (arr[i].y != arr[i - 1].y) {
            val++;
        }
        ret[arr[i].idx].y = val;
        i++;
    }

    for (int t = 0; t < N; t++) {
        for (int i = ret[t].x; i < ret[t + N].x; i++) {
            for (int j = ret[t].y; j < ret[t + N].y; j++) {
                flat[i][j] = t + 1;
            }
        }
    }

    int full = 0, part = 0, none = 0;

    for (int t = 0; t < N; t++) {
        int cnt = 0;
        for (int i = ret[t].x; i < ret[t + N].x; i++) {
            for (int j = ret[t].y; j < ret[t + N].y; j++) {
                if (flat[i][j] == t + 1)
                    cnt++;
            }
        }
        if (((ret[t + N].x - ret[t].x) * (ret[t + N].y - ret[t].y)) == cnt) {
            none++;
        }
        else if (cnt == 0) {
            full++;
        }
        else {
            part++;
        }
    }

    cout << full << " " << part << " " << none << " ";

    return 0;
}