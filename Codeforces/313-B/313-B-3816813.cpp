#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <queue>
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
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz
using namespace std;
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//ll gcd(ll a,ll b)
//{
//   if(b==0)
//   return a;
//   return gcd(b,a%b);
//}
ll ase[100010];
int main ()
{
    string s;
    ll q,i,c,a,b;
    while(cin>>s)
    {
        for(i=1; i<s.size(); i++)
        {
            ase[i]=ase[i-1];
            if(s[i]==s[i-1])
                ase[i]++;
        }
        cin>>q;
        while(q--)
        {
            cin>>a>>b;
            a--,b--;
            if(b-a==1)
            {
                if(s[b]==s[a])
                cout<<1<<endl;
                else
                cout<<0<<endl;
            }
            else
            cout<<ase[b]-ase[a]<<endl;
        }
    }
    return 0;
}