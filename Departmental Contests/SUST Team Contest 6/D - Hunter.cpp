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
#define inf 1<<20
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
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
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt 1010
using namespace std;

int par[mt],n;
bool col[mt];
vec_<int>edge[mt];
bool dfs(int u)
{
    if(col[u])return false;
    col[u]=true;
    for(int i=0;i<sz(edge[u]);i++)
    {
        int v=edge[u][i];
        if(par[v]==-1 || dfs(par[v]) )
        {
            par[v]=u;
            return true;
        }
    }
    return false;
}

int bpm()
{
    int ret=0;
    ms(par,-1);
    for(int i=0;i<n;i++)
    {
        ms(col,0);
        if(dfs(i))ret++;
    }
    return ret;
}
vec_<pii>res;
int main ()
{
    int a,b,p,q,i;
    while(cin>>a>>b)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>p>>q;
            res.pb(mp(p,q));
        }
        clr(res);
        for(i=0;i<n;i++)
        clr(edge[i]);
        for(int i=0; i<n; i++)
        {
            if(res[i].sc)continue;
            for(int j=i+1; j<n; j++)
            {
                if(i!=j)
                {
                   // cout<<j<<endl;
                    if(res[j].sc)
                    {
                       // cout<<j<<endl;
                        if(res[j].first-res[i].first>=a || res[j].first-res[i].first<=b)
                        {
                            //cout<<j<<' '<<i<<endl;
                            edge[i].pb(j);
                        //edge[j].pb(i);
                        }
                    }
                }
            }
        }
        int ans=bpm();
       // cout<<ans<<endl;
        if((ans<<1)==n)
        {
            cout<<"No reason\n";
            for(i=0;i<n;i++)
            if(par[i]!=-1)
            {
                cout<<min(res[i].fs,res[par[i]].fs)<<" "<<max(res[i].fs,res[par[i]].fs)<<endl;
            }
        }
        else
        {
            cout<<"Liar\n";
        }
    }
        return 0;
}


