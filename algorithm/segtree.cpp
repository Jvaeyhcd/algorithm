#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAXN = 1e9;

struct SegTreeNode {
    SegTreeNode *left, *right;
    int val, lazy;
    int l, r;
    SegTreeNode() : val(0), lazy(0), left(nullptr), right(nullptr) {}
    SegTreeNode(int _l, int _r) : l(_l), r(_r), val(0), lazy(0), left(nullptr), right(nullptr) {}
};

template<typename T>
struct SegTree {
    SegTreeNode *root;

    SegTree() {
        root = new SegTreeNode(0, MAXN);
    }

    void modify_add(SegTreeNode *node, int l, int r, int val) {
        int start = node->l, end = node->r;
        if (l <= start && end <= r) {
            node->val += val * (end - start + 1);
            node->lazy += val;
            return;
        }
        pushdown(node);
        int mid = (start + end) >> 1;
        if (l <= mid) modify_add(node->left, l, r, val);
        if (mid < r) modify_add(node->right, l, r, val);
        pushup(node);
    }

    T query(SegTreeNode *node, int l, int r) {
        int start = node->l, end = node->r;
        if (l > end || r < start) return 0;
        else if (l <= start && end <= r) return node->val;
        pushdown(node);
        return query(node->left, l, r) + query(node->right, l, r);
    }

    void pushdown(SegTreeNode *node) {
        int l = node->l, r = node->r;
        int mid = (l + r) >> 1;
        if (!node->left) node->left = new SegTreeNode(l, mid);
        if (!node->right) node->right = new SegTreeNode(mid + 1, r);
        if (node->lazy) {
            int ln = mid - l + 1, rn = r - mid;
            node->left->val += node->lazy * ln;
            node->right->val += node->lazy * rn;
            node->left->lazy += node->lazy;
            node->right->lazy += node->lazy;
            node->lazy = 0;
        }
    }

    void pushup(SegTreeNode * node) {
        node->val = node->left->val + node->right->val;
    }
};

void solve() {
    SegTree<long long> segtree;
    segtree.modify_add(segtree.root, 1, 10, 2);
    cout << segtree.query(segtree.root, 1, 20) << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    fio;
    solve();
    return 0;
}