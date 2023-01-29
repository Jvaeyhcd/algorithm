#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <math.h>
using namespace std;

template<typename T>
class SegmentTree {
private:
    vector<T> tree;
    vector<T> lazy;
    int n;

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int l, int r, int i, int j, T value) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (l >= i && r <= j) {
            tree[node] += (r - l + 1) * value;
            if (l != r) {
                lazy[2 * node] += value;
                lazy[2 * node + 1] += value;
            }
            return;
        }
        int mid = (l + r) / 2;
        if (i <= mid) update(2 * node, l, mid, i, j, value);
        if (j > mid) update(2 * node + 1, mid + 1, r, i, j, value);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    T query(int node, int l, int r, int i, int j) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (l >= i && r <= j) return tree[node];
        int mid = (l + r) / 2;
        T sum = 0;
        if (i <= mid) sum += query(2 * node, l, mid, i, j);
        if (j > mid) sum += query(2 * node + 1, mid + 1, r, i, j);
        return sum;
    }

public:
    SegmentTree(int _n) : n(_n) {
        int size = (int)(2 * pow(2.0, floor((log((double)n) / log(2.0)) + 1)));
        tree.resize(size);
        lazy.resize(size);
        build(1, 0, n - 1);
    }

    void update(int i, int j, T value) {
        update(1, 0, n - 1, i, j, value);
    }

    T query(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
