#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> edge[N];
int dfn[N], low[N], tot;
vector<int> cut_points;

void tarjan(int u, bool islow) {
    cout << u << endl;
    int cnt = 0;
    low[u] = dfn[u] = ++tot;
    for (auto v : edge[u]) {
        if (!dfn[v]) {
            tarjan(v, 0);
            low[u] = min(low[u], low[v]);
            cnt += low[v] >= dfn[u];
        } else {
            low[u] = min(low[u], dfn[v]);
        }
            
    }
    if (cnt > islow) {
        cut_points.emplace_back(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }
    tarjan(1, 1);
    cout << "cut_points: ";
    for (auto it : cut_points) {
        cout << it << ' ';
    }
    return 0;
}
/*
5 5
1 2
2 3
3 4
2 4
4 5
*/