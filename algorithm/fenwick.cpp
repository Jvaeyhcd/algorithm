#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
private:
    vector<T> fenw;
    int n;
public:
    explicit fenwick(int _n) : n(_n), fenw(_n + 1) {};

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, T v) {
        for (int i = x; i <= n; i += lowbit(i)) {
            fenw[i] += v;
        }
    }

    T get(int x) {
        T v{};
        for (int i = x - 1; i > 0; i -= lowbit(i)) {
            v += fenw[i];
        }
        return v;
    }
};
