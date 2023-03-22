/**
 * @File    :   hld.cpp
 * @Time    :   2023/03/20 14:56:32
 * @Author  :   Jvaeyhcd
 * @Contact :   huangcd1992@gmail.com
**/
#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

struct HLD {
    int n, tot;
    vector<int> sz, dep, fa, son;
    vector<int> top, dfn, rnk;
    vector<vector<int>> adj;

    HLD(){}
    HLD(int _n) {
        init(_n);
    }
    
    void init(int _n) {
        n = _n;
        tot = 1;
        sz.resize(n, 0);
        dep.resize(n, 0);
        fa.resize(n, 0);
        son.resize(n, 0);
        top.resize(n, 0);
        dfn.resize(n, 0);
        rnk.resize(n, 0);
        adj.assign(n, {});
    }

    void work(int root = 1) {
        top[root] = root;
        dep[root] = 0;
        dfs1(root, 0);
        dfs2(root, root);
    }
    
    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs1(int u, int f) {
        dep[u] = dep[f] + 1;
        sz[u] = 1;
        fa[u] = f;
        for (int v: adj[u]) {
            if (v == f) {
                continue;
            }
            dfs1(v, u);
            sz[u] += sz[v];
            if (!son[u] || sz[v] > sz[son[u]]) {
                son[u] = v;
            }
        }
    }
    
    void dfs2(int u, int t) {
        top[u] = t;
        tot++;
        dfn[u] = tot;
        rnk[tot] = u;
        if (!son[u]) {
            return;
        }
        dfs2(son[u], t);
        for (int v: adj[u]) {
            if (v != fa[u] && v != son[u]) {
                dfs2(v, v);
            }
        }
    }
    
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) {
                swap(x, y);
            }
            x = fa[top[x]];
        }
        return dep[x] < dep[y] ? x : y;
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
};

HLD hld;

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    hld.init(n + 1);
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        hld.add(x, y);
    }
    hld.work(s);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << hld.lca(x, y) << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    fio;
    solve();
    return 0;
}