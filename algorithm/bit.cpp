#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    vector<T> t1, t2;
    int n;

    BIT(int _n) : n(_n), t1(_n + 1), t2(_n + 1) {};

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, T v) {
        for (int i = x; i <= n; i += lowbit(i)) {
            t1[i] += v;
            t2[i] += x * v;
        }
    }

    void range_add(int l, int r, T v) {
        add(l, v);
        add(r + 1, -v);
    }

    T ask(int x) {
        T v{};
        for (int i = x; i; i -= lowbit(i)) {
            v += (x + 1) * t1[i] - t2[i];
        }
        return v;
    }

    T range_ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
};

int main(int argc, char const *argv[])
{
    BIT<int> bit(10);
    return 0;
}
