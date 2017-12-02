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

#define mt 30

int dist1[mt][mt],dist2[mt][mt];

void init()
{
    int i,j;

    for(i=1; i<=26; i++)
        for(j=1; j<=26; j++)
            if(i==j)
                dist1[i][j]=dist2[i][j]=0;
            else
                dist1[i][j]=dist2[i][j]=inf;
}

void fw(int n)
{
    int i,j,k;

    for(k=1; k<n; k++)
        for(i=1; i<n; i++)
            for(j=1; j<n; j++)
            {
                dist1[i][j]=min(dist1[i][j],dist1[i][k]+dist1[k][j]);
                dist2[i][j]=min(dist2[i][j],dist2[i][k]+dist2[k][j]);
            }
}

int main ()
{
    int n,m,dist,i,ans1;
    char x,y,d,b;
    vec_<char>ans2;
    map<char,int>ma;
    map<int,char>ma2;

    while(cin>>m && m)
    {
        n=1;
        clr(ma);
        clr(ma2);
        clr(ans2);
        init();
        ans1=inf;

        while(m--)
        {
            cin>>b>>d>>x>>y>>dist;

            //cout<<b<<" "<<d<<" "<<x<<" "<<y<<" "<<dist<<endl;

            if(ma.find(x)==ma.end())ma[x]=n,ma2[n]=x,n++;
            if(ma.find(y)==ma.end())ma[y]=n,ma2[n]=y,n++;

            if(b=='Y')
            {
                if(d=='U')
                    dist1[ma[y]][ma[x]]=min(dist1[ma[y]][ma[x]],dist);
                else
                {
                    dist1[ma[y]][ma[x]]=min(dist1[ma[y]][ma[x]],dist);
                    dist1[ma[x]][ma[y]]=min(dist1[ma[x]][ma[y]],dist);
                }

            }
            else
            {
                if(d=='U')
                    dist2[ma[y]][ma[x]]=min(dist2[ma[y]][ma[x]],dist);
                else
                {
                    dist2[ma[y]][ma[x]]=min(dist2[ma[y]][ma[x]],dist);
                    dist2[ma[x]][ma[y]]=min(dist2[ma[x]][ma[y]],dist);
                }
            }
        }

        cin>>x>>y;

        if(ma.find(x)==ma.end())ma[x]=n,ma2[n]=x,n++;
        if(ma.find(y)==ma.end())ma[y]=n,ma2[n]=y,n++;


        fw(n);

        for(i=1;i<n;i++)
        {
            dist=dist1[i][ma[x]]+dist2[i][ma[y]];
            ans1=min(ans1,dist);
        }

        for(i=1;i<n;i++)
            if(ans1 == dist1[i][ma[x]]+dist2[i][ma[y]])
                ans2.pb(ma2[i]);

        if(ans1 >= inf)
        cout<<"You will never meet.\n";
        else
        {
            cout<<ans1;

            sort(all(ans2));

            for(i=0;i<sz(ans2);i++)
                cout<<" "<<ans2[i];

            cout<<endl;
        }

    }
    return 0;
}
