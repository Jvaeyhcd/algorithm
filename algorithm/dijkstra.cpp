#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAXN = 100005;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

struct Node {
    int u;
    long long dis;
    Node(int _u, long long _dis) : u(_u), dis(_dis) {}

    bool operator< (const Node& a) const {
        return dis < a.dis;
    }

    bool operator> (const Node& a) const {
        return dis > a.dis;
    }
};

long long dis[MAXN];
vector<Edge> g[MAXN];
int vis[MAXN];
priority_queue<Node, vector<Node>, greater<Node>> q;

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(Node(s, 0));
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed: g[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(Node(v, dis[v]));
            }
        }
    }
}

void solve() {
    
}

int main() {
    // freopen("input.txt", "r", stdin);
    fio;
    solve();
    return 0;
}