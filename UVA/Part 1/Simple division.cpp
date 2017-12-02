#include <bits/stdc++.h>
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sz(a) a.size()
#define scll1(a) scanf("%lld",&a)
using namespace std;
typedef long long ll;
int main ()
{
    ll n,i,res;
    vec_<ll>v;
    while(scll1(n)==1)
    {
        clr(v);
        if(!n)break;
        v.pb(n);
        while(scll1(n)==1)
        {
            if(!n)break;
            v.pb(n);
        }
        res=abs(v[0]-v[1]);
        for(i=2;i<sz(v);i++)
        {
            n=abs(v[i]-v[i-1]);
            res=__gcd(res,n);
        }
        cout<<res<<endl;
    }
    return 0;
}

