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
#define inf 123456789123456789
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
ll dist[505][505];
int main ()
{
    ll i,j,k,test,t,a,n,m;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i==j)
        dist[i][j]=0;
        else
        {
            dist[i][j]=inf;
//            cout<<dist[i][j]<<endl;
        }
        while(m--)
        {
            cin>>i>>j>>k;
            if(dist[i][j]!=inf && k>=dist[i][j])
            continue;
            dist[i][j]=k;
            dist[j][i]=k;
        }
        cin>>a;
        for(k=0;k<n;k++)
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j]));
        printf("Case %lld:\n",t);
        for(i=0;i<n;i++)
        if(dist[i][a]==inf)
        cout<<"Impossible\n";
        else
        cout<<dist[i][a]<<endl;
    }
    return 0;
}
