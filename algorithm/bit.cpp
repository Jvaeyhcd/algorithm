#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BIT {
private:
    vector<T> t;
    int n;
public:
    explicit BIT(int _n) : n(_n), t(_n + 1) {};

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, T v) {
        while (x <= n) {
            t[x] += v;
            x += lowbit(x);
        }
    }

    void range_add(int l, int r, T v) {
        add(l, v);
        add(r + 1, -v);
    }

    T get(int x) {
        T v{};

        while (x) {
            v += t[x];
            x -= lowbit(x);
        }

        return v;
    }
};