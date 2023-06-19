#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct node {
    int u, v;
};

vector<int> edge[N];
int dfn[N], low[N], fa[N], tot;
vector<node> cut_edge;

void tarjan(int u) {
    low[u] = dfn[u] = ++tot;
    for (auto v : edge[u]) {
        if (!dfn[v]) {
            fa[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                cut_edge.emplace_back(node{u, v});
            }
        } else if (v != fa[u]) {
            low[u] = min(low[u], dfn[v]);
        }
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
    tarjan(1);
    cout << "cut_edge:\n";
    for (auto it : cut_edge) {
        cout << it.u << "--" << it.v << '\n';
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