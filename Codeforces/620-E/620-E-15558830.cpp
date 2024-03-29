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


#define mt 400010
#define mod

vec_<int>adj[mt];
int nn,ns[mt],ne[mt];

int col[mt];
ll segtree[4*mt],lazy[4*mt];
int ulta[mt];

void dfs(int node,int par)
{
    ns[node]=++nn;
    ulta[nn]=node;
    for(auto b: adj[node])
    {
        if(b == par)
            continue;
        dfs(b,node);
    }
    ne[node]=nn;
}

int beg,en;

void lazy_update(int lef, int rig, int cur, int val)
{
    if(lazy[cur])
    {
        segtree[cur]=lazy[cur];
        if(lef != rig)
            lazy[cur << 1]=lazy[(cur << 1) | 1] =lazy[cur];
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        segtree[cur] =(1ll<<val);
        if(rig != lef)
            lazy[(cur << 1) | 1] =lazy[cur << 1] = (1ll<<val);
        return;
    }

    int mid=(lef+rig)>>1,b=(cur<<1);
    lazy_update(lef, mid, b, val);
    lazy_update(mid + 1, rig, b | 1, val);
    segtree[cur] = segtree[b] | segtree[b + 1];
}

ll query(int lef, int rig, int cur)
{
    if(lazy[cur] > 0)
    {
        segtree[cur]=lazy[cur];
        if(lef != rig)
            lazy[cur << 1]=lazy[(cur << 1) | 1] =lazy[cur];
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return 0ll;

    if(lef >= beg && rig <= en)
        return segtree[cur];

    int mid=(lef + rig)>>1,b=(cur<<1);
    return query(lef, mid, b)|query(mid + 1,rig, b + 1);
}

void build(int lef,int rig,int cur)
{
    if(lef==rig)
    {
        segtree[cur]=1ll << col[ulta[lef]];
        return;
    }
    int mid=(lef+rig)>>1,b=(cur<<1);
    build(lef, mid, b);
    build(mid + 1, rig, b | 1);
    segtree[cur] = segtree[b] | segtree[b + 1];
}

int main ()
{
    cffi;
    int i,j,n,q,a,b,qt;
    cin>>n>>q;
    rep1(i,n)
    cin>>col[i];
    rep(i,n-1)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,-1);
    build(1,n,1);

    while(q--)
    {
        cin>>qt;
        if(qt == 2)
        {
            cin>>a;
            beg=ns[a];
            en=ne[a];
            deb(__builtin_popcountll(query(1,n,1)));
            continue;
        }
        cin>>a>>b;
        beg=ns[a];
        en=ne[a];
        lazy_update(1,n,1,b);
    }
    return 0;
}