#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 110

//int food[mt];
int dist[mt][mt],food[mt][mt],n;

void fw()
{
    int i,j,k;

    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(dist[i][j]+food[i][j]>max(food[i][k],food[k][j])+dist[i][k]+dist[k][j])
        {
            dist[i][j]=dist[i][k]+dist[k][j];
            food[i][j]=max(food[i][k],food[k][j]);
        }
        if(dist[i][j] == dist[i][k]+dist[k][j])
        {
            food[i][j]=min(food[i][j],max(food[i][k],food[k][j]));
        }
    }

///  kono ek oggato karone 2 bar fw() chalaile ans mile... ki shei karon eida bair korte parle tare cha khawano hobe

    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(dist[i][j]+food[i][j]>max(food[i][k],food[k][j])+dist[i][k]+dist[k][j])
        {
            dist[i][j]=dist[i][k]+dist[k][j];
            food[i][j]=max(food[i][k],food[k][j]);
        }
        if(dist[i][j] == dist[i][k]+dist[k][j])
        {
            food[i][j]=min(food[i][j],max(food[i][k],food[k][j]));
        }
    }

}

int main ()
{
    int m,q,a,b,c,i,j,t=0;
    while(cin>>n>>m>>q && n && m && q)
    {
        if(t)
            cout<<endl;
        for(i=1; i<=n; i++)
            cin>>food[i][i];

        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                if(i==j)
                    dist[i][j]=0;
                else
                    dist[i][j]=inf;

                if(i==j)
                    continue;

                food[i][j]=max(food[i][i],food[j][j]);

            }

        while(m--)
        {
            cin>>a>>b>>c;
            dist[a][b]=c;
            dist[b][a]=c;
        }

        fw();

        pf("Case #%d\n",++t);

        while(q--)
        {
            cin>>a>>b;
            if(dist[a][b]==inf)
                cout<<-1<<endl;
            else
                cout<<dist[a][b]+food[a][b]<<endl;
        }

    }
    return 0;
}



