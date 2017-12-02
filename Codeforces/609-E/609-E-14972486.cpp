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
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};


#define mt 200010
#define mod

vec_<pil>adj[mt];
int par[mt];
struct maan
{
    int a,b,ind;
    ll c;
};
vec_<maan>v;
bool flag[mt];
bool cmp(maan a,maan b)
{
    return a.c < b.c;
}
ll mstcost;
int find_par(int node)
{
    if(par[node] == node)
        return node;
    return par[node]=find_par(par[node]);
}
void build_mst(int n)
{
    int i;
    rep1(i,n)par[i]=i;
    int p1,p2;
    rep(i,sz(v))
    {
        p1=find_par(v[i].a);
        p2=find_par(v[i].b);
        if(p1 == p2)
            continue;
//        deb("yos ",v[i].ind);
        flag[v[i].ind]=1;
        par[p1]=p2;
        mstcost+=v[i].c;
        adj[v[i].a].pb({v[i].b,v[i].c});
        adj[v[i].b].pb({v[i].a,v[i].c});
    }
}
#define MAX 200010
int level[MAX], pwr[MAX][19];
ll dist[MAX][19];
queue <int> Q;
void bfs(void)
{
    Q.push(1);
    level[1]=1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int elements = adj[u].size();
        for(int i = 0; i < elements; i++)
        {
            int v = adj[u][i].fs;
            if(level[v]) continue;
            level[v] = level[u] + 1;
            pwr[v][0] = u;
            dist[v][0]=adj[u][i].sc;
            Q.push(v);
        }
    }
}
void process(int n)
{
    int h, i, lev;
    h = log2(n) + 1;
    for(lev = 1; lev <= h; lev++)
    {
        for(i = 1; i <= n; i++)
        {
            if(pwr[i][lev - 1] != -1)
                {
                    dist[i][lev]=max(dist[i][lev - 1],dist[pwr[i][lev - 1]][lev - 1]);
                    pwr[i][lev] = pwr[pwr[i][lev - 1]][lev - 1];
                }
        }
    }
}
ll query(int high, int low)
{
    if(level[low] < level[high]) swap(low, high);
    int h, i, diff;
    ll ret=0;
    h = log2(level[low]) + 1;
    diff = level[low] - level[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
            {
                ret=max(ret,dist[low][i]);
                low = pwr[low][i];
            }
    if(low == high) return ret;
    for(i = h; i >= 0; i--)
    {
        if(pwr[low][i] != -1 && pwr[low][i] != pwr[high][i])
        {
            ret=max(ret,dist[low][i]);
            ret=max(ret,dist[high][i]);
            low = pwr[low][i];
            high = pwr[high][i];
        }
    }
    ret=max(ret,dist[low][0]);
    ret=max(ret,dist[high][0]);
    return ret;
}

void build_lca(int n)
{
    ms(pwr,-1);
    bfs();
    process(n);
}

bool cmp2(maan a,maan b)
{
    return a.ind < b.ind;
}

int main ()
{
    cffi;
    int i,j,test,n,m;
    cin>>n>>m;
    v.resize(m);
    rep(i,m)
    {
        cin>>v[i].a>>v[i].b>>v[i].c;
        v[i].ind=i;
    }
    sort(all(v),cmp);
    build_mst(n);
    build_lca(n);
    sort(all(v),cmp2);
    rep(i,m)
    {
        if(flag[i])
        {
            deb(mstcost);
            continue;
        }
        deb(mstcost+v[i].c-query(v[i].a,v[i].b));
    }
    return 0;
}