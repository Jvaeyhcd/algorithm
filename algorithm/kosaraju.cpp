#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

vector<int> g[MAXN], g2[MAXN];
bool vis[MAXN];
vector<int> s;
int color[MAXN], cnt, n;

void dfs1(int u) {
    vis[u] = 1;
    for (int v: g[u]) {
        if (!vis[v]) dfs1(v);
    }
    s.push_back(u);
}

void dfs2(int u) {
    color[u] = cnt;
    for (int v: g2[u]) {
        if (!color[v]) dfs2(v);
    }
}

void kosaraju() {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i);
    }
    for (int i = n; i >= 1; i--) {
        if (!color[i]) {
            ++cnt;
            dfs2(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g2[v].push_back(u);
    }
    kosaraju();
    cout << cnt << endl;
    return 0;
}
