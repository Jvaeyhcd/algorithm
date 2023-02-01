#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Fenwick {
private:
    vector<T> fenw, fenw2;
    int n;
public:
    explicit Fenwick(int _n) : n(_n), fenw(_n + 1), fenw2(_n + 1) {};

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, T v) {
        int pos = x;
        while (x <= n) {
            fenw[x] += v;
            fenw2[x] += v * pos;
            x += lowbit(x);
        }
    }

    void range_add(int l, int r, T v) {
        add(l, v);
        add(r + 1, -v);
    }

    T get(int x) {
        T v{};
        int pos = x;
        while (x) {
            v += (fenw[x] * (pos + 1) - fenw2[x]);
            x -= lowbit(x);
        }
        return v;
    }

    T range_query(int l, int r) {
        return get(r) - get(l - 1);
    }
};