#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define make_flush  cout << flush; //    fflush(stdout);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)

using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

#define mt 10010
#define MAX 10010
#define mod


struct maan
{
    int a,b,c;
};

int level[MAX], pwr[MAX][15];
int minis[MAX][15];
vector <maan> adj[MAX];
queue <int> Q;

int par[mt];
int par2[mt];
int indx[mt];
bool hoiche[mt];

void bfs(void)
{
    int u,v,cst;
    level[1]=1;
    Q.push(1);
    par[1]=-1;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        int elements = adj[u].size();
        for(int i = 0; i < elements; i++)
        {
            v = adj[u][i].a;
            cst = adj[u][i].b;
            if(level[v]) continue;
            level[v] = level[u] + 1;
            par[v]=u;
            indx[v]=adj[u][i].c;
            pwr[v][0] = u;
            minis[v][0]=cst;
            Q.push(v);
        }
    }
}
void process(int n)
{
    bfs();
    int h, i, lev;
    h = log2(n) + 1;
    for(lev = 1; lev <= h; lev++)
        for(i = 1; i <= n; i++)
            if(pwr[i][lev - 1] != -1)
            {
                pwr[i][lev] = pwr[pwr[i][lev - 1]][lev - 1];
                minis[i][lev]=max(minis[i][lev - 1],minis[pwr[i][lev - 1]][lev - 1]);
            }
}

int query(int high, int low)
{
    if(level[low] < level[high]) swap(low, high);
    int h, i, diff;
    h = log2(level[low]) + 1;
    diff = level[low] - level[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
            low = pwr[low][i];
    if(low == high) return low;
    for(i = h; i >= 0; i--)
    {
        if(pwr[low][i] != -1 && pwr[low][i] != pwr[high][i])
        {
            low = pwr[low][i];
            high = pwr[high][i];
        }
    }
    return pwr[low][0];
}


int query2(int high, int low)
{
    if(low == high)
        return 0;
    if(level[low] < level[high]) swap(low, high);
    int h, i, diff;
    h = log2(level[low]) + 1;
    diff = level[low] - level[high];
    int ret=0;
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
        {
            ret=max(ret,minis[low][i]);
            low = pwr[low][i];
        }
    if(low == high) return ret;
    for(i = h; i >= 0; i--)
    {
        if(pwr[low][i] != -1 && pwr[low][i] != pwr[high][i])
        {
            ret=max(ret,minis[low][i]);
            low = pwr[low][i];
            ret=max(ret,minis[high][i]);
            high = pwr[high][i];
        }
    }
    ret=max(ret,minis[high][0]);
    ret=max(ret,minis[low][0]);

    return ret;
}

vec_<maan>trees,nontrees;

void pre_clear(int n)
{
    ms(level, 0);
    ms(pwr,-1);
    while(!Q.empty())Q.pop();
    clr(trees);
    clr(nontrees);
    int i;
    rep1(i,n)
    {
        clr(adj[i]);
        par2[i]=i;
        hoiche[i]=0;
    }
}

bool cmp(maan a,maan b)
{
    return a.c < b.c;
}

ll ans,AI,BI,ii;

int find_par(int node)
{
    if(par2[node] == node)
        return par2[node];
    return par2[node]=find_par(par2[node]);
}

void dfs(int mapa,int node,int cst)
{
    int bp=find_par(node);
    if(mapa == bp)
        return;
    int np;
    if(bp == par2[node])
        np=par[node];
    else
        np=bp;
    if(!hoiche[node])
    {
        hoiche[node]=1;
        ii=indx[node];
        AI=cst-minis[node][0];
        ans+=(ii*AI + ii*ii*BI);
    }
    par2[node]=mapa;
    dfs(mapa,np,cst);
}

void go(int n)
{
    BI=-1;
    int i,mapa;
    repa(nums,nontrees)
    {
        mapa=query(nums.a,nums.b);
        mapa=find_par(mapa);
        dfs(mapa,nums.a,nums.c);
        dfs(mapa,nums.b,nums.c);
    }
    AI=-1;
    for(i=2; i<=n; i++)
        if(!hoiche[i])
        {
            ii=indx[i];
            ans+=(ii*AI + ii*ii*BI);
        }
}

int main ()
{
    int i,j,test,n,t=1,m,a,b,c;
    maan temp;
    sci1(test);
    while(test--)
    {
        ans=0;
        sci2(n,m);
        pre_clear(n);
        rep1(i,m)
        {
            sci3(a,b,c);
            if(i<n)
            {
                adj[a].pb({b,c,i});
                adj[b].pb({a,c,i});
                trees.pb({a,b,c});
            }
            else
                nontrees.pb({a,b,c});
        }
        process(n);
        AI=-1;
        rep(i,sz(nontrees))
        {
            temp=nontrees[i];
            BI=temp.c-query2(temp.a,temp.b);
            ii=i+n;
            ans+=(ii*AI + ii*ii*BI);
        }
        sort(all(nontrees),cmp);
        go(n);
        printf("Case %d: %lld\n",t++,ans);
    }
    return 0;
}










