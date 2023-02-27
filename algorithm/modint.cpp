#include <bits/stdc++.h>
using namespace std;

int inverse(int a, int m) {
    int r = 1;
    while(a > 1) {
        int t = m / a;
        r = (long long)(r) * (m - t) % m;
        a = m - t * a;
    }
    return r;
}
template<int mod>
struct Mint {
    int x;
    Mint(int x = 0) : x(normal(x)) {}
    Mint(long long x) : x(normal(x % mod)) {}
    int normal(int x) {
        if(x >= mod) {
            x -= mod;
        }
        if(x < 0) {
            x += mod;
        }
        return x;
    }
    int val() const {
        return x;
    }
    Mint inv() const {
        assert(x != 0);
        return Mint(inverse(x, mod));
    }
    Mint operator - () const {
        return Mint(mod - x);
    }
    Mint operator += (const Mint &rhs) {
        x = normal(x + rhs.x);
        return *this;
    }
    Mint operator -= (const Mint &rhs) {
        x = normal(x - rhs.x);
        return *this;
    }
    Mint operator *= (const Mint &rhs) {
        x = i64(x) * rhs.x % mod;
        return *this;
    }
    Mint operator /= (const Mint &rhs) {
        return *this *= rhs.inv();
    }
    friend Mint operator + (const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator - (const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator * (const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator / (const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend istream &operator >> (istream &is, Mint &a) {
        long long v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend ostream &operator << (ostream &os, const Mint &a) {
        os << a.val();
        return os;
    }
};

using M107 = Mint<1000000007>;
using M998 = Mint<998244353>;

int main(int argc, char const *argv[])
{
    M107 a, b; cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
