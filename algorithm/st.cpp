#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SparseTable {
    using func_type = function<T(const T &, const T &)>;
    static T default_func(const T &t1, const T &t2) {
        return max(t1, t2);
    }
    vector<vector<T>> st;
    func_type op;

    SparseTable(const vector<T>& a, func_type _func = default_func) {
        op = _func;
        int n = a.size();
        int k = ceil(log2(n)) + 1;
        st.resize(n, vector<T>(k, 0));
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < k; j++) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < n; i++) {
                st[i][j] = op(st[i][j - 1], st[i + pj][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        int k = ceil(log2(r - l + 1)) - 1;
        return op(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

static int op(const int &t1, const int &t2) {
    return min(t1, t2);
};

int main(int argc, char const *argv[])
{
    vector<int> a = {10, 20, 20, 40, 5, 2, 7, 8};
    
    SparseTable<int> st(a, op);
    cout << st.query(0, 3) << endl; // 输出 1
    cout << st.query(2, 5) << endl; // 输出 2
    cout << st.query(0, 7) << endl; // 输出 1
    return 0;
}
