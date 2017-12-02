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


#define mt 110
#define mod

int arr[mt],n,m,mot;

typedef long long LL;
struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
    LL rcap()
    {
        return cap - flow;
    }
};
struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<vector<Edge *> > Lf;
    vector<int> layer;
    vector<int> Q;
    Dinic(int N) : N(N), G(N), Q(N) {}
    void AddEdge(int from, int to, int cap)
    {
        if (from == to) return;
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }
    LL BlockingFlow(int s, int t)
    {
        layer.clear();
        layer.resize(N, -1);
        layer[s] = 0;
        Lf.clear();
        Lf.resize(N);
        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (e.rcap() <= 0) continue;
                if (layer[e.to] == -1)
                {
                    layer[e.to] = layer[e.from] + 1;
                    Q[tail++] = e.to;
                }
                if (layer[e.to] > layer[e.from])
                {
                    Lf[e.from].push_back(&e);
                }
            }
        }
        if (layer[t] == -1) return 0;
        LL totflow = 0;
        vector<Edge *> P;
        while (!Lf[s].empty())
        {
            int curr = P.empty() ? s : P.back()->to;
            if (curr == t)   // Augment
            {
                LL amt = P.front()->rcap();
                for (int i = 0; i < P.size(); ++i)
                {
                    amt = min(amt, P[i]->rcap());
                }
                totflow += amt;
                for (int i = P.size() - 1; i >= 0; --i)
                {
                    P[i]->flow += amt;
                    G[P[i]->to][P[i]->index].flow -= amt;
                    if (P[i]->rcap() <= 0)
                    {
                        Lf[P[i]->from].pop_back();
                        P.resize(i);
                    }
                }
            }
            else if (Lf[curr].empty())     // Retreat
            {
                P.pop_back();
                for (int i = 0; i < N; ++i)
                    for (int j = 0; j < Lf[i].size(); ++j)
                        if (Lf[i][j]->to == curr)
                            Lf[i].erase(Lf[i].begin() + j);
            }
            else     // Advance
            {
                P.push_back(Lf[curr].back());
            }
        }
        return totflow;
    }
    LL GetMaxFlow(int s, int t)
    {
        LL totflow = 0;
        while (LL flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

bool ok(int caps)
{
    Dinic *mf=new Dinic(n+m+5);
    int i,j;
//    deb(n);
//    deb("hola");
//    rep1(i,n)
//    deb(arr[i]);
    rep1(i,n)
    mf->AddEdge(0,i,arr[i]);
    rep1(i,m)
    mf->AddEdge(n+i,n+m+1,caps);
    rep1(i,n)
    rep1(j,m)
    mf->AddEdge(i,n+j,inf);
//    deb(mf->GetMaxFlow(0,n+m+1));
    return (int)mf->GetMaxFlow(0,n+m+1)==mot;
}

int bs()
{
    int ret=inf,l=0,h=110,mid;
    while(l<=h)
    {
        mid=(l+h)>>1;
        if(ok(mid))
        {
            ret=min(ret,mid);
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ret;
}

int main ()
{
    cffi;
    int i,j,test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        mot=0;
        rep1(i,n)
        {
            cin>>arr[i];
            mot+=arr[i];
        }
        cout<<"Case "<<t++<<": "<<bs()<<endl;
    }
//    fflush(stdout);
//    cout << flush;
    return 0;
}










