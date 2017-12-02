#include <bits/stdc++.h>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define scll1(a) scanf("%lld",&a)
#define sz(a) a.size()
using namespace std;
typedef long long ll;
template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
int main ()
{
    vec_<ll>v;
    ll n,i,j,ans,m;
    while(scll1(n)==1)
    {
        if(!n)break;
        ans=0;
        if(n==1)
        {
            cout<<1<<" "<<1<<endl;
            continue;
        }
        clr(v);
        m=j=sqrt(n);
        for(i=1;i<=j;i++)
        if(!(n%i))
        {
            v.pb(i);
            v.pb(n/i);
        }
        sort(v.begin(),v.end());
        for(i=0;i<sz(v);i++)
        for(j=i;j<sz(v);j++)
        if(lcm(v[i],v[j])==n)ans++;
        if(m*m==n)
        ans--;
        cout<<n<<" "<<ans<<endl;
    }
    return 0;
}

