//E

#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define clr(a) a.clear()
#define pb push_back
#define pob pop_back
#define vec_ vector
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define mp make_pair
#define sz(a) a.size()
#define mt
using namespace std;
typedef long long ll;
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

#define SZ 810

ll par[SZ],arr[SZ],par1[SZ];
map<ll,ll>M,ansm;
bool col[SZ];
vec_<ll>adj[SZ];
bool dfs(ll u)
{
    ll i,k,v;
    k=sz(adj[u]);
    for(i=0; i<k; i++)
    {
        v=adj[u][i];
        if(col[v]==0)
        {
            col[v]=1;
            if(par[v]==-1 || dfs(par[v]))
            {
                par[v]=u;
              //  par[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
ll bpm(int f)
{
    ll i,j,k=0;
    ms(par,-1);
    for(i=1; i<=f; i++)
    {
        ms(col,0);
        if(dfs(i))
        k++;
    }
    return k;
}
int main ()
{
    ll t,f,b,i,j,k,ans;
    cin>>t;
    while(t--)
    {
        clr(M);
        ans=0;
        clr(ansm);
        cin>>f>>b;
        for(i=1; i<=f; i++)
        {
            cin>>arr[i];
            clr(adj[i]);
        }

        for(i=1; i<=b; i++)
        {
            cin>>j;
            M[j]=1;
        }
        for(i=1; i<=f; i++)
        {
            for(j=i+1; j<=f; j++)
            {
                if(i==j)
                    continue;
                if(M.find(arr[i]+arr[j])!=M.end())
                {
                        adj[i].pb(j);
                        //adj[j].pb(i);
                }
            }
        }
        for(i=1; i<=f; i++)
        {
            cout<<i<<"====  ";
            for(j=0; j<sz(adj[i]); j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }
       cout<<bpm(f)<<endl;
//        cout<<"\n\n\n\n";
//        for(i=1;i<=f;i++)
//        if(ansm.find(par[i])==ansm.end() && par[i]!=-1)
//        {
//            cout<<i<<" "<<par[i]<<endl;
//            ansm[par[i]]=1;
//          //  ansm[i]=1;
//            ans++;
//        }
//        cout<<ans<<endl;
    }



    return 0;
}

