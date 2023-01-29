#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

int main(int argc, char const *argv[])
{
    long long a = qpow(2ll, 111ll, 111111111111ll);
    cout << a << endl;
    return 0;
}
