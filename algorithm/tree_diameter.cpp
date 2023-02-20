#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

const int MAXN = 5e5 + 1;

struct Node
{
    int to, w;
    Node(int _to, int _w) {
        to = _to;
        w = _w;
    }
};

int n, ans;
vector<Node> g[MAXN];
int d1[MAXN], d2[MAXN];

void dfs(int u, int pa) {
    d1[u] = d2[u] = 0;
    for (Node p: g[u]) {
        int v = p.to, w = p.w;
        if (v == pa) continue;
        dfs(v, u);
        int t = d1[v] + w;
        if (t > d1[u]) {
            d2[u] = d1[u];
            d1[u] = t;
        } else if (t > d2[u]) {
            d2[u] = t;
        }
    }
    ans = max(ans, d1[u] + d2[u]);
}

void solve() {
    int u, v, w;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        g[u].push_back(Node(v, w));
        g[v].push_back(Node(u, w));
    }
    dfs(1, 0);
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    fio;
    solve();
    return 0;
}