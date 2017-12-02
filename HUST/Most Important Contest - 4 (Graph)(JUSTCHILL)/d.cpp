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

#define mt 55

double pre_dist[55][55],points[mt][2];
int n;
double dur(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-y1)*(x1-y1) + (x2-y2)*(x2-y2));
}

void init()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(i==j)
                pre_dist[i][j]=0;
            else
                pre_dist[i][j]=inf;
}

void fw()
{
    int i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                pre_dist[i][j]=min(pre_dist[i][j],pre_dist[i][k]+pre_dist[k][j]);
}

int main ()
{
    int m,i,a,b,u,v,j;
    double w,ans,sum,w1;

    while(sci2(n,m)==2 && n && m)
    {
        for(i=1; i<=n; i++)
            scd2(points[i][0],points[i][1]);

        //deb2(n,m);

        init();

        ans=0;

        while(m--)
        {
            sci2(a,b);
            pre_dist[a][b]=pre_dist[b][a]=dur(points[a][0],points[b][0],points[a][1],points[b][1]);
        }

        fw();

        for(a=1; a<=n; a++)
            for(b=a+1; b<=n; b++)
            {
                w=dur(points[a][0],points[b][0],points[a][1],points[b][1]);
                    sum=0;

                for(i=1; i<=n; i++)
                {
                    for(j=i+1; j<=n; j++)
                    {
                        sum+=pre_dist[i][j]-min(pre_dist[i][j],min(w+pre_dist[i][a]+pre_dist[b][j],w+pre_dist[i][b]+pre_dist[a][j]));
                    }
                }

                if(sum>1.00 && (sum>ans || (sum==ans && w1>w)))
                {
                    ans=sum;
                    w1=w;
                    u=a;
                    v=b;
                }
            }

        if(ans==0)
            pf("No road required\n");
        else
            pf("%d %d\n",u,v);
    }
    return 0;
}


