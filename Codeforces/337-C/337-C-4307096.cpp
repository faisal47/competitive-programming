#include <bits/stdc++.h>
using namespace  std;
typedef long long ll;
ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
const ll mod = 1000000009LL;
int main()
{
    ll n, m, k, gap, rem, ans, flor, tmp;
    while(cin >> n >> m >> k)
    {
        gap = n - m;
        rem = m - ( (k-1) * gap );
        ans = 0;
        if(rem >= k)
        {
            flor = rem / k;
            ans = (k*2) % mod;
            tmp = bigmod(2LL, flor, mod);
            tmp--;
            ans = (ans * tmp) % mod;
        }

        if((k-1) * gap < m)
        {
            ans += rem % k;
        }

        ans += (k-1) * gap < m ? (k-1) * gap : m;

        ans %= mod;

        printf("%I64d\n",ans);
    }

    return 0;
}