#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}
ll mod=1000000009;
int main ()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll khali=n-m;
    ll khali1=khali*(k-1);
    ll baki=m-(k-1)*khali;
    ll ans=0;
    if(baki >= k)
    {
       ans=bigmod(2,baki/k,mod)-1;
       ans=(ans*((k*2)%mod))%mod;
    }
    if(khali1 < m)
    ans+=baki%k,ans+=khali1;
    else
    ans+=m;
    ans%=mod;
    cout<<ans;

    return 0;
}