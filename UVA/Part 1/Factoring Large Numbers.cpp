#include <bits/stdc++.h>
#define pb push_back
#define vec_ vector
#define scll1(a) scanf("%lld",&a)
#define sz(a) a.size()
#define matra 1000000
using namespace std;
typedef long long ll;
int main ()
{
    ll i,j;
    bool flag[matra+10];
    vec_<ll>v;
    v.pb(2);
    for(i=3;i<=matra;i+=2)
    if(!flag[i])
    {
        v.pb(i);
        for(j=i;j<=matra;j+=i)
        flag[j]=1;
    }
    while(scll1(j))
    {
        if(j<0)break;
        for(i=0;i<sz(v);i++)
        {
            if(j%v[i]==0)
            {
                while(j%v[i]==0)j/=v[i],cout<<"    "<<v[i]<<endl;
            }
        }
        if(j>1)
        cout<<"    "<<j<<endl;
        cout<<endl;
    }
    return 0;
}

