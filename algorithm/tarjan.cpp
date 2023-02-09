#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

int dfn[MAXN], low[MAXN], tot;
int scc[MAXN], sc;
int sz[MAXN];

bool vis[MAXN];
vector<int> g[MAXN];
stack<int> st;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    vis[u] = 1;
    for (int i = 0, v; i < g[u].size(); i++) {
        v = g[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        sc++; int v;
        do {
            v = st.top();
            vis[v] = 0;
            scc[v] = sc;
            sz[sc]++;
            st.pop();
        } while (v != u);
    }
}

int main(int argc, char const *argv[])
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    int du[MAXN];
    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (scc[u] != scc[v]) {
                du[scc[u]]++;
            }
        }
    }
    int c = 0;
    for (int i = 1; i <= sc; i++) {
        if (!du[i]) {
            if (c) {
                cout << "0\n";
                return 0;
            }
            c = i;
        }
    }
    cout << sz[c] << endl;
    return 0;
}
