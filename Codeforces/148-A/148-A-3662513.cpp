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
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz
using namespace std;
//struct data //for dj()
//{
// int node,cost;
// bool operator < (const data& p) const
// {
// return cost > p.cost;
// }
//};
//ll bigmod(ll a,ll b,ll m)
//{
// if(b == 0) return 1%m;
// ll x = bigmod(a,b/2,m);
// x = (x * x) % m;
// if(b % 2 == 1) x = (x * a) % m;
// return x;
//}
//ll gcd(ll a,ll b)
//{
// if(b==0)
// return a;
// return gcd(b,a%b);
//}
int main ()
{
ll i,j,n,m,l,k,d,c;
bool flag[100010];
while(cin>>n>>m>>l>>k>>d)
{
    for(i=1;i<=d;i++)
    flag[i]=0;
    for(i=n;i<=d;i+=n)
    flag[i]=1;
    for(i=m;i<=d;i+=m)
    flag[i]=1;
    for(i=l;i<=d;i+=l)
    flag[i]=1;
    for(i=k;i<=d;i+=k)
    flag[i]=1;
    c=0;
    for(i=1;i<=d;i++)
    if(flag[i])
    c++;
    cout<<c<<endl;
}
return 0;
}