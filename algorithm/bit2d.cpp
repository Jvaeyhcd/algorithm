#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT2d {
    int n, m;
    vector<vector<T>> c1, c2, c3, c4;

    int lowbit(int x) {
        return x & (-x);
    }

    BIT2d(int _n, int _m) : n(_n), m(_m), c1(_n + 1, vector<T>(_m + 1)), c2(_n + 1, vector<T>(_m + 1)), c3(_n + 1, vector<T>(_m + 1)), c4(_n + 1, vector<T>(_m + 1)) {};

    void add(int x, int y, T v) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                c1[i][j] += v;
                c2[i][j] += x * v;
                c3[i][j] += y * v;
                c4[i][j] += x * y * v;
            }
        }
    }

    void range_add(int x1, int y1, int x2, int y2, int v) {
        add(x1, y1, v);
        add(x2 + 1, y2 + 1, v);
        add(x2 + 1, y1, -v);
        add(x1, y2 + 1, -v);
    }

    T ask(int x, int y) {
        T tot{};
        for (int i = x; i; i -= lowbit(i)) {
            for (int j = y; j; j -= lowbit(j)) {
                tot += (x + 1) * (y + 1) * c1[i][j] - (y + 1) * c2[i][j] - (x + 1) * c3[i][j] + c4[i][j];
            }
        }
        return tot;
    }

    T range_ask(int x1, int y1, int x2, int y2) {
        return ask(x2, y2) + ask(x1 - 1, y1 - 1) - ask(x2, y1 - 1) - ask(x1 - 1, y2);
    }

};

int main(int argc, char const *argv[])
{
    int n, m; cin >> n >> m;
    BIT2d<long long> bit2d(n, m);

    int op;
    while (~scanf("%d", &op)) {
        if (op == 1) {
            int x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;
            bit2d.range_add(x1, y1, x2, y2, k);
        } else if (op == 2) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << bit2d.range_ask(x1, y1, x2, y2) << endl;
        }
    }
    return 0;
}
