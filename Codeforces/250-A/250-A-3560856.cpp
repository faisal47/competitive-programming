#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz
using namespace std;
int main ()
{
    ll i,j,n,c,a;
    vec_ <ll>v;
    while(cin>>n)
    {
        clr(v);
        a=1;c=0;
        for(i=1;i<=n;i++)
        {
            cin>>j;
            if(j<0)
            c++;
            if(c>2 || i==n)
            {
                if(i==n && c!=3)
                v.pb(i-a+1);
                else if(i==n && c==3)
                {
                   // cout<<"kjd";
                    v.pb(i-a);
                    v.pb(1);
                }
                else
                v.pb(i-a);
                a=i;
                c=1;
            }
        }
        cout<<v.size()<<endl<<v[0];
        for(i=1;i<v.size();i++)
        cout<<" "<<v[i];
        cout<<endl;
    }
    return 0;
}