#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define g 5
#define ll long long
#define sz 5
void inc(int &a, int b)
{
    a = a + b >= mod ? a + b - mod : a + b;
}
int qpow(int a, int b, int mod)
{
    int ret = 1;
    while (b)
    {
        if (b & 1)
            ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod, b >>= 1;
    }
    return ret;
}
struct mat
{
    int v[sz][sz];
    mat() { memset(v, 0, sizeof(v)); }
    mat operator*(const mat &A) const
    {
        mat ret;
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j < sz; ++j)
                for (int k = 0; k < sz; ++k)
                    inc(ret.v[i][j], 1ll * v[i][k] * A.v[k][j] % mod);
        return ret;
    }
};
int bsgs(int y, int z, int p)
{
    map<int, int> M;
    int m = sqrt(p) + 1;
    for (int i = 0, t = z; i <= m; ++i, t = 1ll * t * y % p)
        M[t] = i;
    for (int i = 1, tt = qpow(y, m, p), t = tt; i <= m; ++i, t = 1ll * t * tt % p)
        if (M.count(t))
            return i * m - M[t];
}
ll n;
int f1, f2, f3, c;
int main()
{
    scanf("%lld%d%d%d%d", &n, &f1, &f2, &f3, &c);
    int a1 = bsgs(g, f1, mod), a2 = bsgs(g, f2, mod), a3 = bsgs(g, f3, mod), b = bsgs(g, c, mod);
    mat S, T;
    --mod;
    S.v[0][0] = a3, S.v[0][1] = a2, S.v[0][2] = a1, S.v[0][3] = 4, S.v[0][4] = 1;
    T.v[0][0] = T.v[0][1] = T.v[1][0] = T.v[2][0] = T.v[1][2] = T.v[3][3] = T.v[4][3] = T.v[4][4] = 1;
    T.v[3][0] = 2ll * b % mod, T.v[4][0] = (-6ll * b % mod + mod) % mod;
    n -= 3;
    while (n)
    {
        if (n & 1)
            S = S * T;
        T = T * T, n >>= 1;
    }
    ++mod;
    printf("%d\n", qpow(g, S.v[0][0], mod));
    return 0;
}
