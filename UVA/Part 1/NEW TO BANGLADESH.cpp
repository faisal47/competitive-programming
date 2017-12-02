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
//#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz 500
using namespace std;
ll inf =1e9;
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
ll tim[sz][sz],t[sz][sz];
ll n,m,q,test,i,j,k,a,b,c,d;
void fw()
{
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                if(tim[i][j]>tim[i][k]+tim[k][j])
                {
                    tim[i][j]=tim[i][k]+tim[k][j];
                    t[i][j]=t[i][k]+t[k][j];
                }
                else if(tim[i][j]==tim[i][k]+tim[k][j])
                {
                    t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
                }
            }
}
int main ()
{
//   cout<<inf<<endl;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                if(i!=j)
                    tim[i][j]=inf;
                else
                    tim[i][j]=0;
            }
        while(m--)
        {
            cin>>a>>b>>c>>d;
            if(c<tim[a][b])
            {
               // tim[a][b]=c;
                tim[b][a]=tim[a][b]=c;
                //t[a][b]=d;
                t[b][a]=t[a][b]=d;
            }
            else if(c == tim[a][b])
            {
                //cout<<t[a][b]<<" "<<d<<endl;
                t[a][b]=min(t[a][b],d);
                t[b][a]=t[a][b];
               // cout<<"changed"<<t[a][b]<<" "<<d<<endl;
            }
        }
       // cout<<t[1][2]<<endl;
        fw();
        cin>>q;
        while(q--)
        {
            cin>>a>>b;
            if(tim[a][b]==inf)
                cout<<"No Path.\n";
            else
                printf("Distance and time to reach destination is %lld & %lld.\n",t[a][b],tim[a][b]);
        }
        if(test)
            cout<<endl;
    }
    return 0;
}
