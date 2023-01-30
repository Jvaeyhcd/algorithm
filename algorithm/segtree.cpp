#include <bits/stdc++.h>
using namespace std;

// lazy range set segment tree
template<typename T>
class LazyRangeSetSegmentTree {
private:
    vector<T> tree, lazy, arr;
    int n;

    int lson(int node) { return (node << 1) + 1; }

    int rson(int node) { return (node << 1) + 2; }

    void pushup(int node) {
        tree[node] = tree[lson(node)] + tree[rson(node)];
    }

    void pushdown(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) >> 1;
            lazy[lson(node)] = lazy[node];
            lazy[rson(node)] = lazy[node];
            tree[lson(node)] = lazy[node] * (mid - l + 1);
            tree[rson(node)] = lazy[node] * (r - mid);
            lazy[node] = 0;
        }
    }

    void build(int l, int r, int node) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson(node));
        build(mid + 1, r, rson(node));
        pushup(node);
    }

    void range_set(int L, int R, int l, int r, int node, T val) {
        if (L <= l && r <= R) {
            tree[node] = val * (r - l + 1);
            lazy[node] = val;
            return;
        }
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid) range_set(L, R, l, mid, lson(node), val);
        if (mid < R) range_set(L, R, mid + 1, r, rson(node), val);
        pushup(node);
    }

    T range_sum(int L, int R, int l, int r, int node) {
        if (L > r || R < l) return 0;
        else if (L <= l && r <= R) return tree[node];
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        return range_sum(L, R, l, mid, lson(node)) + range_sum(L, R, mid + 1, r, rson(node));
    }

public:
    LazyRangeSetSegmentTree(int _n) : n(_n) {
        arr.resize(n, 0);
        tree.resize(n << 2, 0);
        lazy.resize(n << 2, 0);
        build(0, n - 1, 0);
    }

    LazyRangeSetSegmentTree(vector<T> _arr) : arr(_arr) {
        n = arr.size();
        tree.resize(n << 2, 0);
        lazy.resize(n << 2, 0);
        build(0, n - 1, 0);
    }

    void range_set(int l, int r, T val) {
        range_set(l, r, 0, n - 1, 0, val);
    }

    T range_sum(int l, int r) {
        return range_sum(l, r, 0, n - 1, 0);
    }
};

// lazy range add segment tree
template<typename T>
class LazyRangeAddSegmentTree {
private:
    vector<T> tree, lazy, arr;
    int n;

    int lson(int node) { return (node << 1) + 1; }

    int rson(int node) { return (node << 1) + 2; }

    void pushup(int node) {
        tree[node] = tree[lson(node)] + tree[rson(node)];
    }

    void pushdown(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) >> 1;
            lazy[lson(node)] += lazy[node];
            lazy[rson(node)] += lazy[node];
            tree[lson(node)] += lazy[node] * (mid - l + 1);
            tree[rson(node)] += lazy[node] * (r - mid);
            lazy[node] = 0;
        }
    }

    void build(int l, int r, int node) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson(node));
        build(mid + 1, r, rson(node));
        pushup(node);
    }

    void range_add(int L, int R, int l, int r, int node, T val) {
        if (L <= l && r <= R) {
            tree[node] += val * (r - l + 1);
            lazy[node] += val;
            return;
        }
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid) range_add(L, R, l, mid, lson(node), val);
        if (mid < R) range_add(L, R, mid + 1, r, rson(node), val);
        pushup(node);
    }

    T range_sum(int L, int R, int l, int r, int node) {
        if (L > r || R < l) return 0;
        else if (L <= l && r <= R) return tree[node];
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        return range_sum(L, R, l, mid, lson(node)) + range_sum(L, R, mid + 1, r, rson(node));
    }

public:
    LazyRangeAddSegmentTree(int _n) : n(_n) {
        arr.resize(n, 0);
        tree.resize(n << 2, 0);
        lazy.resize(n << 2, 0);
        build(0, n - 1, 0);
    }

    LazyRangeAddSegmentTree(vector<T> _arr) : arr(_arr) {
        n = arr.size();
        tree.resize(n << 2, 0);
        lazy.resize(n << 2, 0);
        build(0, n - 1, 0);
    }

    void range_add(int l, int r, T val) {
        range_add(l, r, 0, n - 1, 0, val);
    }

    T range_sum(int l, int r) {
        return range_sum(l, r, 0, n - 1, 0);
    }
};

int main(int argc, char const *argv[])
{
    LazyRangeSetSegmentTree<long long> seg(10);
    for (int i = 0; i < 10; i++) {
        int a; cin >> a;
        seg.range_set(i, i, a);
        cout << seg.range_sum(0, 9) << endl;
    }
    return 0;
}
