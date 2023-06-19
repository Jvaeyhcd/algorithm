#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

const long long BASE = 256;
const long long MOD = 1000000009;


template <typename T=long>
T qpow(T a, T n, T mod) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 1) {
        return qpow(a, n - 1, mod) * a % mod;
    } else {
        T temp = qpow(a, n / 2, mod) % mod;
        return temp * temp % mod;
    }
}

int rabin_karp(string txt, string pat) {
    int m = pat.size(), n = txt.size();
    long long hash_txt = 0, hash_pat = 0;
    long long mult = qpow<long long>(BASE, m - 1, MOD);

    for (int i = 0; i < m; i++) {
        hash_pat = (hash_pat * BASE + pat[i]) % MOD;
        hash_txt = (hash_txt * BASE + txt[i]) % MOD;
    }

    if (hash_pat == hash_txt) {
        return 0;
    }
    for (int i = 1; i < n - m + 1; i++) {
        hash_txt = ((hash_txt - mult * txt[i - 1]) * BASE + txt[i + m - 1]) % MOD;
        if (hash_txt < MOD) {
            hash_txt += MOD;
        }
        if (hash_pat == hash_txt) {
            return i;
        }
    }
    return -1;
}

void solve() {
    string txt = "GEEKS FOR GEEKS GEEKS GEEKS GEEKS GEEKS GEEKS SSsGEEKS";
    string pat = "SSsGEEKS";
    cout << rabin_karp(txt, pat) << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    fio;
    solve();
    return 0;
}