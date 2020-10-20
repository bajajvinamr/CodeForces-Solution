#include <bits/stdc++.h>
using namespace std;
 
int f[200020], g[200020];
 
int power(int x, int y)
{
    int o;
 
    for(o = 1; y; y /= 2)
    {
        if(y % 2)
            o = (long long)o * x % 998244353;
        x = (long long)x * x % 998244353;
    }
 
    return o;
}
 
int c(int n, int m)
{
    return (long long)f[n] * g[m] % 998244353 * g[n - m] % 998244353;
}
 
int main()
{
    int n;
    long long k;
 
    scanf("%d %I64d", &n, &k);
    if(k >= n)
    {
        printf("0\n");
 
        return 0;
    }
    for(int i = f[0] = 1; i <= n; i ++)
        f[i] = (long long)f[i - 1] * i % 998244353;
    g[n] = power(f[n], 998244351);
    for(int i = n - 1; i >= 0; i --)
        g[i] = (long long)g[i + 1] * (i + 1) % 998244353;
 
    int o = 0;
    for(int i = 0; i <= n - k; i ++)
        if(i % 2)
            o = ((o - (long long)c(n - k, i) * power(n - k - i, n)) % 998244353 + 998244353) % 998244353;
        else
            o = (o + (long long)c(n - k, i) * power(n - k - i, n)) % 998244353;
    o = (long long)o * c(n, n - k) * 2 % 998244353;
 
    if(!k)
        o = (o - f[n] + 998244353) % 998244353;
    printf("%d\n", o);
 
    return 0;
}
