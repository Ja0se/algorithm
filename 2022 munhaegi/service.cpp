#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct pa {
    int to, cap;
    int rev;
};
int N, P, M;// ºÀ»çÆÀ, ºÀ»ç±â°£, ºÀ»çÂü¿© ÃÖ´ëÈ¸¼ö
int Place[51];
int TotalPlace;
int End;
vector<struct pa> v[10005];
vector<int> Out;
vector<int> level;
void addEdge(int start, int end, int cap) {
    v[start].push_back({ end,cap,(int)v[end].size() });
    v[end].push_back({ start,0,(int)v[start].size() - 1 });
}
bool bfs() {
    queue<int> q;
    level.clear();
    level.resize(10005, -1);
    level[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& p : v[cur]) {
            if (level[p.to] == -1 && p.cap > 0) {
                level[p.to] = level[cur] + 1;
                q.push(p.to);
            }
        }
    }
    return level[End] != -1;
}
int dfs(int start, int flow) {
    if (start == End)return flow;
    for (int& i = Out[start]; i < v[start].size(); i++) {
        struct pa& cur = v[start][i];
        if (cur.cap > 0 && level[cur.to] > level[start]) {
            int mflow = dfs(cur.to, min(cur.cap, flow));
            if (mflow > 0) {
                cur.cap -= mflow;
                v[cur.to][cur.rev].cap += mflow;
                return mflow;
            }
        }
    }
    return 0;
}
void clear() {
    cin >> N >> P >> M;
    End = N + N * P + TotalPlace + 1;
    TotalPlace = 0;
    for (int i = 0; i < 10005; i++)v[i].clear();
    for (int i = 0; i < P; i++) {
        int a;
        cin >> a;
        TotalPlace += a;
        Place[i + 1] = TotalPlace;
    }
    for (int i = 0; i < N; i++) {
        addEdge(0, i + 1, M);
        int a;
        cin >> a;
        for (int j = 1; j <= P; j++) {
            addEdge(i + 1, N + i * P + j, 1);
        }
        for (int j = 0; j < a; j++) {
            int b, c;
            cin >> b >> c;
            addEdge(N + i * P + b, N + N * P + c + Place[b - 1], 1);
        }
    }
    for (int i = 1; i <= TotalPlace; i++) {
        addEdge(N + N * P + i, End, 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    freopen("service.inp", "r", stdin);    freopen("service.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        clear();
        int ans = 0;

        while (1) {
            Out.clear();
            Out.resize(10005, 0);
            if (!bfs())break;
            while (1) {
                int Add = dfs(0, 1e9);
                if (Add == 0)break;
                ans += Add;
            }
        }
        ans >= TotalPlace ? cout << "1\n" : cout << "0\n";
    }
    return 0;
}
