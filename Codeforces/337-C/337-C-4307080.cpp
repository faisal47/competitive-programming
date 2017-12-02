#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;

ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}


#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1000000009LL;



//%I64d
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
            if(tmp < 0) tmp += mod;
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