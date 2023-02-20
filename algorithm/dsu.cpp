#include <bits/stdc++.h>
using namespace std;

class UnionFindSet {
    vector<int> fa;
    vector<int> rank;
    int n;

public:
    UnionFindSet(int _n) {
        n = _n;
        fa.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        fa[fy] = fx;
        rank[fx] += rank[fy];
        return true;
    }
};

int main(int argc, char const *argv[])
{
    UnionFindSet dsu = UnionFindSet(10);
    dsu.merge(1, 2);
    cout << dsu.find(2) << endl;
    return 0;
}
